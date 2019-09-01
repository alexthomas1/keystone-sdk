//
// Created by Alex Thomas on 8/31/19.
//

//#include "gmock/gmock.h"
#include <getopt.h>
#include <iostream>
#include <cstdio>
#include "gtest/gtest.h"
#include "keystone.h"
#include "edge_wrapper.h"

//using ::testing::AtLeast;                         // #1

TEST(KeystoneSDK, PositiveNos) {
  Keystone enclave;
  Params params;
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}