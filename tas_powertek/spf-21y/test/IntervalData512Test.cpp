#include <folly/logging/xlog.h>
#include <gtest/gtest.h>

#include <string>

#include "../data/IntervalData512.h"

namespace tas_powertek::spf21y {

TEST(IntervalData512Test, xlsCalculation) {
  // Based on the XLS sheet provided for EventData
  constexpr std::string_view kInterval512Data(
      "\x19\x19\x11\x0c\x04\x07\xe8\x42\x48\x28\x35\x43\x78\x96\x18\x43\x74\x8b"
      "\x54\x43\x79\xef\x04\x43\x78\x96\x18\x43\x74\x8b\x54\x43\x79\xb5\x87\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x40\xed\x22\x42\x00\x00\x02\x43\xd5\x37\xe5"
      "\x43\xd7\x76\xc3\x43\xd6\x90\xd1\x43\xd5\x37\xe5\x43\xd7\x5a\x05\x43\xd6"
      "\x74\x12\x3e\xe5\xf2\xac\x41\x1a\x7f\x0c\x41\x13\x4f\x76\x00\x02\x02\x43"
      "\xfe\x2c\x2d\x43\xfd\x52\xeb\x43\xfb\xf1\xe1\x43\xaa\xca\xc6\x00\x00\x00"
      "\x00\x43\xee\x42\xa0\x40\xcb\xad\x71\x41\x07\xc8\xf6\x40\x07\xc8\xf6\x41"
      "\x29\xbb\x34\x40\xa9\xbb\x34\x41\x71\x04\xb5\x40\x07\xc8\xf6\x41\x80\xfe"
      "\xea\x40\x4b\xad\x71\x40\xcb\xad\x71\x40\x87\xc8\xf6\x41\x29\xbb\x34\x40"
      "\xed\x9f\xaf\x41\xf9\x81\x44\x41\x07\xc8\xf6\x41\x4f\x12\x77\x41\x29\xbb"
      "\x34\x41\x89\x7b\x79\x41\xf9\x81\x44\x41\xa2\xf1\x27\x41\x29\xbb\x34\x40"
      "\x4b\xad\x71\x42\x0d\xb9\xc1\x41\x60\x0b\x96\x41\xf9\x81\x44\x41\xa2\xf1"
      "\x27\x41\xc6\x95\xe8\x41\xcf\x12\x77\x41\xa2\xf1\x27\x40\x87\xc8\xf6\x43"
      "\xec\xfc\xbe\x40\x07\xc8\xf6\x40\xcb\xad\x71\x40\xed\x9f\xaf\x3f\x87\xc8"
      "\xf6\x40\x07\xc8\xf6\x41\x71\x04\xb5\x40\xa9\xbb\x34\x41\x89\x7b\x79\x40"
      "\xed\x9f\xaf\x40\xa9\xbb\x34\x3f\x87\xc8\xf6\x41\x07\xc8\xf6\x40\xcb\xad"
      "\x71\x40\x87\xc8\xf6\x41\x9a\x74\x98\x41\x07\xc8\xf6\x40\xed\x9f\xaf\x41"
      "\x9a\x74\x98\x41\x07\xc8\xf6\x41\x60\x0b\x96\x42\x1a\x74\x98\x41\x18\xc2"
      "\x15\x41\x60\x0b\x96\x41\xbc\x66\xd6\x42\x1a\x74\x98\x41\xd5\xdc\x84\x41"
      "\x71\x04\xb5\x42\x52\x77\x7e\x41\x4b\xad\x71\x42\x30\x85\x40\x43\xe9\x46"
      "\x3f\x40\x87\xc8\xf6\x41\x80\xfe\xea\x40\xcb\xad\x71\x40\x87\xc8\xf6\x41"
      "\x07\xc8\xf6\x41\x60\x0b\x96\x40\xed\x9f\xaf\x41\x3a\xb4\x53\x41\x18\xc2"
      "\x15\x40\xa9\xbb\x34\x41\x29\xbb\x34\x41\x07\xc8\xf6\x40\xcb\xad\x71\x41"
      "\xa2\xf1\x27\x40\xcb\xad\x71\x41\x4b\xad\x71\x41\xbc\x66\xd6\x41\x07\xc8"
      "\xf6\x40\xa9\xbb\x34\x40\x87\xc8\xf6\x42\x28\x08\xb1\x42\x0d\xb9\xc1\x41"
      "\x91\xf8\x09\x42\x0d\xb9\xc1\x41\xf1\x04\xb5\x42\x45\xbc\xa7\x42\x2c\x46"
      "\xf8\x41\x60\x0b\x96\x41\x3a\xb4\x53\x41\xe8\x88\x26\x43\x30\x85\x40\x43"
      "\x32\x01\x73\x43\x3e\x19\x59\x43\xa9\x84\xe3\x43\x35\x66\x79\x48\xa8\x39"
      "\x82\x46\x31\xb9\x88\x48\xb7\xc8\x50\x48\xa7\xd3\xf0\x45\xa2\x36\x29\x48"
      "\xab\x7b\x8f\x44\xb6\xa4\xe8\x46\xc5\x1b\x14\x47\xe5\x9c\xcc\x47\xe0\x28"
      "\x2e\x47\xdb\x21\x07\x46\x9f\x0c\xf2\x46\xa4\x46\xbe\xc6\xea\x76\xec\x47"
      "\xf6\xf7\x81\x47\xf2\x14\x9d\x47\xf6\x15\x24\x47\xe4\xdb\xf9\x47\xdf\x90"
      "\xc9\x47\xda\xe2\xff\x46\x8e\x7f\x3c\x46\x94\x93\x58\xc6\xfa\x85\x22\x47"
      "\xe7\x9f\x28\x47\xe2\xa1\xba\x47\xe3\xad\x54\x3f\x6a\x54\x25\x3f\x7a\x8b"
      "\x3f\x3f\x6e\x02\xcb\x3f\x6d\x0b\xbc\x3f\x63\xf5\xcf\x3f\x7c\xf2\x63\x3f"
      "\x7c\x89\x58\x3f\x76\x1d\xba\x00\x00\x00\x00\x00\x00\x00\x00\x44\xb6\xa4"
      "\xe8\x45\xf6\x85\x52\x45\xf7\x9b\x93\x46\x13\x25\xb6\x47\x77\x9c\x62\x47"
      "\x76\x90\xff\x46\x64\x4a\xb4\x48\x09\xd0\x03\x25\x25\x28\xff\x11\x11\x13"
      "\x64\x64\x66\x43\x80\xc8\x9a\x43\x80\x25\xa8\x43\x85\xfb\x4b\x43\x92\xb6"
      "\x22\x43\x35\x9c\xc9\x43\x34\x56\xe7\x43\x3a\xea\xa3\x43\x36\x3f\xba\x43"
      "\x36\x09\x6a\x43\x3f\x95\x8b\x43\x39\x38\x20\x47\x30\x5c\xc4\x47\x2c\x47"
      "\x52\x47\x36\x55\x3e\x48\x04\xbe\x55\x11\x10\x21\x10\x00\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x00\x00\x00\x12"
      "\x00",
      775);
  IntervalData512 intervalData =
      IntervalData512::fromByteStream(kInterval512Data);
  EXPECT_EQ(intervalData.time.sec, 25);
  EXPECT_EQ(intervalData.time.min, 25);
  EXPECT_EQ(intervalData.time.hour, 17);
  EXPECT_EQ(intervalData.time.day_of_month, 12);
  EXPECT_EQ(intervalData.time.month, 4);
  EXPECT_EQ(intervalData.time.year, 2024);
  EXPECT_NEAR(*intervalData.supplyFrequency, 50.04, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_RMS, 248.59, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_RMS, 244.54, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_RMS, 249.93, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_Fundamental, 248.59, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_Fundamental, 244.54, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_Fundamental, 249.71, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToNeutralVoltage_THD, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToNeutralVoltage_THD, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToNeutralVoltage_THD, 7.41, 0.01);
  EXPECT_EQ(*intervalData.phase1ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase2ToNeutralVoltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase3ToNeutralVoltage_THDPercent, 2);
  EXPECT_NEAR(*intervalData.phase1ToPhase2Voltage_RMS, 426.44, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToPhase3Voltage_RMS, 430.93, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToPhase1Voltage_RMS, 429.13, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToPhase2Voltage_Fundamental, 426.44, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToPhase3Voltage_Fundamental, 430.70, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToPhase1Voltage_Fundamental, 428.91, 0.01);
  EXPECT_NEAR(*intervalData.phase1ToPhase2Voltage_THD, 0.45, 0.01);
  EXPECT_NEAR(*intervalData.phase2ToPhase3Voltage_THD, 9.66, 0.01);
  EXPECT_NEAR(*intervalData.phase3ToPhase1Voltage_THD, 9.21, 0.01);
  EXPECT_EQ(*intervalData.phase1ToPhase2Voltage_THDPercent, 0);
  EXPECT_EQ(*intervalData.phase2ToPhase3Voltage_THDPercent, 2);
  EXPECT_EQ(*intervalData.phase3ToPhase1Voltage_THDPercent, 2);
  EXPECT_NEAR(*intervalData.phase1Current_RMS, 508.35, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_RMS, 506.65, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_RMS, 503.89, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_RMS, 341.58, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_Fundamental, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Fundamental, 476.52, 0.01);
  EXPECT_EQ(intervalData.phase1Current_Harmonics(0),
            intervalData.phase1Current_RMS);
  EXPECT_EQ(intervalData.phase1Current_Harmonics(1),
            intervalData.phase1Current_Fundamental);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(2), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(3), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(4), 2.12, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(5), 10.61, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(6), 5.30, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(7), 15.06, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(8), 2.12, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(9), 16.12, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(10), 3.18, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(11), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(12), 4.24, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(13), 10.61, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(14), 7.43, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(15), 31.19, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(16), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(17), 12.94, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(18), 10.61, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(19), 17.19, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(20), 31.19, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(21), 20.37, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(22), 10.61, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(23), 3.18, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(24), 35.43, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(25), 14.00, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(26), 31.19, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(27), 20.37, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(28), 24.82, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(29), 25.88, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(30), 20.37, 0.01);
  EXPECT_NEAR(*intervalData.phase1Current_Harmonics(31), 4.24, 0.01);

