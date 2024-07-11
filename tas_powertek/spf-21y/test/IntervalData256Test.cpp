#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/IntervalData256.h"

namespace tas_powertek::spf21y {

TEST(IntervalData256Test, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval256Data(
      "\x35\x00\x12\x0c\x04\x07\xe8\x42\x48\xe8\x12\x43\x7b\xf4\x66\x43\x76\x57"
      "\x39\x43\x7b\x0e\x73\x43\x7b\xf4\x66\x43\x76\x57\x39\x43\x7a\xd4\xf7\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x41\x13\x4f\x76\x00\x00\x03\x43\xd7\x03\xca"
      "\x43\xd9\x09\x2c\x43\xd8\xb2\xf1\x43\xd8\x3f\xf8\x43\xd8\x3f\xf8\x00\x00"
      "\x00\x00\x41\x3a\xd5\x2c\x40\xf4\x51\xd7\x00\x02\x01\x25\x25\x28\x43\xff"
      "\x8d\x37\x43\xfd\x1c\x9b\x43\xfb\x85\x40\x43\xef\x88\x82\x43\xed\x17\xe6"
      "\x43\xe8\xd9\x9e\x43\x32\x37\xc3\x43\x31\x28\x31\x43\x3e\x4f\xa9\x43\xa7"
      "\x80\xe8\x00\x00\x00\x00\x43\xa6\x56\x2e\xff\x11\x11\x13\x48\xa9\xd8\x53"
      "\x46\x26\x7b\xba\x48\xb9\x96\x8b\x48\xa9\x6d\xe2\x45\x87\x81\xf2\x48\xad"
      "\x26\x25\x44\xdf\x01\x90\x46\xc7\x6e\x5e\x47\xea\x1b\x2e\x47\xe1\xdd\x18"
      "\x47\xdb\x69\x06\x46\x9d\x8d\x04\x46\xa4\x3d\x4f\xc6\xee\x8c\x5e\x47\xfb"
      "\xb8\xf3\x47\xf3\xbd\xc7\x47\xf6\xe3\x6c\x47\xe9\x41\x7d\x47\xe1\x51\x1c"
      "\x47\xdb\x24\xf0\x46\x8e\x82\x30\x46\x93\x85\x93\xc7\x00\x13\xb0\x48\x0b"
      "\xc1\x4e\x3f\x6a\x48\xb8\x3f\x7a\x80\x16\x3f\x6e\x15\x99\x3f\x6d\x39\x22"
      "\x3f\x63\x81\xfd\x3f\x7d\x0f\x39\x3f\x7c\xa2\xe8\x3f\x75\xb8\x2a\x43\x82"
      "\x7b\x1d\x43\x80\xc8\x9a\x43\x86\xd4\x8c\x43\x8f\x1a\xcb\x43\x38\xcb\x7f"
      "\x43\x36\x3f\xba\x43\x3c\x9d\x26\x43\x37\xf2\x3e\x43\x35\x9c\xc9\x43\x40"
      "\x6e\xcd\x63\x63\x66\x48\x07\x85\x41\x11\x10\x21\x10\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x00\x00\x00\x10"
      "\x00",
      343);
  IntervalData256 intervalData =
      IntervalData256::fromByteStream(kInterval256Data);
  EXPECT_EQ(intervalData.time.sec, 53);
  EXPECT_EQ(intervalData.time.min, 0);
  EXPECT_EQ(intervalData.time.hour, 18);
  EXPECT_EQ(intervalData.time.day_of_month, 12);
  EXPECT_EQ(intervalData.time.month, 4);
  EXPECT_EQ(intervalData.time.year, 2024);
  EXPECT_NEAR(*intervalData.supplyFrequency, 50.22, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_RMS, 251.95, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_RMS, 246.34, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_RMS, 251.06, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_Fundamental, 251.95, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_Fundamental, 246.34, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_Fundamental, 250.83, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_THD, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_THD, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_THD, 9.21, 0.01);
  EXPECT_EQ(*intervalData.phase1ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase2ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase3ToNeutralVoltage_THDPercent, 3);
  EXPECT_NEAR(*intervalData.phase1ToPhase2Voltage_RMS, 430.03, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToPhase3Voltage_RMS, 434.07, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToPhase1Voltage_RMS, 433.40, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_RMS, 432.50, 0.01);
  EXPECT_NEAR(*intervalData.averagePhaseToPhaseVoltage_Fundamental, 432.50,
              0.01);
  EXPECT_NEAR(*intervalData.phase1ToPhase2Voltage_THD, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToPhase3Voltage_THD, 11.68, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToPhase1Voltage_THD, 7.63, 0.01);
  EXPECT_EQ(*intervalData.phase1ToPhase2Voltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase2ToPhase3Voltage_THDPercent, 2);
  EXPECT_EQ(*intervalData.phase3ToPhase1Voltage_THDPercent, 1);
  EXPECT_EQ(*intervalData.phase1Current_THDPercent, 37);
  EXPECT_EQ(*intervalData.phase2Current_THDPercent, 37);
  EXPECT_EQ(*intervalData.phase3Current_THDPercent, 40);
  EXPECT_NEAR(*intervalData.phase1Current_RMS, 511.10, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_RMS, 506.22, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_RMS, 503.04, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Fundamental, 479.07, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Fundamental, 474.19, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Fundamental, 465.70, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_THD, 178.22, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_THD, 177.16, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_THD, 190.31, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_RMS, 335.00, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_Fundamental, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_THD, 332.67, 0.01);
  EXPECT_EQ(*intervalData.neutralCurrent_THDPercent, 255);
  EXPECT_EQ(*intervalData.phase1Current_TDDPercent, 17);
  EXPECT_EQ(*intervalData.phase2Current_TDDPercent, 17);
  EXPECT_EQ(*intervalData.phase3Current_TDDPercent, 19);

  EXPECT_NEAR(*intervalData.overall3PhActivePower_Combined, 347842.59, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Combined, 10654.93, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Combined, 380084.34, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhActivePower_Fundamental, 346991.06, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Fundamental, 4336.24, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Fundamental, 354609.16,
              0.01);
  EXPECT_NEAR(*intervalData.overall3PhDistortionPower_IEC_IEEE, 1784.05, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhDistortionPower_CrossDistortion, 25527.18,
              0.01);
  EXPECT_NEAR(*intervalData.phase1ActivePower_Combined, 119862.36, 0.01);
  EXPECT_NEAR(*intervalData.phase2ActivePower_Combined, 115642.19, 0.01);
  EXPECT_NEAR(*intervalData.phase3ActivePower_Combined, 112338.05, 0.01);
  EXPECT_NEAR(*intervalData.phase1ReactivePower_Combined, 20166.51, 0.01);
  EXPECT_NEAR(*intervalData.phase2ReactivePower_Combined, 21022.65, 0.01);
  EXPECT_NEAR(*intervalData.phase3ReactivePower_Combined, -30534.18, 0.01);
  EXPECT_NEAR(*intervalData.phase1ApparentPower_Combined, 128881.90, 0.01);
  EXPECT_NEAR(*intervalData.phase2ApparentPower_Combined, 124795.55, 0.01);
  EXPECT_NEAR(*intervalData.phase3ApparentPower_Combined, 126406.84, 0.01);
  EXPECT_NEAR(*intervalData.phase1ActivePower_Fundamental, 119426.98, 0.01);
  EXPECT_NEAR(*intervalData.phase2ActivePower_Fundamental, 115362.22, 0.01);
  EXPECT_NEAR(*intervalData.phase3ActivePower_Fundamental, 112201.88, 0.01);
  EXPECT_NEAR(*intervalData.phase1ReactivePower_Fundamental, 18241.09, 0.01);
  EXPECT_NEAR(*intervalData.phase2ReactivePower_Fundamental, 18882.79, 0.01);
  EXPECT_NEAR(*intervalData.phase3ReactivePower_Fundamental, -32787.69, 0.01);
  EXPECT_NEAR(*intervalData.overallLoadReactivePower_Fundamental, 143109.22,
              0.01);

  EXPECT_NEAR(*intervalData.powerFactor_OverallThreePhase, 0.915, 0.01);
  EXPECT_NEAR(*intervalData.powerFactor_Fundamental_OverallThreePhase, 0.979,
              0.01);
  EXPECT_NEAR(*intervalData.phase1PowerFactor, 0.930, 0.01);
  EXPECT_NEAR(*intervalData.phase2PowerFactor, 0.927, 0.01);
  EXPECT_NEAR(*intervalData.phase3PowerFactor, 0.889, 0.01);
  EXPECT_NEAR(*intervalData.phase1PowerFactor_Fundamental, 0.989, 0.01);
  EXPECT_NEAR(*intervalData.phase2PowerFactor_Fundamental, 0.987, 0.01);
  EXPECT_NEAR(*intervalData.phase3PowerFactor_Fundamental, 0.960, 0.01);

  EXPECT_NEAR(*intervalData.capacitorPhase1Current_RMS, 260.96, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_RMS, 257.57, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_RMS, 269.66, 0.01);
  EXPECT_NEAR(*intervalData.capacitorEarthFaultCurrent_RMS, 286.21, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_Fundamental, 184.79, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_Fundamental, 182.25, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_Fundamental, 188.61, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_THD, 183.95, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_THD, 181.61, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_THD, 192.43, 0.01);
  EXPECT_EQ(*intervalData.capacitorPhase1Current_THDPercent, 99);
  EXPECT_EQ(*intervalData.capacitorPhase2Current_THDPercent, 99);
  EXPECT_EQ(*intervalData.capacitorPhase3Current_THDPercent, 102);
  EXPECT_NEAR(*intervalData.capacitorOverallInjectedReactivePower_Fundamental,
              138773.02, 0.01);

  EXPECT_EQ(1, intervalData.bankStatus[1]);
  EXPECT_EQ(1, intervalData.bankStatus[2]);
  EXPECT_EQ(1, intervalData.bankStatus[3]);
  EXPECT_EQ(0, intervalData.bankStatus[4]);
  EXPECT_EQ(2, intervalData.bankStatus[5]);
  EXPECT_EQ(1, intervalData.bankStatus[6]);
  EXPECT_EQ(1, intervalData.bankStatus[7]);
  EXPECT_EQ(0, intervalData.bankStatus[8]);
  EXPECT_EQ(0, intervalData.bankStatus[9]);
  EXPECT_EQ(0, intervalData.bankStatus[10]);
  EXPECT_EQ(0, intervalData.bankStatus[11]);
  EXPECT_EQ(0, intervalData.bankStatus[12]);
  EXPECT_EQ(0, intervalData.bankStatus[13]);
  EXPECT_EQ(0, intervalData.bankStatus[14]);
  EXPECT_EQ(0, intervalData.bankStatus[15]);
  EXPECT_EQ(0, intervalData.bankStatus[16]);

  EXPECT_FALSE(intervalData.faultData.OVR());
  EXPECT_FALSE(intervalData.faultData.UVR());
  EXPECT_FALSE(intervalData.faultData.OVY());
  EXPECT_FALSE(intervalData.faultData.UVY());
  EXPECT_FALSE(intervalData.faultData.OVB());
  EXPECT_FALSE(intervalData.faultData.UVB());
  EXPECT_FALSE(intervalData.faultData.OCR());
  EXPECT_FALSE(intervalData.faultData.ULR());
  EXPECT_FALSE(intervalData.faultData.OCY());
  EXPECT_FALSE(intervalData.faultData.ULY());
  EXPECT_FALSE(intervalData.faultData.OCB());
  EXPECT_FALSE(intervalData.faultData.ULB());
  EXPECT_FALSE(intervalData.faultData.COR());
  EXPECT_FALSE(intervalData.faultData.CUR());
  EXPECT_FALSE(intervalData.faultData.COY());
  EXPECT_FALSE(intervalData.faultData.CUY());
  EXPECT_FALSE(intervalData.faultData.COB());
  EXPECT_FALSE(intervalData.faultData.CUB());
  EXPECT_FALSE(intervalData.faultData.SOF());
  EXPECT_FALSE(intervalData.faultData.SUF());
  EXPECT_FALSE(intervalData.faultData.MOT());
  EXPECT_FALSE(intervalData.faultData.ChR());
  EXPECT_FALSE(intervalData.faultData.ChY());
  EXPECT_FALSE(intervalData.faultData.ChB());
  EXPECT_FALSE(intervalData.faultData.OBF());
  EXPECT_FALSE(intervalData.faultData.UBA());
  EXPECT_FALSE(intervalData.faultData.OCN());
  EXPECT_FALSE(intervalData.faultData.EOT());
  EXPECT_FALSE(intervalData.faultData.PDN());
  EXPECT_FALSE(intervalData.faultData.PUP());
  EXPECT_FALSE(intervalData.faultData.RTC());
  EXPECT_FALSE(intervalData.faultData.NVF());
  EXPECT_FALSE(intervalData.faultData.ZCF());
  EXPECT_FALSE(intervalData.faultData.ZVF());
  EXPECT_FALSE(intervalData.faultData.MDW());
  EXPECT_FALSE(intervalData.faultData.MDV());
  EXPECT_FALSE(intervalData.faultData.UBV());
  EXPECT_FALSE(intervalData.faultData.UBC());
  EXPECT_FALSE(intervalData.faultData.__na_1_());
  EXPECT_FALSE(intervalData.faultData.CEL());
  EXPECT_FALSE(intervalData.faultData.VHF());
  EXPECT_FALSE(intervalData.faultData.CHF());
  EXPECT_FALSE(intervalData.faultData.PFR());
  EXPECT_FALSE(intervalData.faultData.PFY());
  EXPECT_FALSE(intervalData.faultData.PFB());
  EXPECT_FALSE(intervalData.faultData.AVL());
  EXPECT_FALSE(intervalData.faultData.AVH());
  EXPECT_FALSE(intervalData.faultData.CBF());
  EXPECT_FALSE(intervalData.faultData.SyF());
  EXPECT_FALSE(intervalData.faultData.CTM());
  EXPECT_FALSE(intervalData.faultData.ERU());
  EXPECT_FALSE(intervalData.faultData.EWU());
  EXPECT_FALSE(intervalData.faultData.RM1());
  EXPECT_FALSE(intervalData.faultData.RM2());
  EXPECT_FALSE(intervalData.faultData.DSB());
  EXPECT_FALSE(intervalData.faultData.HLD());
  EXPECT_FALSE(intervalData.faultData.AMG());
  EXPECT_FALSE(intervalData.faultData.WDR());
  EXPECT_FALSE(intervalData.faultData.SyA());
  EXPECT_FALSE(intervalData.faultData.SyP());
  EXPECT_FALSE(intervalData.faultData.ASM());
  EXPECT_FALSE(intervalData.faultData.PEM());
  EXPECT_FALSE(intervalData.faultData._EOF());
  EXPECT_FALSE(intervalData.faultData._4GN());
  EXPECT_FALSE(intervalData.faultData.ERC());
  EXPECT_FALSE(intervalData.faultData.ERP());
  EXPECT_FALSE(intervalData.faultData.ERE());
  EXPECT_FALSE(intervalData.faultData.ERL());
  EXPECT_FALSE(intervalData.faultData.EWC());
  EXPECT_FALSE(intervalData.faultData.EWP());
  EXPECT_FALSE(intervalData.faultData.EWE());
  EXPECT_FALSE(intervalData.faultData.EWL());
  EXPECT_FALSE(intervalData.faultData.CM1());
  EXPECT_FALSE(intervalData.faultData.CM2());
  EXPECT_FALSE(intervalData.faultData.PSV());
  EXPECT_FALSE(intervalData.faultData.CRT());
  EXPECT_FALSE(intervalData.faultData.MRT());
  EXPECT_FALSE(intervalData.faultData.UCR());
  EXPECT_FALSE(intervalData.faultData.WST());
  EXPECT_FALSE(intervalData.faultData.__na_2_());
  EXPECT_FALSE(intervalData.faultData.ZVR());
  EXPECT_FALSE(intervalData.faultData.ZVY());
  EXPECT_FALSE(intervalData.faultData.ZVB());
  EXPECT_FALSE(intervalData.faultData.ZCR());
  EXPECT_FALSE(intervalData.faultData.ZCY());
  EXPECT_FALSE(intervalData.faultData.ZCB());
  EXPECT_FALSE(intervalData.faultData.VHR());
  EXPECT_FALSE(intervalData.faultData.VHY());
  EXPECT_FALSE(intervalData.faultData.VHB());
  EXPECT_FALSE(intervalData.faultData.CHR());
  EXPECT_FALSE(intervalData.faultData.CHY());
  EXPECT_FALSE(intervalData.faultData.CHB());
  EXPECT_FALSE(intervalData.faultData.OBR());
  EXPECT_FALSE(intervalData.faultData.OBY());
  EXPECT_FALSE(intervalData.faultData.OBB());
  EXPECT_FALSE(intervalData.faultData.VRH());
  EXPECT_FALSE(intervalData.faultData.VYH());
  EXPECT_FALSE(intervalData.faultData.VBH());
  EXPECT_FALSE(intervalData.faultData.UVF());
  EXPECT_FALSE(intervalData.faultData.OVF());
  EXPECT_FALSE(intervalData.faultData.PFL());
  EXPECT_FALSE(intervalData.faultData.OCF());
  EXPECT_FALSE(intervalData.faultData.COF());
  EXPECT_FALSE(intervalData.faultData.CUF());
  EXPECT_FALSE(intervalData.faultData.VhF());
  EXPECT_FALSE(intervalData.faultData.ChF());
  EXPECT_FALSE(intervalData.faultData.ULF());
  EXPECT_FALSE(intervalData.faultData.ASP());
  EXPECT_FALSE(intervalData.faultData.ABD());
  EXPECT_FALSE(intervalData.faultData.ABP());
  EXPECT_FALSE(intervalData.faultData.MAN());
  EXPECT_FALSE(intervalData.faultData.__na_3_());
  EXPECT_FALSE(intervalData.faultData.VOL());
  EXPECT_FALSE(intervalData.faultData.VOH());
  EXPECT_FALSE(intervalData.faultData.VOR());
  EXPECT_FALSE(intervalData.faultData.BDF());
  EXPECT_FALSE(intervalData.faultData.BDA());
  EXPECT_FALSE(intervalData.faultData.BDP());
  EXPECT_FALSE(intervalData.faultData.__na_4_());
  EXPECT_FALSE(intervalData.faultData.__na_5_());
  EXPECT_FALSE(intervalData.faultData.__na_6_());
  EXPECT_FALSE(intervalData.faultData.__na_7_());
  EXPECT_FALSE(intervalData.faultData.__na_8_());
  EXPECT_FALSE(intervalData.faultData.__na_9_());
  EXPECT_FALSE(intervalData.faultData.__na_10_());
  EXPECT_FALSE(intervalData.faultData.__na_11_());
  EXPECT_FALSE(intervalData.faultData.__na_12_());
  EXPECT_TRUE(intervalData.faultData.IOK());

  EXPECT_EQ(intervalData.auxFnData.inputVoltage, 0);
  EXPECT_EQ(intervalData.auxFnData.gprsSignalStrength, 16);
  EXPECT_FALSE(intervalData.auxFnData.output1());
  EXPECT_FALSE(intervalData.auxFnData.output2());
  EXPECT_FALSE(intervalData.auxFnData.output3());
  EXPECT_FALSE(intervalData.auxFnData.input());
}
}  // namespace tas_powertek::spf21y
