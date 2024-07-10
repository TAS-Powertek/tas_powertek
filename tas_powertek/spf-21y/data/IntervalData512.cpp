#include "IntervalData512.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {

amp IntervalData512::phase1Current_Harmonics(size_t harmonic) {
  switch (harmonic) {
    case 0:
      return phase1Current_RMS;
    case 1:
      return phase1Current_Fundamental;
    default:
      if (harmonic - 2 < _phase1Current_Harmonics.size()) {
        return _phase1Current_Harmonics[harmonic - 2];
      }
  }
  throw std::runtime_error(
      fmt::format("Invalid phase1 harmonic: {}. Maximum harmonic available: {}",
                  harmonic, _phase1Current_Harmonics.size() + 2));
}

amp IntervalData512::phase2Current_Harmonics(size_t harmonic) {
  switch (harmonic) {
    case 0:
      return phase2Current_RMS;
    case 1:
      return phase2Current_Fundamental;
    default:
      if (harmonic - 2 < _phase2Current_Harmonics.size()) {
        return _phase2Current_Harmonics[harmonic - 2];
      }
  }
  throw std::runtime_error(
      fmt::format("Invalid phase2 harmonic: {}. Maximum harmonic available: {}",
                  harmonic, _phase2Current_Harmonics.size() + 2));
}

amp IntervalData512::phase3Current_Harmonics(size_t harmonic) {
  switch (harmonic) {
    case 0:
      return phase3Current_RMS;
    case 1:
      return phase3Current_Fundamental;
    default:
      if (harmonic - 2 < _phase3Current_Harmonics.size()) {
        return _phase3Current_Harmonics[harmonic - 2];
      }
  }
  throw std::runtime_error(
      fmt::format("Invalid phase3 harmonic: {}. Maximum harmonic available: {}",
                  harmonic, _phase3Current_Harmonics.size() + 2));
}

