#include "IntervalData64.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
void IntervalData64::bigEndian() {
  time.bigEndian();
  *supplyFrequency = folly::Endian::big(*supplyFrequency);
  *averagePhaseToNeutralVolage_RMS =
      folly::Endian::big(*averagePhaseToNeutralVolage_RMS);
  *averagePhaseToNeutralVoltage_Fundamental =
      folly::Endian::big(*averagePhaseToNeutralVoltage_Fundamental);
  *averagePhaseToNeutralVolage_THD =
      folly::Endian::big(*averagePhaseToNeutralVolage_THD);
  *averagePhaseToPhaseVoltage_RMS =
      folly::Endian::big(*averagePhaseToPhaseVoltage_RMS);
  *averagePhaseToPhaseVoltage_Fundamental =
      folly::Endian::big(*averagePhaseToPhaseVoltage_Fundamental);
  *averagePhaseCurrent_RMS = folly::Endian::big(*averagePhaseCurrent_RMS);
  *averagePhaseCurrent_THD = folly::Endian::big(*averagePhaseCurrent_THD);
  *overall3PhActivePower_Fundamental =
      folly::Endian::big(*overall3PhActivePower_Fundamental);
  *overall3PhReactivePower_Fundamental =
      folly::Endian::big(*overall3PhReactivePower_Fundamental);
  *powerFactor_Fundamental_OverallThreePhase =
      folly::Endian::big(*powerFactor_Fundamental_OverallThreePhase);
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
  *capacitorAverageCurrent_THD =
      folly::Endian::big(*capacitorAverageCurrent_THD);
  faultData.bigEndian();
  auxFnData.bigEndian();
}

/* static */ IntervalData64 IntervalData64::fromByteStream(
    std::string_view data) {
  if (data.size() != sizeof(IntervalData64)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into IntervalData64 of size {}",
        data.size(), sizeof(IntervalData64)));
  }

  IntervalData64 result;
  std::memcpy(&result, data.data(), sizeof(IntervalData64));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y