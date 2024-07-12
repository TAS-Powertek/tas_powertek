#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/EventData.h"

namespace tas_powertek::spf21y {

TEST(EventDataTest, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kEventData(
      "\x08\x18\x11\x0c\x04\x07\xe8\x42\x47\xf4\x36\x43\x78\xcf\x95\x43\x72\xbf"
      "\x6f\x43\x7b\xba\xe9\x43\x79\x09\x11\x43\x72\xbf\x6f\x43\x7b\xba\xe9\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x41\x0c\x1f\xe1\x00\x00\x03\x43\xd5\x37\xe5"
      "\x43\xd7\x76\xc3\x43\xd7\x03\xca\x43\xd5\x37\xe5\x43\xd7\x5a\x05\x43\xd6"
      "\xe7\x0c\x00\x00\x00\x00\x41\x25\x46\x6c\x41\x0c\x1f\xe1\x00\x02\x02\x1b"
      "\x1c\x1f\x44\x00\x25\xa8\x43\xfd\xbf\x8c\x43\xea\x70\xf9\x43\xf7\x2b\xd0"
      "\x43\xf4\x18\x43\x43\xdf\x68\xa5\x43\x06\xef\xb5\x43\x09\xb1\xca\x43\x0e"
      "\x5c\xb2\x43\x90\x60\xae\x43\x8f\x35\xf4\xff\x0d\x0d\x0e\x48\xa6\x87\x39"
      "\x47\x95\xb4\xe4\x48\xb4\x2f\xd8\x48\xa6\x14\x59\x47\x89\x64\x6e\x48\xac"
      "\xf9\x26\x44\x9f\x47\xa5\x46\x68\x0f\xd1\x47\xe4\x0a\xa5\x47\xda\xca\xc4"
      "\x47\xdb\x47\x75\x47\x25\x55\xb5\x47\x24\xdd\x7f\xc5\xfa\x9b\x3e\x47\xf9"
      "\x39\xc2\x47\xf0\xc8\x7f\x47\xe6\xd1\x11\x47\xe3\x2d\x36\x47\xda\x3b\xff"
      "\x47\xda\xe8\x92\x47\x1d\x93\xe0\x47\x1b\xac\xf0\xc6\x1a\x05\x2d\x48\x07"
      "\xa8\x77\x3f\x6c\x8b\x44\x3f\x75\xc2\x8f\x3f\x6a\x3d\x71\x3f\x68\x72\xb0"
      "\x3f\x73\x33\x33\x3f\x71\xa9\xfc\x3f\x70\xe5\x60\x3f\x7e\xf9\xdb\x43\x26"
      "\x1f\xdd\x43\x26\xf9\x1f\x43\x2b\x6d\xb7\x43\x66\x32\xb1\x42\xb7\xbb\xed"
      "\x42\xb2\x37\xc3\x42\xbf\x5f\x3b\x43\x0a\x1e\x6a\x43\x0d\x16\xd0\x43\x0e"
      "\x26\x62\x96\x9e\x94\x47\x85\xf1\x2c\x33\x30\x33\x30\x00\x00\x00\x00\x00"
      "\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
      "\x00",
      343);
  EventData eventData = EventData::fromByteStream(kEventData);
  EXPECT_EQ(eventData.time.sec, 8);
  EXPECT_EQ(eventData.time.min, 24);
  EXPECT_EQ(eventData.time.hour, 17);
  EXPECT_EQ(eventData.time.day_of_month, 12);
  EXPECT_EQ(eventData.time.month, 4);
  EXPECT_EQ(eventData.time.year, 2024);

  EXPECT_NEAR(*eventData.supplyFrequency, 49.99, 0.01);
  EXPECT_NEAR(*eventData.phase1ToNeutralVoltage_RMS, 248.81, 0.01);
  EXPECT_NEAR(*eventData.phase2ToNeutralVoltage_RMS, 242.75, 0.01);
  EXPECT_NEAR(*eventData.phase3ToNeutralVoltage_RMS, 251.73, 0.01);
  EXPECT_NEAR(*eventData.phase1ToNeutralVoltage_Fundamental, 249.04, 0.01);
  EXPECT_NEAR(*eventData.phase2ToNeutralVoltage_Fundamental, 242.75, 0.01);
  EXPECT_NEAR(*eventData.phase3ToNeutralVoltage_Fundamental, 251.73, 0.01);
  EXPECT_NEAR(*eventData.phase1ToNeutralVoltage_THD, 0, 0.01);
  EXPECT_NEAR(*eventData.phase2ToNeutralVoltage_THD, 0, 0.01);
  EXPECT_NEAR(*eventData.phase3ToNeutralVoltage_THD, 8.76, 0.01);
  EXPECT_EQ(*eventData.phase1ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*eventData.phase2ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*eventData.phase3ToNeutralVoltage_THDPercent, 3);
  EXPECT_NEAR(*eventData.phase1ToPhase2Voltage_RMS, 426.44, 0.01);
  EXPECT_NEAR(*eventData.phase2ToPhase3Voltage_RMS, 430.93, 0.01);
  EXPECT_NEAR(*eventData.phase3ToPhase1Voltage_RMS, 430.03, 0.01);
  EXPECT_NEAR(*eventData.phase1ToPhase2Voltage_Fundamental, 426.44, 0.01);
  EXPECT_NEAR(*eventData.phase2ToPhase3Voltage_Fundamental, 430.70, 0.01);
  EXPECT_NEAR(*eventData.phase3ToPhase1Voltage_Fundamental, 429.81, 0.01);
  EXPECT_NEAR(*eventData.phase1ToPhase2Voltage_THD, 0, 0.01);
  EXPECT_NEAR(*eventData.phase2ToPhase3Voltage_THD, 10.33, 0.01);
  EXPECT_NEAR(*eventData.phase3ToPhase1Voltage_THD, 8.76, 0.01);
  EXPECT_EQ(*eventData.phase1ToPhase2Voltage_THDPercent, 0);
  EXPECT_EQ(*eventData.phase2ToPhase3Voltage_THDPercent, 2);
  EXPECT_EQ(*eventData.phase3ToPhase1Voltage_THDPercent, 2);
  EXPECT_EQ(*eventData.phase1Current_THDPercent, 27);
  EXPECT_EQ(*eventData.phase2Current_THDPercent, 28);
  EXPECT_EQ(*eventData.phase3Current_THDPercent, 31);
  EXPECT_NEAR(*eventData.phase1Current_RMS, 512.58, 0.01);
  EXPECT_NEAR(*eventData.phase2Current_RMS, 507.50, 0.01);
  EXPECT_NEAR(*eventData.phase3Current_RMS, 468.88, 0.01);
  EXPECT_NEAR(*eventData.phase1Current_Fundamental, 494.34, 0.01);
  EXPECT_NEAR(*eventData.phase2Current_Fundamental, 488.19, 0.01);
  EXPECT_NEAR(*eventData.phase3Current_Fundamental, 446.82, 0.01);
  EXPECT_NEAR(*eventData.phase1Current_THD, 134.94, 0.01);
  EXPECT_NEAR(*eventData.phase2Current_THD, 137.69, 0.01);
  EXPECT_NEAR(*eventData.phase3Current_THD, 142.36, 0.01);
  EXPECT_NEAR(*eventData.neutralCurrent_RMS, 288.76, 0.01);
  EXPECT_NEAR(*eventData.neutralCurrent_THD, 286.42, 0.01);
  EXPECT_EQ(*eventData.neutralCurrent_THDPercent, 255);
  EXPECT_EQ(*eventData.phase1Current_TDDPercent, 13);
  EXPECT_EQ(*eventData.phase2Current_TDDPercent, 13);
  EXPECT_EQ(*eventData.phase3Current_TDDPercent, 14);
  EXPECT_NEAR(*eventData.overall3PhActivePower_Combined, 341049.78, 0.01);
  EXPECT_NEAR(*eventData.overall3PhReactivePower_Combined, 76649.78, 0.01);
  EXPECT_NEAR(*eventData.overall3PhApparentPower_Combined, 369022.75, 0.01);
  EXPECT_NEAR(*eventData.overall3PhActivePower_Fundamental, 340130.78, 0.01);
  EXPECT_NEAR(*eventData.overall3PhReactivePower_Fundamental, 70344.86, 0.01);
  EXPECT_NEAR(*eventData.overall3PhApparentPower_Fundamental, 354249.19, 0.01);
  EXPECT_NEAR(*eventData.overall3PhDistortionPower_IEC_IEEE, 1274.24, 0.01);
  EXPECT_NEAR(*eventData.overall3PhDistortionPower_CrossDistortion, 14851.95,
              0.01);
  EXPECT_NEAR(*eventData.phase1ActivePower_Combined, 116757.29, 0.01);
  EXPECT_NEAR(*eventData.phase2ActivePower_Combined, 112021.53, 0.01);
  EXPECT_NEAR(*eventData.phase3ActivePower_Combined, 112270.91, 0.01);
  EXPECT_NEAR(*eventData.phase1ReactivePower_Combined, 42325.71, 0.01);
  EXPECT_NEAR(*eventData.phase2ReactivePower_Combined, 42205.50, 0.01);
  EXPECT_NEAR(*eventData.phase3ReactivePower_Combined, -8019.41, 0.01);
  EXPECT_NEAR(*eventData.phase1ApparentPower_Combined, 127603.52, 0.01);
  EXPECT_NEAR(*eventData.phase2ApparentPower_Combined, 123281.00, 0.01);
  EXPECT_NEAR(*eventData.phase3ApparentPower_Combined, 118178.13, 0.01);
  EXPECT_NEAR(*eventData.phase1ActivePower_Fundamental, 116314.42, 0.01);
  EXPECT_NEAR(*eventData.phase2ActivePower_Fundamental, 111736.00, 0.01);
  EXPECT_NEAR(*eventData.phase3ActivePower_Fundamental, 112081.14, 0.01);
  EXPECT_NEAR(*eventData.phase1ReactivePower_Fundamental, 40339.88, 0.01);
  EXPECT_NEAR(*eventData.phase2ReactivePower_Fundamental, 39852.94, 0.01);
  EXPECT_NEAR(*eventData.phase3ReactivePower_Fundamental, -9857.29, 0.01);
  EXPECT_NEAR(*eventData.overallLoadReactivePower_Fundamental, 138913.86, 0.01);
  EXPECT_NEAR(*eventData.powerFactor_OverallThreePhase, 0.924, 0.01);
  EXPECT_NEAR(*eventData.powerFactor_Fundamental_OverallThreePhase, 0.960,
              0.01);
  EXPECT_NEAR(*eventData.phase1PowerFactor, 0.915, 0.01);
  EXPECT_NEAR(*eventData.phase2PowerFactor, 0.908, 0.01);
  EXPECT_NEAR(*eventData.phase3PowerFactor, 0.950, 0.01);
  EXPECT_NEAR(*eventData.phase1PowerFactor_Fundamental, 0.944, 0.01);
  EXPECT_NEAR(*eventData.phase2PowerFactor_Fundamental, 0.941, 0.01);
  EXPECT_NEAR(*eventData.phase3PowerFactor_Fundamental, 0.996, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase1Current_RMS, 166.12, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase2Current_RMS, 166.97, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase3Current_RMS, 171.43, 0.01);
  EXPECT_NEAR(*eventData.capacitorEarthFaultCurrent_RMS, 230.20, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase1Current_Fundamental, 91.87, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase2Current_Fundamental, 89.11, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase3Current_Fundamental, 95.69, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase1Current_THD, 138.12, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase2Current_THD, 141.09, 0.01);
  EXPECT_NEAR(*eventData.capacitorPhase3Current_THD, 142.15, 0.01);
  EXPECT_EQ(*eventData.capacitorPhase1Current_THDPercent, 150);
  EXPECT_EQ(*eventData.capacitorPhase2Current_THDPercent, 158);
  EXPECT_EQ(*eventData.capacitorPhase3Current_THDPercent, 148);
  EXPECT_NEAR(*eventData.capacitorOverallInjectedReactivePower_Fundamental,
              68578.34, 0.01);

  EXPECT_EQ(3, eventData.bankStatus[1]);
  EXPECT_EQ(3, eventData.bankStatus[2]);
  EXPECT_EQ(3, eventData.bankStatus[3]);
  EXPECT_EQ(0, eventData.bankStatus[4]);
  EXPECT_EQ(3, eventData.bankStatus[5]);
  EXPECT_EQ(3, eventData.bankStatus[6]);
  EXPECT_EQ(3, eventData.bankStatus[7]);
  EXPECT_EQ(0, eventData.bankStatus[8]);
  EXPECT_EQ(0, eventData.bankStatus[9]);
  EXPECT_EQ(0, eventData.bankStatus[10]);
  EXPECT_EQ(0, eventData.bankStatus[11]);
  EXPECT_EQ(0, eventData.bankStatus[12]);
  EXPECT_EQ(0, eventData.bankStatus[13]);
  EXPECT_EQ(0, eventData.bankStatus[14]);
  EXPECT_EQ(0, eventData.bankStatus[15]);
  EXPECT_EQ(0, eventData.bankStatus[16]);

  EXPECT_FALSE(eventData.faultData.OVR());
  EXPECT_FALSE(eventData.faultData.UVR());
  EXPECT_FALSE(eventData.faultData.OVY());
  EXPECT_FALSE(eventData.faultData.UVY());
  EXPECT_FALSE(eventData.faultData.OVB());
  EXPECT_FALSE(eventData.faultData.UVB());
  EXPECT_FALSE(eventData.faultData.OCR());
  EXPECT_FALSE(eventData.faultData.ULR());
  EXPECT_FALSE(eventData.faultData.OCY());
  EXPECT_FALSE(eventData.faultData.ULY());
  EXPECT_FALSE(eventData.faultData.OCB());
  EXPECT_FALSE(eventData.faultData.ULB());
  EXPECT_FALSE(eventData.faultData.COR());
  EXPECT_FALSE(eventData.faultData.CUR());
  EXPECT_FALSE(eventData.faultData.COY());
  EXPECT_FALSE(eventData.faultData.CUY());
  EXPECT_FALSE(eventData.faultData.COB());
  EXPECT_FALSE(eventData.faultData.CUB());
  EXPECT_FALSE(eventData.faultData.SOF());
  EXPECT_FALSE(eventData.faultData.SUF());
  EXPECT_FALSE(eventData.faultData.MOT());
  EXPECT_FALSE(eventData.faultData.ChR());
  EXPECT_FALSE(eventData.faultData.ChY());
  EXPECT_FALSE(eventData.faultData.ChB());
  EXPECT_FALSE(eventData.faultData.OBF());
  EXPECT_FALSE(eventData.faultData.UBA());
  EXPECT_FALSE(eventData.faultData.OCN());
  EXPECT_FALSE(eventData.faultData.EOT());
  EXPECT_FALSE(eventData.faultData.PDN());
  EXPECT_TRUE(eventData.faultData.PUP());
  EXPECT_FALSE(eventData.faultData.RTC());
  EXPECT_FALSE(eventData.faultData.NVF());
  EXPECT_FALSE(eventData.faultData.ZCF());
  EXPECT_FALSE(eventData.faultData.ZVF());
  EXPECT_FALSE(eventData.faultData.MDW());
  EXPECT_FALSE(eventData.faultData.MDV());
  EXPECT_FALSE(eventData.faultData.UBV());
  EXPECT_FALSE(eventData.faultData.UBC());
  EXPECT_FALSE(eventData.faultData.__na_1_());
  EXPECT_FALSE(eventData.faultData.CEL());
  EXPECT_FALSE(eventData.faultData.VHF());
  EXPECT_FALSE(eventData.faultData.CHF());
  EXPECT_FALSE(eventData.faultData.PFR());
  EXPECT_FALSE(eventData.faultData.PFY());
  EXPECT_FALSE(eventData.faultData.PFB());
  EXPECT_FALSE(eventData.faultData.AVL());
  EXPECT_FALSE(eventData.faultData.AVH());
  EXPECT_FALSE(eventData.faultData.CBF());
  EXPECT_FALSE(eventData.faultData.SyF());
  EXPECT_FALSE(eventData.faultData.CTM());
  EXPECT_FALSE(eventData.faultData.ERU());
  EXPECT_FALSE(eventData.faultData.EWU());
  EXPECT_FALSE(eventData.faultData.RM1());
  EXPECT_FALSE(eventData.faultData.RM2());
  EXPECT_FALSE(eventData.faultData.DSB());
  EXPECT_FALSE(eventData.faultData.HLD());
  EXPECT_FALSE(eventData.faultData.AMG());
  EXPECT_FALSE(eventData.faultData.WDR());
  EXPECT_FALSE(eventData.faultData.SyA());
  EXPECT_FALSE(eventData.faultData.SyP());
  EXPECT_FALSE(eventData.faultData.ASM());
  EXPECT_FALSE(eventData.faultData.PEM());
  EXPECT_FALSE(eventData.faultData._EOF());
  EXPECT_FALSE(eventData.faultData._4GN());
  EXPECT_FALSE(eventData.faultData.ERC());
  EXPECT_FALSE(eventData.faultData.ERP());
  EXPECT_FALSE(eventData.faultData.ERE());
  EXPECT_FALSE(eventData.faultData.ERL());
  EXPECT_FALSE(eventData.faultData.EWC());
  EXPECT_FALSE(eventData.faultData.EWP());
  EXPECT_FALSE(eventData.faultData.EWE());
  EXPECT_FALSE(eventData.faultData.EWL());
  EXPECT_FALSE(eventData.faultData.CM1());
  EXPECT_FALSE(eventData.faultData.CM2());
  EXPECT_FALSE(eventData.faultData.PSV());
  EXPECT_FALSE(eventData.faultData.CRT());
  EXPECT_FALSE(eventData.faultData.MRT());
  EXPECT_FALSE(eventData.faultData.UCR());
  EXPECT_FALSE(eventData.faultData.WST());
  EXPECT_FALSE(eventData.faultData.__na_2_());
  EXPECT_FALSE(eventData.faultData.ZVR());
  EXPECT_FALSE(eventData.faultData.ZVY());
  EXPECT_FALSE(eventData.faultData.ZVB());
  EXPECT_FALSE(eventData.faultData.ZCR());
  EXPECT_FALSE(eventData.faultData.ZCY());
  EXPECT_FALSE(eventData.faultData.ZCB());
  EXPECT_FALSE(eventData.faultData.VHR());
  EXPECT_FALSE(eventData.faultData.VHY());
  EXPECT_FALSE(eventData.faultData.VHB());
  EXPECT_FALSE(eventData.faultData.CHR());
  EXPECT_FALSE(eventData.faultData.CHY());
  EXPECT_FALSE(eventData.faultData.CHB());
  EXPECT_FALSE(eventData.faultData.OBR());
  EXPECT_FALSE(eventData.faultData.OBY());
  EXPECT_FALSE(eventData.faultData.OBB());
  EXPECT_FALSE(eventData.faultData.VRH());
  EXPECT_FALSE(eventData.faultData.VYH());
  EXPECT_FALSE(eventData.faultData.VBH());
  EXPECT_FALSE(eventData.faultData.UVF());
  EXPECT_FALSE(eventData.faultData.OVF());
  EXPECT_FALSE(eventData.faultData.PFL());
  EXPECT_FALSE(eventData.faultData.OCF());
  EXPECT_FALSE(eventData.faultData.COF());
  EXPECT_FALSE(eventData.faultData.CUF());
  EXPECT_FALSE(eventData.faultData.VhF());
  EXPECT_FALSE(eventData.faultData.ChF());
  EXPECT_FALSE(eventData.faultData.ULF());
  EXPECT_FALSE(eventData.faultData.ASP());
  EXPECT_FALSE(eventData.faultData.ABD());
  EXPECT_FALSE(eventData.faultData.ABP());
  EXPECT_FALSE(eventData.faultData.MAN());
  EXPECT_FALSE(eventData.faultData.__na_3_());
  EXPECT_FALSE(eventData.faultData.VOL());
  EXPECT_FALSE(eventData.faultData.VOH());
  EXPECT_FALSE(eventData.faultData.VOR());
  EXPECT_FALSE(eventData.faultData.BDF());
  EXPECT_FALSE(eventData.faultData.BDA());
  EXPECT_FALSE(eventData.faultData.BDP());
  EXPECT_FALSE(eventData.faultData.__na_4_());
  EXPECT_FALSE(eventData.faultData.__na_5_());
  EXPECT_FALSE(eventData.faultData.__na_6_());
  EXPECT_FALSE(eventData.faultData.__na_7_());
  EXPECT_FALSE(eventData.faultData.__na_8_());
  EXPECT_FALSE(eventData.faultData.__na_9_());
  EXPECT_FALSE(eventData.faultData.__na_10_());
  EXPECT_FALSE(eventData.faultData.__na_11_());
  EXPECT_FALSE(eventData.faultData.__na_12_());
  EXPECT_FALSE(eventData.faultData.IOK());

  EXPECT_EQ(eventData.auxFnData.inputVoltage, 0);
  EXPECT_EQ(eventData.auxFnData.gprsSignalStrength, 0);
  EXPECT_FALSE(eventData.auxFnData.output1());
  EXPECT_FALSE(eventData.auxFnData.output2());
  EXPECT_FALSE(eventData.auxFnData.output3());
  EXPECT_FALSE(eventData.auxFnData.input());
}
}  // namespace tas_powertek::spf21y
