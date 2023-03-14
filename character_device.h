#ifndef CHARACTER_DEV_H
#define CHARACTER_DEV_H
#include <linux/ioctl.h>
#define MAJOR_NUM 100
#define IOCTL_GET_INFO _IOWR(MAJOR_NUM, 1, struct lab_response *)
#define DEVICE_NAME "lab_character_device"
#define BUFFER_SIZE 1024
#endif
