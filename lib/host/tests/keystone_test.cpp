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

TEST(KeystoneSDK, PositiveNos) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init(0, 0), KEYSTONE_ERROR);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}