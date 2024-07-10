#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/FaultData.h"

namespace tas_powertek::spf21y {

TEST(FaultDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kEventData(
      "\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 16);
  FaultData faultData = FaultData::fromByteStream(kEventData);
  EXPECT_FALSE(faultData.OVR());
  EXPECT_FALSE(faultData.UVR());
  EXPECT_FALSE(faultData.OVY());
  EXPECT_FALSE(faultData.UVY());
  EXPECT_FALSE(faultData.OVB());
  EXPECT_FALSE(faultData.UVB());
  EXPECT_FALSE(faultData.OCR());
  EXPECT_FALSE(faultData.ULR());
  EXPECT_FALSE(faultData.OCY());
  EXPECT_FALSE(faultData.ULY());
  EXPECT_FALSE(faultData.OCB());
  EXPECT_FALSE(faultData.ULB());
  EXPECT_FALSE(faultData.COR());
  EXPECT_FALSE(faultData.CUR());
  EXPECT_FALSE(faultData.COY());
  EXPECT_FALSE(faultData.CUY());
  EXPECT_FALSE(faultData.COB());
  EXPECT_FALSE(faultData.CUB());
  EXPECT_FALSE(faultData.SOF());
  EXPECT_FALSE(faultData.SUF());
  EXPECT_FALSE(faultData.MOT());
  EXPECT_FALSE(faultData.ChR());
  EXPECT_FALSE(faultData.ChY());
  EXPECT_FALSE(faultData.ChB());
  EXPECT_FALSE(faultData.OBF());
  EXPECT_FALSE(faultData.UBA());
  EXPECT_FALSE(faultData.OCN());
  EXPECT_FALSE(faultData.EOT());
  EXPECT_FALSE(faultData.PDN());
  EXPECT_TRUE(faultData.PUP());
  EXPECT_FALSE(faultData.RTC());
  EXPECT_FALSE(faultData.NVF());
  EXPECT_FALSE(faultData.ZCF());
  EXPECT_FALSE(faultData.ZVF());
  EXPECT_FALSE(faultData.MDW());
  EXPECT_FALSE(faultData.MDV());
  EXPECT_FALSE(faultData.UBV());
  EXPECT_FALSE(faultData.UBC());
  EXPECT_FALSE(faultData.__na_1_());
  EXPECT_FALSE(faultData.CEL());
  EXPECT_FALSE(faultData.VHF());
  EXPECT_FALSE(faultData.CHF());
  EXPECT_FALSE(faultData.PFR());
  EXPECT_FALSE(faultData.PFY());
  EXPECT_FALSE(faultData.PFB());
  EXPECT_FALSE(faultData.AVL());
  EXPECT_FALSE(faultData.AVH());
  EXPECT_FALSE(faultData.CBF());
  EXPECT_FALSE(faultData.SyF());
  EXPECT_FALSE(faultData.CTM());
  EXPECT_FALSE(faultData.ERU());
  EXPECT_FALSE(faultData.EWU());
  EXPECT_FALSE(faultData.RM1());
  EXPECT_FALSE(faultData.RM2());
  EXPECT_FALSE(faultData.DSB());
  EXPECT_FALSE(faultData.HLD());
  EXPECT_FALSE(faultData.AMG());
  EXPECT_FALSE(faultData.WDR());
  EXPECT_FALSE(faultData.SyA());
  EXPECT_FALSE(faultData.SyP());
  EXPECT_FALSE(faultData.ASM());
  EXPECT_FALSE(faultData.PEM());
  EXPECT_FALSE(faultData._EOF());
  EXPECT_FALSE(faultData._4GN());
  EXPECT_FALSE(faultData.ERC());
  EXPECT_FALSE(faultData.ERP());
  EXPECT_FALSE(faultData.ERE());
  EXPECT_FALSE(faultData.ERL());
  EXPECT_FALSE(faultData.EWC());
  EXPECT_FALSE(faultData.EWP());
  EXPECT_FALSE(faultData.EWE());
  EXPECT_FALSE(faultData.EWL());
  EXPECT_FALSE(faultData.CM1());
  EXPECT_FALSE(faultData.CM2());
  EXPECT_FALSE(faultData.PSV());
  EXPECT_FALSE(faultData.CRT());
  EXPECT_FALSE(faultData.MRT());
  EXPECT_FALSE(faultData.UCR());
  EXPECT_FALSE(faultData.WST());
  EXPECT_FALSE(faultData.__na_2_());
  EXPECT_FALSE(faultData.ZVR());
  EXPECT_FALSE(faultData.ZVY());
  EXPECT_FALSE(faultData.ZVB());
  EXPECT_FALSE(faultData.ZCR());
  EXPECT_FALSE(faultData.ZCY());
  EXPECT_FALSE(faultData.ZCB());
  EXPECT_FALSE(faultData.VHR());
  EXPECT_FALSE(faultData.VHY());
  EXPECT_FALSE(faultData.VHB());
  EXPECT_FALSE(faultData.CHR());
  EXPECT_FALSE(faultData.CHY());
  EXPECT_FALSE(faultData.CHB());
  EXPECT_FALSE(faultData.OBR());
  EXPECT_FALSE(faultData.OBY());
  EXPECT_FALSE(faultData.OBB());
  EXPECT_FALSE(faultData.VRH());
  EXPECT_FALSE(faultData.VYH());
  EXPECT_FALSE(faultData.VBH());
  EXPECT_FALSE(faultData.UVF());
  EXPECT_FALSE(faultData.OVF());
  EXPECT_FALSE(faultData.PFL());
  EXPECT_FALSE(faultData.OCF());
  EXPECT_FALSE(faultData.COF());
  EXPECT_FALSE(faultData.CUF());
  EXPECT_FALSE(faultData.VhF());
  EXPECT_FALSE(faultData.ChF());
  EXPECT_FALSE(faultData.ULF());
  EXPECT_FALSE(faultData.ASP());
  EXPECT_FALSE(faultData.ABD());
  EXPECT_FALSE(faultData.ABP());
  EXPECT_FALSE(faultData.MAN());
  EXPECT_FALSE(faultData.__na_3_());
  EXPECT_FALSE(faultData.VOL());
  EXPECT_FALSE(faultData.VOH());
  EXPECT_FALSE(faultData.VOR());
  EXPECT_FALSE(faultData.BDF());
  EXPECT_FALSE(faultData.BDA());
  EXPECT_FALSE(faultData.BDP());
  EXPECT_FALSE(faultData.__na_4_());
  EXPECT_FALSE(faultData.__na_5_());
  EXPECT_FALSE(faultData.__na_6_());
  EXPECT_FALSE(faultData.__na_7_());
  EXPECT_FALSE(faultData.__na_8_());
  EXPECT_FALSE(faultData.__na_9_());
  EXPECT_FALSE(faultData.__na_10_());
  EXPECT_FALSE(faultData.__na_11_());
  EXPECT_FALSE(faultData.__na_12_());
  EXPECT_FALSE(faultData.IOK());
  XLOGF(INFO, "{}", faultData.faultBits.to_string());
}
}  // namespace tas_powertek::spf21y