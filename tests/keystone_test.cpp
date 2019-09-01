//
// Created by Alex Thomas on 8/31/19.
//

#include <getopt.h>
#include <iostream>
#include <cstdio>
#include "gtest/gtest.h"
#include "keystone.h"

size_t untrusted_size = 2*1024*1024;
size_t freemem_size = 48*1024*1024;
uintptr_t utm_ptr = (uintptr_t)DEFAULT_UNTRUSTED_PTR;

TEST(Keystone_Init, ValidInit) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init("test_runner", "test_runner", params), KEYSTONE_SUCCESS);
}

TEST(Keystone_Init, NullRT) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  ASSERT_ANY_THROW(enclave.init("test_runner", 0, params));
}

TEST(Keystone_Init, NullEAPP) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  ASSERT_ANY_THROW(enclave.init(0, "eyrie-rt", params));
}

TEST(Keystone_Run, RunTest) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init("test_runner", "test_runner", params), KEYSTONE_SUCCESS);
  EXPECT_EQ(enclave.run(), KEYSTONE_SUCCESS);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}