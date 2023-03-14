#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/version.h>
#include <linux/fs.h>
#include <linux/mutex.h> 
#include "character_device.h"
#include "lab_struct.h"
#include "getting_structures.h"


MODULE_LICENSE("GPL");



static long lab_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);


static long lab_dev_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
    printk(KERN_INFO "lab_dev_ioctl(%p,%lu,%lu)", file, ioctl_num, ioctl_param);
    unsigned long ret_val_ku;
    struct lab_response * lab_res;
    int ret_val;
    switch (ioctl_num)
    {

    case IOCTL_GET_INFO:
        
        printk(KERN_INFO "IOCTL_GET_INFO\n");
        
        if (lab_res == NULL)
        {
            lab_res = vmalloc(sizeof(struct lab_response));
        }
        
        ret_val_ku = copy_from_user(lab_res, (struct lab_response *)ioctl_param, sizeof(struct lab_response));
        
        if (ret_val_ku < 0)
        {
            printk(KERN_INFO "ERROR WITH COPYIING ");
        }

        ret_val = get_thread_struct_info(lab_res);
        ret_val = get_dentry(lab_res);

        ret_val_ku = copy_to_user((struct lab_response *)ioctl_param, lab_res, sizeof(struct lab_response));
        if (ret_val_ku < 0)
        {
            printk(KERN_INFO "ERROR WITH COPYIING ");
        }
        
        vfree(lab_res);
        lab_res = NULL;
         
        break;
    }
    return 0;
}

struct file_operations file_ops = {
    .unlocked_ioctl = lab_dev_ioctl
};

int init_module()
{
    int ret_val;
    ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &file_ops);
    if (ret_val < 0)
    {
        printk(KERN_ALERT "%s failed with %d\n", "Sorry, registering the character device \n", ret_val);
        return ret_val;
    }

    return 0;
}

void cleanup_module()
{
    unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
}
