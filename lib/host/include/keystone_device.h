#include <sys/ioctl.h>


class KeystoneDevice
{
private:
    int fd;
public:
    KeystoneDevice() {};
    ~KeystoneDevice() {};
    bool initDevice(Params params);
    int ioctl_ioc_create_enclave(int fd, struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_utm_init(int fd, struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_finalize_enclave(int fd, struct keystone_ioctl_create_enclave *enclp);
    int ioctl_destroy_enclave(int fd, struct keystone_ioctl_create_enclave *enclp);
    int ioctl_run_enclave(int fd, struct keystone_ioctl_run_enclave *enclp);
    int ioctl_resume_enclave(int fd, struct keystone_ioctl_run_enclave *enclp);
};