  EXPECT_NEAR(*intervalData.phase2Current_Fundamental, 473.97, 0.01);
  EXPECT_EQ(intervalData.phase2Current_Harmonics(0),
            intervalData.phase2Current_RMS);
  EXPECT_EQ(intervalData.phase2Current_Harmonics(1),
            intervalData.phase2Current_Fundamental);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(2), 2.12, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(3), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(4), 7.43, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(5), 1.06, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(6), 2.12, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(7), 15.06, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(8), 5.30, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(9), 17.19, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(10), 7.43, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(11), 5.30, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(12), 1.06, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(13), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(14), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(15), 4.24, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(16), 19.31, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(17), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(18), 7.43, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(19), 19.31, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(20), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(21), 14.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(22), 38.61, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(23), 9.55, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(24), 14.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(25), 23.55, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(26), 38.61, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(27), 26.73, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(28), 15.06, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(29), 52.62, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(30), 12.73, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_Harmonics(31), 44.13, 0.01);

  EXPECT_NEAR(*intervalData.phase3Current_Fundamental, 466.55, 0.01);
  EXPECT_EQ(intervalData.phase3Current_Harmonics(0),
            intervalData.phase3Current_RMS);
  EXPECT_EQ(intervalData.phase3Current_Harmonics(1),
            intervalData.phase3Current_Fundamental);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(2), 4.24, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(3), 16.12, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(4), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(5), 4.24, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(6), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(7), 14.00, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(8), 7.43, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(9), 11.67, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(10), 9.55, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(11), 5.30, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(12), 10.61, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(13), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(14), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(15), 20.37, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(16), 6.36, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(17), 12.73, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(18), 23.55, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(19), 8.49, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(20), 5.30, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(21), 4.24, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(22), 42.01, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(23), 35.43, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(24), 18.25, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(25), 35.43, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(26), 30.13, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(27), 49.43, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(28), 43.07, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(29), 14.00, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(30), 11.67, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_Harmonics(31), 29.07, 0.01);

  EXPECT_NEAR(*intervalData.phase1Current_THD, 176.52, 0.01);
  EXPECT_NEAR(*intervalData.phase2Current_THD, 178.01, 0.01);
  EXPECT_NEAR(*intervalData.phase3Current_THD, 190.10, 0.01);
  EXPECT_NEAR(*intervalData.neutralCurrent_THD, 339.04, 0.01);
  EXPECT_NEAR(*intervalData.averageCurrent_THD, 181.40, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhActivePower_Combined, 344524.06, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Combined, 11374.38, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Combined, 376386.50, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhActivePower_Fundamental, 343711.50, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhReactivePower_Fundamental, 5190.77, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhApparentPower_Fundamental, 351196.47,
              0.01);
  EXPECT_NEAR(*intervalData.overall3PhDistortionPower_IEC_IEEE, 1461.15, 0.01);
  EXPECT_NEAR(*intervalData.overall3PhDistortionPower_CrossDistortion, 25229.54,
              0.01);
  EXPECT_NEAR(*intervalData.phase1ActivePower_Combined, 117561.59, 0.01);
  EXPECT_NEAR(*intervalData.phase2ActivePower_Combined, 114768.36, 0.01);
  EXPECT_NEAR(*intervalData.phase3ActivePower_Combined, 112194.05, 0.01);
  EXPECT_NEAR(*intervalData.phase1ReactivePower_Combined, 20358.47, 0.01);
  EXPECT_NEAR(*intervalData.phase2ReactivePower_Combined, 21027.37, 0.01);
  EXPECT_NEAR(*intervalData.phase3ReactivePower_Combined, -30011.46, 0.01);
  EXPECT_NEAR(*intervalData.phase1ApparentPower_Combined, 126447.01, 0.01);
  EXPECT_NEAR(*intervalData.phase2ApparentPower_Combined, 123945.23, 0.01);
  EXPECT_NEAR(*intervalData.phase3ApparentPower_Combined, 125994.28, 0.01);
  EXPECT_NEAR(*intervalData.phase1ActivePower_Fundamental, 117175.95, 0.01);
  EXPECT_NEAR(*intervalData.phase2ActivePower_Fundamental, 114465.57, 0.01);
  EXPECT_NEAR(*intervalData.phase3ActivePower_Fundamental, 112069.99, 0.01);
  EXPECT_NEAR(*intervalData.phase1ReactivePower_Fundamental, 18239.62, 0.01);
  EXPECT_NEAR(*intervalData.phase2ReactivePower_Fundamental, 19017.67, 0.01);
  EXPECT_NEAR(*intervalData.phase3ReactivePower_Fundamental, -32066.57, 0.01);
  EXPECT_NEAR(*intervalData.phase1ApparentPower_Fundamental, 118590.31, 0.01);
  EXPECT_NEAR(*intervalData.phase2ApparentPower_Fundamental, 116035.45, 0.01);
  EXPECT_NEAR(*intervalData.phase3ApparentPower_Fundamental, 116570.66, 0.01);
  EXPECT_NEAR(*intervalData.powerFactor_OverallThreePhase, 0.92, 0.01);
  EXPECT_NEAR(*intervalData.powerFactor_Fundamental_OverallThreePhase, 0.98,
              0.01);
  EXPECT_NEAR(*intervalData.phase1PowerFactor, 0.93, 0.01);
  EXPECT_NEAR(*intervalData.phase2PowerFactor, 0.93, 0.01);
  EXPECT_NEAR(*intervalData.phase3PowerFactor, 0.89, 0.01);
  EXPECT_NEAR(*intervalData.phase1PowerFactor_Fundamental, 0.99, 0.01);
  EXPECT_NEAR(*intervalData.phase2PowerFactor_Fundamental, 0.99, 0.01);
  EXPECT_NEAR(*intervalData.phase3PowerFactor_Fundamental, 0.96, 0.01);
  EXPECT_NEAR(*intervalData.phase1DistortionPower_IEC_IEEE, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase2DistortionPower_IEC_IEEE, 0.00, 0.01);
  EXPECT_NEAR(*intervalData.phase3DistortionPower_IEC_IEEE, 1461.153, 0.01);
  EXPECT_NEAR(*intervalData.phase1DistortionPower_CrossDistortion, 7888.665,
              0.01);
  EXPECT_NEAR(*intervalData.phase2DistortionPower_CrossDistortion, 7923.447,
              0.01);
  EXPECT_NEAR(*intervalData.phase3DistortionPower_CrossDistortion, 9417.428,
              0.01);
  EXPECT_NEAR(*intervalData.phase1LoadReactivePower_Fundamental, 63388.383,
              0.01);
  EXPECT_NEAR(*intervalData.phase2LoadReactivePower_Fundamental, 63120.996,
              0.01);
  EXPECT_NEAR(*intervalData.phase3LoadReactivePower_Fundamental, 14610.676,
              0.01);
  EXPECT_NEAR(*intervalData.overallLoadReactivePower_Fundamental, 141120.047,
              0.01);
  EXPECT_EQ(*intervalData.phase1Current_THDPercent, 37);
  EXPECT_EQ(*intervalData.phase2Current_THDPercent, 37);
  EXPECT_EQ(*intervalData.phase3Current_THDPercent, 40);
  EXPECT_EQ(*intervalData.neutralCurrent_THDPercent, 255);
  EXPECT_EQ(*intervalData.phase1Current_TDDPercent, 17);
  EXPECT_EQ(*intervalData.phase2Current_TDDPercent, 17);
  EXPECT_EQ(*intervalData.phase3Current_TDDPercent, 19);
  EXPECT_EQ(*intervalData.capacitorPhase1Current_THDPercent, 100);
  EXPECT_EQ(*intervalData.capacitorPhase2Current_THDPercent, 100);
  EXPECT_EQ(*intervalData.capacitorPhase3Current_THDPercent, 102);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_RMS, 257.57, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_RMS, 256.29, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_RMS, 267.96, 0.01);
  EXPECT_NEAR(*intervalData.capacitorEarthFaultCurrent_RMS, 293.42, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_Fundamental, 181.61, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_Fundamental, 180.34, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_Fundamental, 186.92, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1Current_THD, 182.25, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2Current_THD, 182.03, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3Current_THD, 191.58, 0.01);
  EXPECT_NEAR(*intervalData.averageCapacitorCurrent_THD, 185.22, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase1InjectedReactivePower_Fundamental,
              45148.77, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase2InjectedReactivePower_Fundamental,
              44103.32, 0.01);
  EXPECT_NEAR(*intervalData.capacitorPhase3InjectedReactivePower_Fundamental,
              46677.24, 0.01);
  EXPECT_NEAR(*intervalData.capacitorOverallInjectedReactivePower_Fundamental,
              135929.33, 0.01);

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
  EXPECT_EQ(intervalData.auxFnData.gprsSignalStrength, 18);
  EXPECT_FALSE(intervalData.auxFnData.output1());
  EXPECT_FALSE(intervalData.auxFnData.output2());
  EXPECT_FALSE(intervalData.auxFnData.output3());
  EXPECT_FALSE(intervalData.auxFnData.input());
}
}  // namespace tas_powertek::spf21y
