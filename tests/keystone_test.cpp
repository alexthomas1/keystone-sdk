//
// Created by Alex Thomas on 8/31/19.
//

//#include "gmock/gmock.h"
#include <getopt.h>
#include <iostream>
#include <cstdio>
#include "gtest/gtest.h"
#include "keystone.h"

//using ::testing::AtLeast;                         // #1

size_t untrusted_size = 2*1024*1024;
size_t freemem_size = 48*1024*1024;
uintptr_t utm_ptr = (uintptr_t)DEFAULT_UNTRUSTED_PTR;

TEST(Keystone_Init, InvalidELF) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

//  ASSERT_ANY_THROW(enclave.init("stack.eapp_riscv", 0, params));
  EXPECT_EQ(enclave.init("test_runner", "test_runner", params), KEYSTONE_ERROR);
}

TEST(Keystone_Run, RunTest) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  enclave.init("test_runner", "eyrie-rt", params)
  EXPECT_EQ(enclave.run(), KEYSTONE_SUCCESS);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}