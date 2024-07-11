#include "IntervalData128.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
void IntervalData128::bigEndian() {
  time.bigEndian();
  *supplyFrequency = folly::Endian::big(*supplyFrequency);
  *phase1ToNeutralVoltage_RMS = folly::Endian::big(*phase1ToNeutralVoltage_RMS);
  *phase2ToNeutralVoltage_RMS = folly::Endian::big(*phase2ToNeutralVoltage_RMS);
  *phase3ToNeutralVoltage_RMS = folly::Endian::big(*phase3ToNeutralVoltage_RMS);
  *averagePhaseToNeutralVoltage_Fundamental =
      folly::Endian::big(*averagePhaseToNeutralVoltage_Fundamental);
  *averagePhaseToNeutralVolage_THD =
      folly::Endian::big(*averagePhaseToNeutralVolage_THD);
  *averagePhaseToPhaseVoltage_RMS =
      folly::Endian::big(*averagePhaseToPhaseVoltage_RMS);
  *averagePhaseToPhaseVoltage_Fundamental =
      folly::Endian::big(*averagePhaseToPhaseVoltage_Fundamental);
  *phase1Current_RMS = folly::Endian::big(*phase1Current_RMS);
  *phase2Current_RMS = folly::Endian::big(*phase2Current_RMS);
  *phase3Current_RMS = folly::Endian::big(*phase3Current_RMS);
  *neutralCurrent_RMS = folly::Endian::big(*neutralCurrent_RMS);
  *averagePhaseCurrent_Fundamental =
      folly::Endian::big(*averagePhaseCurrent_Fundamental);
  *averagePhaseCurrent_THD = folly::Endian::big(*averagePhaseCurrent_THD);
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
  *capacitorPhase1Current_THDPercent =
      folly::Endian::big(*capacitorPhase1Current_THDPercent);
  *capacitorPhase2Current_THDPercent =
      folly::Endian::big(*capacitorPhase2Current_THDPercent);
  *capacitorPhase3Current_THDPercent =
      folly::Endian::big(*capacitorPhase3Current_THDPercent);
  *powerFactor_OverallThreePhase =
      folly::Endian::big(*powerFactor_OverallThreePhase);
  *powerFactor_Fundamental_OverallThreePhase =
      folly::Endian::big(*powerFactor_Fundamental_OverallThreePhase);
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
  *capacitorOverallInjectedReactivePower_Fundamental =
      folly::Endian::big(*capacitorOverallInjectedReactivePower_Fundamental);
  faultData.bigEndian();
  auxFnData.bigEndian();
}

/* static */ IntervalData128 IntervalData128::fromByteStream(
    std::string_view data) {
  if (data.size() != sizeof(IntervalData128)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into IntervalData128 of size {}",
        data.size(), sizeof(IntervalData128)));
  }

  IntervalData128 result;
  std::memcpy(&result, data.data(), sizeof(IntervalData128));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y