#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>
#include <string_view>

#include "../data/UserSettingData.h"

namespace tas_powertek::spf21y {

using namespace std::literals;

TEST(UserSettingDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for UserSettingData
  constexpr std::string_view kUserSettingData(
      "\x11\x27\x00\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69"
      "\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00"
      "\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69"
      "\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00\x30\x69\x02\x00"
      "\x4c\x04\x00\x00\x98\x08\x00\x00\x80\x0c\x00\x00\xe8\x03\x00\x00\x38\x18"
      "\x00\x00\x00\x32\x00\x00\x00\x32\x00\x00\xc4\x09\x00\x00\xc4\x09\x00\x00"
      "\xc4\x09\x00\x00\x88\x13\x00\x00\x88\x13\x00\x00\x88\x13\x00\x00\x88\x13"
      "\x00\x00\x88\x13\x00\x00\x10\x27\x00\x00\x36\x10\x9f\x01\xe2\x04\xf4\x01"
      "\xe8\x03\xe8\x03\x32\x00\x32\x00\x64\x00\x64\x00\xc8\x00\xc8\x00\xc8\x00"
      "\xc8\x00\xc8\x00\xc8\x00\xf4\x01\xf4\x01\xf4\x01\xf4\x01\xf4\x01\xe8\x03"
      "\xe8\x03\xe8\x03\x52\x03\x0a\x00\x0a\x00\x0a\x00\x0a\x00\x0a\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xb4\x00"
      "\xb4\x00\xb4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x20\x03\x7e\x04\x64\x00\xe0\x01\x08\x02\x14\x05\x0f\x00\x0f\x00"
      "\x7e\x04\x14\x00\x70\x03\x4b\x00\xf4\x01\x5e\x01\x32\x00\xf4\x01\x8a\x02"
      "\x03\x00\x03\x00\xcf\x03\xcf\x03\xd6\x06\x5a\x0a\xc8\x00\xc8\x00\xc8\x00"
      "\x4b\x00\x00\x00\x52\x03\x4c\x04\x96\x00\xef\x01\x03\x02\xb0\x04\x0a\x00"
      "\x14\x00\x1a\x04\x0f\x00\x98\x03\x41\x00\x90\x01\xfa\x00\x4b\x00\xc2\x01"
      "\x58\x02\x01\x00\x01\x00\xc5\x03\xc5\x03\xd0\x07\xc4\x09\x64\x00\x64\x00"
      "\x64\x00\x41\x00\x01\x00\x00\x00\xe5\x07\x68\x42\xb6\x03\x04\x01\x01\x01"
      "\x01\x01\x00\x00\x00\x01\x01\x03\x00\x00\x01\x01\x10\x01\x01\x01\x01\x01"
      "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x00\x01\x01\x01"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01"
      "\x01\x01\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x01\x01\x01\x00\x0f\x0f\x32\x00\x00\x02\x02\x02\x02\x02\x02\x02\x02"
      "\x01\x01\x01\x02\x02\x01\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02"
      "\x02\x00\x01\x01\x00\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01"
      "\x01\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x00\x00\x01\x00\x01\x01\x00"
      "\x00\x00\x01\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x02\x01\x01"
      "\x01\x01\x00\x00\x01\x00\x00\x00\x0c\x01\x00\x01\x02\x00\x00\x00\x05\x06"
      "\x07\x00\x00\x00\x02\x05\x03\x04\x01\x00\x00\x01\x00\x00\x00\x01\x00\x00"
      "\x00\x01\x00\x00\x00\x4e\x6f\x6e\x65\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x31\x33\x39\x2e\x30\x35\x39\x2e\x30\x36\x33\x2e\x30\x36\x33"
      "\x00\x74\x61\x73\x2e\x73\x75\x62\x6c\x69\x6d\x65\x65\x6e\x74\x65\x72\x70"
      "\x72\x69\x73\x65\x2e\x63\x6f\x6d\x2f\x64\x61\x73\x68\x62\x6f\x61\x72\x64"
      "\x2f\x70\x6f\x73\x74\x5f\x64\x61\x74\x61\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x35\x30\x30\x32\x64\x65\x6d"
      "\x6f\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x01"
      "\x0a\x0a\x0a\x00\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01"
      "\x01\x01\x01\x01\x01\x55\x55\x55\x55\x55\x55\x55\x55\x55\x55\x55\x55\x55"
      "\x55\x55\x55\x55\x73\x73\x73\x73\x73\x73\x73\x73\x73\x73\x73\x73\x73\x73"
      "\x73\x73\x73\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01"
      "\x01\x01\x00\x00\x05\x00\x02\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x01\x01\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\xea\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x30\x32\x2e\x30\x31\x2e"
      "\x30\x30\x31\x32",
      904);
  UserSettingData userSettingData =
      UserSettingData::fromByteStream(kUserSettingData);
  EXPECT_EQ(userSettingData.COM1_Unit_ID, 10001);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[0], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[1], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[2], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[3], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[4], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[5], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[6], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[7], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[8], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[9], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[10], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[11], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[12], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[13], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[14], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[15], 158000);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_Limit[16], 158000);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(1 - 1), 11);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(2 - 1), 22);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(3 - 1), 32);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(4 - 1), 10);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(5 - 1), 62);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(6 - 1), 128);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(7 - 1), 128);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(8 - 1), 25);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(9 - 1), 25);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(10 - 1), 25);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(11 - 1), 50);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(12 - 1), 50);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(13 - 1), 50);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(14 - 1), 50);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(15 - 1), 50);
  EXPECT_EQ(userSettingData.EX_Bank_kVAr(16 - 1), 100);
  EXPECT_EQ(userSettingData.EX_Rated_V(), 415);
  EXPECT_EQ(userSettingData.ES_Rated_VLL, 415);
  EXPECT_EQ(userSettingData.ES_SCT_Primary, 1250);
  EXPECT_EQ(userSettingData.ES_CCT_Primary, 500);
  EXPECT_EQ(userSettingData.EX_SCT_Primary, 1000);
  EXPECT_EQ(userSettingData.EX_CCT_Primary, 1000);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(1 - 1), 5);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(2 - 1), 5);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(3 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(4 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(5 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(6 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(7 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(8 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(9 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(10 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(11 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(12 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(13 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(14 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(15 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.ES_Bank_kVAr(16 - 1), 100);
  EXPECT_FLOAT_EQ(userSettingData.ES_Target_DPF(), 1);
  EXPECT_FLOAT_EQ(userSettingData.EX_Target_DPF_Grid(), 1);
  EXPECT_FLOAT_EQ(userSettingData.EX_Target_DPF_Generator(), 0.85);
  EXPECT_EQ(userSettingData.EX_PT_Ratio, 10);
  EXPECT_FLOAT_EQ(userSettingData.EX_DT_Ratio(), 1);
  EXPECT_FLOAT_EQ(userSettingData.EX_Correction_Time(), 1);
  EXPECT_EQ(userSettingData.EX_Discharge_Time, 10);
  EXPECT_FLOAT_EQ(userSettingData.EX_Interleave_Time(), 1);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[1 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[2 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[3 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[4 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[5 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[6 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[7 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[8 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[9 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[10 - 1], 180);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[11 - 1], 180);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[12 - 1], 180);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[13 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[14 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[15 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[16 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[17 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[18 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[19 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[20 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[21 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[22 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[23 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[24 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[25 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[26 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[27 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RST_TIME_Uch[28 - 1], 0);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(1 - 1), 0);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(2 - 1), 80);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(3 - 1), 115);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(4 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(5 - 1), 48);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(6 - 1), 52);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(7 - 1), 130);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(8 - 1), 1.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(9 - 1), 1.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(10 - 1), 115);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(11 - 1), 2);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(12 - 1), 88);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(13 - 1), 7.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(14 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(15 - 1), 35);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(16 - 1), 5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(17 - 1), 50);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(18 - 1), 65);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(19 - 1), 0.3);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(20 - 1), 0.3);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(21 - 1), 97.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(22 - 1), 97.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(23 - 1), 175);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(24 - 1), 265);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(25 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(26 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(27 - 1), 20);
  EXPECT_FLOAT_EQ(userSettingData.FLT_SET_Limit_Uch(28 - 1), 7.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(1 - 1), 0);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(2 - 1), 85);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(3 - 1), 110);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(4 - 1), 15);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(5 - 1), 49.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(6 - 1), 51.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(7 - 1), 120);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(8 - 1), 1);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(9 - 1), 2);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(10 - 1), 105);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(11 - 1), 1.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(12 - 1), 92);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(13 - 1), 6.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(14 - 1), 40);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(15 - 1), 25);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(16 - 1), 7.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(17 - 1), 45);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(18 - 1), 60);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(19 - 1), 0.1);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(20 - 1), 0.1);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(21 - 1), 96.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(22 - 1), 96.5);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(23 - 1), 200);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(24 - 1), 250);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(25 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(26 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(27 - 1), 10);
  EXPECT_FLOAT_EQ(userSettingData.FLT_RST_Limit_Uch(28 - 1), 6.5);
  EXPECT_EQ(userSettingData.COM2_Unit_ID, 1);
  EXPECT_EQ(userSettingData.Password, 0);
  EXPECT_EQ(userSettingData.Set_Year, 2021);
  EXPECT_EQ(userSettingData.Display_Contrast, 17000);
  EXPECT_EQ(userSettingData.Aux_In_Mul_Fact, 950);
  EXPECT_EQ(userSettingData.log_Interval, 4);
  EXPECT_EQ(userSettingData.Temp_Bank_Ptr, 1);
  EXPECT_EQ(userSettingData.Temp_Fault_Ptr, 1);
  EXPECT_EQ(userSettingData.Temp_AuxIN_Ptr, 1);
  EXPECT_EQ(userSettingData.Temp_AuxOUT_Ptr, 1);
  EXPECT_EQ(userSettingData.EX_RatedV_Config, 1);
  EXPECT_EQ(userSettingData.ES_Rated_Freq, 0);
  EXPECT_EQ(userSettingData.EX_Rated_Freq, 0);
  EXPECT_EQ(userSettingData.Application, 0);
  EXPECT_EQ(userSettingData.Meas_Config, 1);
  EXPECT_EQ(userSettingData.Scheme, 1);
  EXPECT_EQ(userSettingData.CapCT_Config, 3);
  EXPECT_EQ(userSettingData.ES_SCT_Secondary, 0);
  EXPECT_EQ(userSettingData.ES_CCT_Secondary, 0);
  EXPECT_EQ(userSettingData.EX_SCT_Secondary, 1);
  EXPECT_EQ(userSettingData.EX_CCT_Secondary, 1);
  EXPECT_EQ(userSettingData.ES_NumCap_Bank, 16);
  EXPECT_EQ(userSettingData.ES_Bank_Config[1 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[2 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[3 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[4 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[5 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[6 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[7 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[8 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[9 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[10 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[11 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[12 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[13 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[14 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[15 - 1], 1);
  EXPECT_EQ(userSettingData.ES_Bank_Config[16 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[1 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[2 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[3 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[4 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[5 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[6 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[7 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Config[8 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[9 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[10 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[11 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[12 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[13 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[14 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[15 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Config[16 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[1 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[2 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[3 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[4 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[5 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[6 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[7 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[8 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[9 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[10 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[11 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[12 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[13 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[14 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[15 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_Utilisation_Reset[16 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[1 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[2 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[3 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[4 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[5 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[6 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[7 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[8 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[9 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[10 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[11 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[12 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[13 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[14 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[15 - 1], 0);
  EXPECT_EQ(userSettingData.Bank_kVAr_Reset[16 - 1], 0);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[1 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[2 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[3 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[4 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[5 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[6 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[7 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[8 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[9 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[10 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[11 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[12 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[13 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[14 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[15 - 1], 1);
  EXPECT_EQ(userSettingData.Manual_Bank_Setting[16 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[1 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[2 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[3 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[4 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[5 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[6 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[7 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[8 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[9 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[10 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[11 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[12 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[13 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[14 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[15 - 1], 0);
  EXPECT_EQ(userSettingData.EX_Bank_Unit[16 - 1], 0);
  EXPECT_EQ(userSettingData.ES_DPF_Sign, 1);
  EXPECT_EQ(userSettingData.EX_DPF_Sign_Grid, 1);
  EXPECT_EQ(userSettingData.EX_DPF_Sign_Generator, 1);
  EXPECT_EQ(userSettingData.EX_Vector_Group, 0);
  EXPECT_EQ(userSettingData.EX_MD_Window_Time, 15);
  EXPECT_EQ(userSettingData.EX_Resolution, 15);
  EXPECT_EQ(userSettingData.EX_Offset, 50);
  EXPECT_EQ(userSettingData.EX_Correction_Time_Config, 0);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[1 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[2 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[3 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[4 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[5 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[6 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[7 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[8 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[9 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[10 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[11 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[12 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[13 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[14 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[15 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[16 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[17 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[18 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[19 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[20 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[21 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[22 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[23 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[24 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[25 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[26 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[27 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_RES_Type_Uch[28 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_EN_DS[1 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_EN_DS[2 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[3 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[4 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_EN_DS[5 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_EN_DS[6 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_EN_DS[7 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[8 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[9 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[10 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[11 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[12 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[13 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[14 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[15 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[16 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[17 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[18 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[19 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_EN_DS[20 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[21 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[22 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[23 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[24 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[25 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[26 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[27 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_EN_DS[28 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[1 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[2 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[3 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[4 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[5 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[6 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[7 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[8 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[9 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[10 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[11 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[12 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[13 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[14 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[15 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[16 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[17 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[18 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[19 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[20 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[21 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[22 - 1], 0);
  EXPECT_EQ(userSettingData.FLT_ACT[23 - 1], 2);
  EXPECT_EQ(userSettingData.FLT_ACT[24 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[25 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[26 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[27 - 1], 1);
  EXPECT_EQ(userSettingData.FLT_ACT[28 - 1], 0);
  EXPECT_EQ(userSettingData.AuxIN_Function_1, 0);
  EXPECT_EQ(userSettingData.AuxIN_Function_2, 1);
  EXPECT_EQ(userSettingData.AuxOUT_Function_1, 0);
  EXPECT_EQ(userSettingData.AuxOUT_Function_2, 0);
  EXPECT_EQ(userSettingData.AuxOUT_Function_3, 0);
  EXPECT_EQ(userSettingData.AuxOUT_Function_4, 12);
  EXPECT_EQ(userSettingData.ES_Mode_Config, 1);
  EXPECT_EQ(userSettingData._1A_OFFSET, 0);
  EXPECT_EQ(userSettingData._2A_OFFSET, 1);
  EXPECT_EQ(userSettingData._3A_OFFSET, 2);
  EXPECT_EQ(userSettingData._1A_CT_Polarity, 0);
  EXPECT_EQ(userSettingData._2A_CT_Polarity, 0);
  EXPECT_EQ(userSettingData._3A_CT_Polarity, 0);
  EXPECT_EQ(userSettingData._1CA_OFFSET, 5);
  EXPECT_EQ(userSettingData._2CA_OFFSET, 6);
  EXPECT_EQ(userSettingData._3CA_OFFSET, 7);
  EXPECT_EQ(userSettingData._1CA_CT_Polarity, 0);
  EXPECT_EQ(userSettingData._2CA_CT_Polarity, 0);
  EXPECT_EQ(userSettingData._3CA_CT_Polarity, 0);
  EXPECT_EQ(userSettingData.log_Frame_Type, 2);
  EXPECT_EQ(userSettingData.COM1_BuadRate, 5);
  EXPECT_EQ(userSettingData.COM1_Function, 3);
  EXPECT_EQ(userSettingData.COM2_BuadRate, 4);
  EXPECT_EQ(userSettingData.COM2_Function, 1);
  EXPECT_EQ(userSettingData.Reset_LogData, 0);
  EXPECT_EQ(userSettingData.Energy_Reset_EnDs, 0);
  EXPECT_EQ(userSettingData.Energy_Reset_Date, 1);
  EXPECT_EQ(userSettingData.Energy_Reset_Hr, 0);
  EXPECT_EQ(userSettingData.Energy_Reset_Min, 0);
  EXPECT_EQ(userSettingData.MD_Reset_EnDs, 0);
  EXPECT_EQ(userSettingData.MD_Reset_Date, 1);
  EXPECT_EQ(userSettingData.MD_Reset_Hr, 0);
  EXPECT_EQ(userSettingData.MD_Reset_Min, 0);
  EXPECT_EQ(userSettingData.Max_Reset_EnDs, 0);
  EXPECT_EQ(userSettingData.Max_Reset_Date, 1);
  EXPECT_EQ(userSettingData.Max_Reset_Hr, 0);
  EXPECT_EQ(userSettingData.Max_Reset_Min, 0);
  EXPECT_EQ(userSettingData.GPRS_APN, 0);
  EXPECT_EQ(userSettingData.Other_APN, "None"sv);
  EXPECT_EQ(userSettingData.IP_Address, "139.059.063.063"sv);
  EXPECT_EQ(userSettingData.Main_Server_Name,
            "tas.sublimeenterprise.com/dashboard/post_data"sv);
  EXPECT_EQ(userSettingData.Port, "5002"sv);
  EXPECT_EQ(userSettingData.Sub_Server_Name, "demo "sv);
  EXPECT_EQ(userSettingData.Password_EnDs, 1);
  EXPECT_EQ(userSettingData.Load_Default, 0);
  EXPECT_EQ(userSettingData.Reset_RTC_Date_EnDs, 0);
  EXPECT_EQ(userSettingData.Reset_RTC_Time_EnDs, 0);
  EXPECT_EQ(userSettingData.Set_Date, 1);
  EXPECT_EQ(userSettingData.Set_Month, 10);
  EXPECT_EQ(userSettingData.Set_Hr, 10);
  EXPECT_EQ(userSettingData.Set_Min, 10);
  EXPECT_EQ(userSettingData.Set_Sec, 0);
  EXPECT_EQ(userSettingData.Remote_Update_EnDs, 0);
  EXPECT_EQ(userSettingData.PowerUp_Mode, 0);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[1 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[2 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[3 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[4 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[5 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[6 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[7 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[8 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[9 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[10 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[11 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[12 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[13 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[14 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[15 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[16 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_EnDs[17 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[1 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[2 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[3 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[4 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[5 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[6 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[7 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[8 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[9 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[10 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[11 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[12 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[13 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[14 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[15 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[16 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Lval[17 - 1], 85);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[1 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[2 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[3 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[4 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[5 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[6 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[7 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[8 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[9 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[10 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[11 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[12 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[13 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[14 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[15 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[16 - 1], 115);
  EXPECT_EQ(userSettingData.EX_Bank_HelthCheck_Uval[17 - 1], 115);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[1 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[2 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[3 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[4 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[5 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[6 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[7 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[8 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[9 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[10 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[11 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[12 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[13 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[14 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[15 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[16 - 1], 1);
  EXPECT_EQ(userSettingData.EX_BankUseage_Check_EnDs[17 - 1], 1);
  EXPECT_EQ(userSettingData.EX_Temp_Mains_Gen_Sel, 0);
  EXPECT_EQ(userSettingData.Remote_Operation_Mode, 0);
  EXPECT_EQ(userSettingData.Remote_Mode_Timeout, 5);
  EXPECT_EQ(userSettingData.Remote_Mode_Timeout_Act, 0);
  EXPECT_EQ(userSettingData.Step_Config, 2);
  EXPECT_EQ(userSettingData.Language_Support, 0);
  EXPECT_EQ(userSettingData.Display_Scroll_Config, 0);
  EXPECT_EQ(userSettingData.AutoSync_Retry, 1);
  EXPECT_EQ(userSettingData.AutoSync_FL_Option, 1);
  EXPECT_EQ(userSettingData.Project_Name, ""sv);
  EXPECT_EQ(userSettingData.Load_Balancing_En, 0);
  EXPECT_EQ(userSettingData.Utilisation_Div_TFact, 0);
  EXPECT_EQ(userSettingData.Utilisation_Div_CFact, 1);
  EXPECT_EQ(userSettingData.Num_RT_Data_Frames, 1);
  EXPECT_EQ(userSettingData.AutoDetect_Bank_kVAr, 0);
  EXPECT_EQ(userSettingData.VA_Type, 0);
  EXPECT_EQ(userSettingData.Firmware_Version, "02.01.0012"sv);
}
}  // namespace tas_powertek::spf21y
