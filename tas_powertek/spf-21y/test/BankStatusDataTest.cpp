#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/BankStatusData.h"

namespace tas_powertek::spf21y {

TEST(BankStatusDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval256Data(
      "\x11\x10\x21\x10\x00\x00\x00\x00", 8);
  BankStatusData bankStatus = BankStatusData::fromByteStream(kInterval256Data);
  EXPECT_EQ(1, bankStatus[1]);
  EXPECT_EQ(1, bankStatus[2]);
  EXPECT_EQ(1, bankStatus[3]);
  EXPECT_EQ(0, bankStatus[4]);
  EXPECT_EQ(2, bankStatus[5]);
  EXPECT_EQ(1, bankStatus[6]);
  EXPECT_EQ(1, bankStatus[7]);
  EXPECT_EQ(0, bankStatus[8]);
  EXPECT_EQ(0, bankStatus[9]);
  EXPECT_EQ(0, bankStatus[10]);
  EXPECT_EQ(0, bankStatus[11]);
  EXPECT_EQ(0, bankStatus[12]);
  EXPECT_EQ(0, bankStatus[13]);
  EXPECT_EQ(0, bankStatus[14]);
  EXPECT_EQ(0, bankStatus[15]);
  EXPECT_EQ(0, bankStatus[16]);
}
}  // namespace tas_powertek::spf21y
