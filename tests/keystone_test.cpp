//
// Created by Alex Thomas on 8/31/19.
//

#include <getopt.h>
#include <iostream>
#include <cstdio>
#include "gtest/gtest.h"
#include "keystone.h"

#define EYRIE_RT "eyrie-rt"
#define TEST_EAPP "stack.eapp_riscv"
#define FAKE_EAPP "fake_file.riscv"
#define FAKE_RT "fake-rt"

char const *ref_hash = "\xF\x7F\xED\xF5\xEB\x82\x8B\xD2\x11\xFBWv\xBE\xB4m\x80\xD2";

size_t untrusted_size = 2*1024*1024;
size_t freemem_size = 48*1024*1024;
uintptr_t utm_ptr = (uintptr_t)DEFAULT_UNTRUSTED_PTR;

TEST(Keystone_Init, ValidMeasure) {
  /* Measures enclave using a simulated enclave
   *
   * */
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init(TEST_EAPP, EYRIE_RT, params), KEYSTONE_SUCCESS);
  ASSERT_STREQ(enclave.getHash(), ref_hash);
  EXPECT_EQ(enclave.destroy(), KEYSTONE_SUCCESS);
}

TEST(Keystone_Init, InvalidRT) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init(TEST_EAPP, FAKE_RT, params), KEYSTONE_ERROR);
}

TEST(Keystone_Init, InvalidEAPP) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init(FAKE_EAPP, EYRIE_RT, params), KEYSTONE_ERROR);
}

TEST(Keystone_Run, RunTest) {
  Keystone enclave;
  Params params;

  params.setFreeMemSize(untrusted_size);
  params.setUntrustedMem(utm_ptr, untrusted_size);
  params.setSimulated(true);

  EXPECT_EQ(enclave.init(TEST_EAPP, EYRIE_RT, params), KEYSTONE_SUCCESS);
  EXPECT_EQ(enclave.run(), KEYSTONE_SUCCESS);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}