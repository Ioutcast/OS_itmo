#ifndef LAB_STRUCT_H
#define LAB_STRUCT_H

struct lab_response
{	
	int pid;
    char* path;
	unsigned char d_iname[40];
	unsigned long dentry_time;
	unsigned long thread_sp;
	unsigned long dentry_flags;
};

#endif
