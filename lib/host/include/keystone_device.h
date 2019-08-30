#include <stddef.h>
#include <cerrno>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <stdarg.h>
#include <assert.h>
#include "common.h"
#include "keystone_user.h"
#include "params.h"



class KeystoneDevice
{
private:
    int fd;
public:
    KeystoneDevice() {};
    ~KeystoneDevice() {};
    bool initDevice(Params params);
    int ioctl_ioc_create_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_utm_init(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_finalize_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_destroy_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_run_enclave(struct keystone_ioctl_run_enclave *enclp);
    int ioctl_resume_enclave(struct keystone_ioctl_run_enclave *enclp);
    int getFD();
};
