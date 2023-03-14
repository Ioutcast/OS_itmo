#include "character_device.h"
#include "lab_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(int argc, char **argv)
{   
    if (argc != 3) {
                printf("Wrong amount of arguments! Must be 2!");
                return -1;
        }
    struct lab_response *lab_res = malloc(sizeof(struct lab_response));
    lab_res->pid = atoi(argv[1]);
    lab_res->path = argv[2];
    char *next;
    long val = strtol (argv[1], &next, 10);
         if ((next == argv[1])) {
            printf ("'%s' is not valid\n", argv[i]);
            exit(-1);
    }
    if (lab_res->pid<=0){
        printf("Ошибка ввода ааргументов.\n");
        exit(-1);
    }
    int fd = open(DEVICE_NAME, 0);

    if (fd < 0)
    {
        printf("Can't open device file: %s\n", DEVICE_NAME);
        exit(-1);
    }

   
    int ret_val = ioctl(fd, IOCTL_GET_INFO, lab_res);
    close(fd);
    if (lab_res->thread_sp != 0){
        printf("sp is %lu\n", lab_res->thread_sp);
    } 
    else{
        printf("Данные о thread_struct достать не получилось.\n");
    }
    if (lab_res->dentry_flags == 0){
        printf("Данные о вводимом объекте dentry достать не получилось.\n");
    } 
    else{
    printf("dentry time is %lu\n", lab_res->dentry_time);
    printf("dentry flags is %x\n", lab_res->dentry_flags);
    printf("dentry name is %s\n", lab_res->d_iname);
    }
    return 0;
}
