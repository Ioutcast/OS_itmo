#include "getting_structures.h"


int get_thread_struct_info(struct lab_response * resp)
{

    	struct task_struct *t = get_pid_task(find_get_pid(resp->pid), PIDTYPE_PID);
    	if (t == NULL)
    	{
    	    printk(KERN_ERR "task_struct with pid=%d does not exist\n", resp->pid);
    	    return 1;
    	}
    	struct thread_struct th = t->thread;

    	resp->thread_sp = th.sp;
    	return 0;
}

int get_dentry(struct lab_response * resp)
{
	int ret = 0;
	struct path original_path;
	ret = kern_path(resp->path, LOOKUP_DIRECTORY, &original_path);
	if (ret){
		pr_alert("Error while getting dentry");
		return 1;
	} else {
		path_put(&original_path);
		resp->dentry_time = original_path.dentry->d_time;
		resp->dentry_flags = original_path.dentry->d_flags;
		strcpy(resp->d_iname, original_path.dentry->d_iname);
		return 0;
	}
}
