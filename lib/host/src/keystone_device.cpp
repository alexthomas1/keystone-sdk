//
// Created by Alex Thomas on 8/17/19.
//

#include "keystone_device.h"
#include <keystone_user.h>


int KeystoneDevice::ioctl_ioc_create_enclave(int fd, struct keystone_ioctl_create_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_CREATE_ENCLAVE, enclp);
}

int KeystoneDevice::ioctl_ioc_utm_init(int fd, struct keystone_ioctl_create_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_UTM_INIT, &enclp);

}

int KeystoneDevice::ioctl_ioc_finalize_enclave(int fd, struct keystone_ioctl_create_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_FINALIZE_ENCLAVE, &enclp);
}

int KeystoneDevice::ioctl_destroy_enclave(int fd, struct keystone_ioctl_create_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_DESTROY_ENCLAVE, enclp);
}

int KeystoneDevice::ioctl_run_enclave(int fd, struct keystone_ioctl_run_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_RUN_ENCLAVE, enclp);
}

int KeystoneDevice::ioctl_resume_enclave(int fd, struct keystone_ioctl_run_enclave *enclp)
{
  return ioctl(fd, KEYSTONE_IOC_RESUME_ENCLAVE, enclp);
}