void IntervalData512::bigEndian() {
  time.bigEndian();
  *supplyFrequency = folly::Endian::big(*supplyFrequency);
  *phase1ToNeutralVoltage_RMS = folly::Endian::big(*phase1ToNeutralVoltage_RMS);
  *phase2ToNeutralVoltage_RMS = folly::Endian::big(*phase2ToNeutralVoltage_RMS);
  *phase3ToNeutralVoltage_RMS = folly::Endian::big(*phase3ToNeutralVoltage_RMS);
  *phase1ToNeutralVoltage_Fundamental =
      folly::Endian::big(*phase1ToNeutralVoltage_Fundamental);
  *phase2ToNeutralVoltage_Fundamental =
      folly::Endian::big(*phase2ToNeutralVoltage_Fundamental);
  *phase3ToNeutralVoltage_Fundamental =
      folly::Endian::big(*phase3ToNeutralVoltage_Fundamental);
  *phase1ToNeutralVoltage_THD = folly::Endian::big(*phase1ToNeutralVoltage_THD);
  *phase2ToNeutralVoltage_THD = folly::Endian::big(*phase2ToNeutralVoltage_THD);
  *phase3ToNeutralVoltage_THD = folly::Endian::big(*phase3ToNeutralVoltage_THD);
  *phase1Voltage_NeutralTHDPercent =
      folly::Endian::big(*phase1Voltage_NeutralTHDPercent);
  *phase2Voltage_NeutralTHDPercent =
      folly::Endian::big(*phase2Voltage_NeutralTHDPercent);
  *phase3Voltage_NeutralTHDPercent =
      folly::Endian::big(*phase3Voltage_NeutralTHDPercent);
  *phase1ToPhase2Voltage_RMS = folly::Endian::big(*phase1ToPhase2Voltage_RMS);
  *phase2ToPhase3Voltage_RMS = folly::Endian::big(*phase2ToPhase3Voltage_RMS);
  *phase3ToPhase1Voltage_RMS = folly::Endian::big(*phase3ToPhase1Voltage_RMS);
  *phase1ToPhase2Voltage_Fundamental =
      folly::Endian::big(*phase1ToPhase2Voltage_Fundamental);
  *phase2ToPhase3Voltage_Fundamental =
      folly::Endian::big(*phase2ToPhase3Voltage_Fundamental);
  *phase3ToPhase1Voltage_Fundamental =
      folly::Endian::big(*phase3ToPhase1Voltage_Fundamental);
  *phase1ToPhase2Voltage_THD = folly::Endian::big(*phase1ToPhase2Voltage_THD);
  *phase2ToPhase3Voltage_THD = folly::Endian::big(*phase2ToPhase3Voltage_THD);
  *phase3ToPhase1Voltage_THD = folly::Endian::big(*phase3ToPhase1Voltage_THD);
  *phase1ToPhase2Voltage_THDPercent =
      folly::Endian::big(*phase1ToPhase2Voltage_THDPercent);
  *phase2ToPhase3Voltage_THDPercent =
      folly::Endian::big(*phase2ToPhase3Voltage_THDPercent);
  *phase3ToPhase1Voltage_THDPercent =
      folly::Endian::big(*phase3ToPhase1Voltage_THDPercent);
  *phase1Current_RMS = folly::Endian::big(*phase1Current_RMS);
  *phase2Current_RMS = folly::Endian::big(*phase2Current_RMS);
  *phase3Current_RMS = folly::Endian::big(*phase3Current_RMS);
  *neutralCurrent_RMS = folly::Endian::big(*neutralCurrent_RMS);
  *neutralCurrent_Fundamental = folly::Endian::big(*neutralCurrent_Fundamental);
  *phase1Current_Fundamental = folly::Endian::big(*phase1Current_Fundamental);
  for (auto& f : _phase1Current_Harmonics) {
    *f = folly::Endian::big(*f);
  }
  *phase2Current_Fundamental = folly::Endian::big(*phase2Current_Fundamental);
  for (auto& f : _phase2Current_Harmonics) {
    *f = folly::Endian::big(*f);
  }
  *phase3Current_Fundamental = folly::Endian::big(*phase3Current_Fundamental);
  for (auto& f : _phase3Current_Harmonics) {
    *f = folly::Endian::big(*f);
  }
  *phase1Current_THD = folly::Endian::big(*phase1Current_THD);
  *phase2Current_THD = folly::Endian::big(*phase2Current_THD);
  *phase3Current_THD = folly::Endian::big(*phase3Current_THD);
  *neutralCurrent_THD = folly::Endian::big(*neutralCurrent_THD);
  *averageCurrent_THD = folly::Endian::big(*averageCurrent_THD);
  *overall3PhActivePower_Combined =
      folly::Endian::big(*overall3PhActivePower_Combined);
  *overall3PhReactivePower_Combined =
      folly::Endian::big(*overall3PhReactivePower_Combined);
  *overall3PhApparentPower_Combined =
      folly::Endian::big(*overall3PhApparentPower_Combined);
  *overall3PhActivePower_Fundamental =
      folly::Endian::big(*overall3PhActivePower_Fundamental);
  *overall3PhReactivePower_Fundamental =
      folly::Endian::big(*overall3PhReactivePower_Fundamental);
  *overall3PhApparentPower_Fundamental =
      folly::Endian::big(*overall3PhApparentPower_Fundamental);
  *overall3PhDistortionPower_IEC_IEEE =
      folly::Endian::big(*overall3PhDistortionPower_IEC_IEEE);
  *overall3PhDistortionPower_CrossDistortion =
      folly::Endian::big(*overall3PhDistortionPower_CrossDistortion);
  *phase1ActivePower_Combined = folly::Endian::big(*phase1ActivePower_Combined);
  *phase2ActivePower_Combined = folly::Endian::big(*phase2ActivePower_Combined);
  *phase3ActivePower_Combined = folly::Endian::big(*phase3ActivePower_Combined);
  *phase1ReactivePower_Combined =
      folly::Endian::big(*phase1ReactivePower_Combined);
  *phase2ReactivePower_Combined =
      folly::Endian::big(*phase2ReactivePower_Combined);
  *phase3ReactivePower_Combined =
      folly::Endian::big(*phase3ReactivePower_Combined);
  *phase1ApparentPower_Combined =
      folly::Endian::big(*phase1ApparentPower_Combined);
  *phase2ApparentPower_Combined =
      folly::Endian::big(*phase2ApparentPower_Combined);
  *phase3ApparentPower_Combined =
      folly::Endian::big(*phase3ApparentPower_Combined);
  *phase1ActivePower_Fundamental =
      folly::Endian::big(*phase1ActivePower_Fundamental);
  *phase2ActivePower_Fundamental =
      folly::Endian::big(*phase2ActivePower_Fundamental);
  *phase3ActivePower_Fundamental =
      folly::Endian::big(*phase3ActivePower_Fundamental);
  *phase1ReactivePower_Fundamental =
      folly::Endian::big(*phase1ReactivePower_Fundamental);
  *phase2ReactivePower_Fundamental =
      folly::Endian::big(*phase2ReactivePower_Fundamental);
  *phase3ReactivePower_Fundamental =
      folly::Endian::big(*phase3ReactivePower_Fundamental);
  *phase1ApparentPower_Fundamental =
      folly::Endian::big(*phase1ApparentPower_Fundamental);
  *phase2ApparentPower_Fundamental =
      folly::Endian::big(*phase2ApparentPower_Fundamental);
  *phase3ApparentPower_Fundamental =
      folly::Endian::big(*phase3ApparentPower_Fundamental);
  *powerFactor_OverallThreePhase =
      folly::Endian::big(*powerFactor_OverallThreePhase);
  *powerFactor_Fundamental_OverallThreePhase =
      folly::Endian::big(*powerFactor_Fundamental_OverallThreePhase);
  *phase1PowerFactor = folly::Endian::big(*phase1PowerFactor);
  *phase2PowerFactor = folly::Endian::big(*phase2PowerFactor);
  *phase3PowerFactor = folly::Endian::big(*phase3PowerFactor);
  *phase1PowerFactor_Fundamental =
      folly::Endian::big(*phase1PowerFactor_Fundamental);
  *phase2PowerFactor_Fundamental =
      folly::Endian::big(*phase2PowerFactor_Fundamental);
  *phase3PowerFactor_Fundamental =
      folly::Endian::big(*phase3PowerFactor_Fundamental);
  *phase1DistortionPower_IEC_IEEE =
      folly::Endian::big(*phase1DistortionPower_IEC_IEEE);
  *phase2DistortionPower_IEC_IEEE =
      folly::Endian::big(*phase2DistortionPower_IEC_IEEE);
  *phase3DistortionPower_IEC_IEEE =
      folly::Endian::big(*phase3DistortionPower_IEC_IEEE);
  *phase1DistortionPower_CrossDistortion =
      folly::Endian::big(*phase1DistortionPower_CrossDistortion);
  *phase2DistortionPower_CrossDistortion =
      folly::Endian::big(*phase2DistortionPower_CrossDistortion);
  *phase3DistortionPower_CrossDistortion =
      folly::Endian::big(*phase3DistortionPower_CrossDistortion);
  *phase1LoadReactivePower_Fundamental =
      folly::Endian::big(*phase1LoadReactivePower_Fundamental);
  *phase2LoadReactivePower_Fundamental =
      folly::Endian::big(*phase2LoadReactivePower_Fundamental);
  *phase3LoadReactivePower_Fundamental =
      folly::Endian::big(*phase3LoadReactivePower_Fundamental);
  *overallLoadReactivePower_Fundamental =
      folly::Endian::big(*overallLoadReactivePower_Fundamental);
  *phase1Current_THDPercent = folly::Endian::big(*phase1Current_THDPercent);
  *phase2Current_THDPercent = folly::Endian::big(*phase2Current_THDPercent);
  *phase3Current_THDPercent = folly::Endian::big(*phase3Current_THDPercent);
  *neutralCurrent_THDPercent = folly::Endian::big(*neutralCurrent_THDPercent);
  *phase1Current_TDDPercent = folly::Endian::big(*phase1Current_TDDPercent);
  *phase2Current_TDDPercent = folly::Endian::big(*phase2Current_TDDPercent);
  *phase3Current_TDDPercent = folly::Endian::big(*phase3Current_TDDPercent);
  *capacitorPhase1Current_THDPercent =
      folly::Endian::big(*capacitorPhase1Current_THDPercent);
  *capacitorPhase2Current_THDPercent =
      folly::Endian::big(*capacitorPhase2Current_THDPercent);
  *capacitorPhase3Current_THDPercent =
      folly::Endian::big(*capacitorPhase3Current_THDPercent);
  *capacitorPhase1Current_RMS = folly::Endian::big(*capacitorPhase1Current_RMS);
  *capacitorPhase2Current_RMS = folly::Endian::big(*capacitorPhase2Current_RMS);
  *capacitorPhase3Current_RMS = folly::Endian::big(*capacitorPhase3Current_RMS);
  *capacitorEarthFaultCurrent_RMS =
      folly::Endian::big(*capacitorEarthFaultCurrent_RMS);
  *capacitorPhase1Current_Fundamental =
      folly::Endian::big(*capacitorPhase1Current_Fundamental);
  *capacitorPhase2Current_Fundamental =
      folly::Endian::big(*capacitorPhase2Current_Fundamental);
  *capacitorPhase3Current_Fundamental =
      folly::Endian::big(*capacitorPhase3Current_Fundamental);
  *capacitorPhase1Current_THD = folly::Endian::big(*capacitorPhase1Current_THD);
  *capacitorPhase2Current_THD = folly::Endian::big(*capacitorPhase2Current_THD);
  *capacitorPhase3Current_THD = folly::Endian::big(*capacitorPhase3Current_THD);
  *averageCapacitorCurrent_THD =
      folly::Endian::big(*averageCapacitorCurrent_THD);
  *capacitorPhase1InjectedReactivePower_Fundamental =
      folly::Endian::big(*capacitorPhase1InjectedReactivePower_Fundamental);
  *capacitorPhase2InjectedReactivePower_Fundamental =
      folly::Endian::big(*capacitorPhase2InjectedReactivePower_Fundamental);
  *capacitorPhase3InjectedReactivePower_Fundamental =
      folly::Endian::big(*capacitorPhase3InjectedReactivePower_Fundamental);
  *capacitorOverallInjectedReactivePower_Fundamental =
      folly::Endian::big(*capacitorOverallInjectedReactivePower_Fundamental);
  bankStatus.bigEndian();
  faultData.bigEndian();
  auxFnData.bigEndian();
}

/* static */ IntervalData512 IntervalData512::fromByteStream(
    std::string_view data) {
  if (data.size() != sizeof(IntervalData512)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into IntervalData512 of size {}",
        data.size(), sizeof(IntervalData512)));
  }

  IntervalData512 result;
  std::memcpy(&result, data.data(), sizeof(IntervalData512));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y