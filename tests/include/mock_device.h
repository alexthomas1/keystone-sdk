#include "keystone_device.h"

class MockKeystoneDevice: public KeystoneDeviceInterface{
private:
    int fd;
public:
    MockKeystoneDevice() {};
    ~MockKeystoneDevice() {};
    bool initDevice(Params params);
    int ioctl_ioc_create_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_utm_init(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_ioc_finalize_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_destroy_enclave(struct keystone_ioctl_create_enclave *enclp);
    int ioctl_run_enclave(struct keystone_ioctl_run_enclave *enclp);
    int ioctl_resume_enclave(struct keystone_ioctl_run_enclave *enclp);
    int getFD();
};