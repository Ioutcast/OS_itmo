#ifndef LKFS_H
#define LKFS_H

#include "character_device.h"
#include "lab_struct.h"

#include <linux/namei.h>
#include <linux/dcache.h>

// #include <asm/uaccess.h>

#include <linux/uaccess.h>
#include <linux/netdevice.h>
#include <linux/list.h>
#include <asm/siginfo.h>
#include <linux/rcupdate.h> 
#include <linux/sched.h>

int get_thread_struct_info(struct lab_response * resp);
int get_dentry(struct lab_response * resp);
#endif
