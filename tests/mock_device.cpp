#include "keystone_device.h"

int MockKeystoneDevice::ioctl_ioc_create_enclave(struct keystone_ioctl_create_enclave *enclp)
{
  return 0;
}

int MockKeystoneDevice::ioctl_ioc_utm_init(struct keystone_ioctl_create_enclave *enclp)
{
  return 0;

}

int MockKeystoneDevice::ioctl_ioc_finalize_enclave(struct keystone_ioctl_create_enclave *enclp)
{
  return 0;
}

int MockKeystoneDevice::ioctl_destroy_enclave(struct keystone_ioctl_create_enclave *enclp)
{
  return 0;
}

int MockKeystoneDevice::ioctl_run_enclave(struct keystone_ioctl_run_enclave *enclp)
{
  return 0;
}

int MockKeystoneDevice::ioctl_resume_enclave(struct keystone_ioctl_run_enclave *enclp)
{
  return 0;
}

int MockKeystoneDevice::getFD(){
  return 5;
}

bool MockKeystoneDevice::initDevice(Params params)
{
  return true;
}