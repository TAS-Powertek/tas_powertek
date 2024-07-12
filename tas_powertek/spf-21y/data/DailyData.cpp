#include "DailyData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
void DailyData::bigEndian() {
  time.bigEndian();
  *maxPhase1ToNeutralVoltage_RMS =
      folly::Endian::big(*maxPhase1ToNeutralVoltage_RMS);
  *maxPhase2ToNeutralVoltage_RMS =
      folly::Endian::big(*maxPhase2ToNeutralVoltage_RMS);
  *maxPhase3ToNeutralVoltage_RMS =
      folly::Endian::big(*maxPhase3ToNeutralVoltage_RMS);
  *maxPhasesToNetralVoltage_THD =
      folly::Endian::big(*maxPhasesToNetralVoltage_THD);
  *maxPhase1ToPhase2Voltage_RMS =
      folly::Endian::big(*maxPhase1ToPhase2Voltage_RMS);
  *maxPhase2ToPhase3Voltage_RMS =
      folly::Endian::big(*maxPhase2ToPhase3Voltage_RMS);
  *maxPhase3ToPhase1Voltage_RMS =
      folly::Endian::big(*maxPhase3ToPhase1Voltage_RMS);
  *maxPhaseToPhaseVoltage_THD = folly::Endian::big(*maxPhaseToPhaseVoltage_THD);
  *maxPhase1Current_RMS = folly::Endian::big(*maxPhase1Current_RMS);
  *maxPhase2Current_RMS = folly::Endian::big(*maxPhase2Current_RMS);
  *maxPhase3Current_RMS = folly::Endian::big(*maxPhase3Current_RMS);
  *maxNeutralCurrent_RMS = folly::Endian::big(*maxNeutralCurrent_RMS);
  *maxPhase1Current_THD = folly::Endian::big(*maxPhase1Current_THD);
  *maxPhase2Current_THD = folly::Endian::big(*maxPhase2Current_THD);
  *maxPhase3Current_THD = folly::Endian::big(*maxPhase3Current_THD);
  *maxNeutralCurrent_THD = folly::Endian::big(*maxNeutralCurrent_THD);
  *maxCapacitorCurrent_THD = folly::Endian::big(*maxCapacitorCurrent_THD);
  *maxDemandOverallVA = folly::Endian::big(*maxDemandOverallVA);
  *maxDemandOverallWatt = folly::Endian::big(*maxDemandOverallWatt);
  for (var& v : capacitorBank_VAR) {
    *v = folly::Endian::big(*v);
  }
  *maxExternalTempPT100 = folly::Endian::big(*maxExternalTempPT100);
  *overallActiveEnergyGeneration_Negative =
      folly::Endian::big(*overallActiveEnergyGeneration_Negative);
  *overallActiveEnergyConsumption_Positive =
      folly::Endian::big(*overallActiveEnergyConsumption_Positive);
  *overallReactiveEnergyImport_Negative =
      folly::Endian::big(*overallReactiveEnergyImport_Negative);
  *overallReactiveEnergyExport_Positive =
      folly::Endian::big(*overallReactiveEnergyExport_Positive);
  *overallApparentEnergy = folly::Endian::big(*overallApparentEnergy);
  *capacitorReactiveFundamentalEnergyExported =
      folly::Endian::big(*capacitorReactiveFundamentalEnergyExported);
  for (uint32_t& c : capacitorUtilizationCounters) {
    c = folly::Endian::big(c);
  }
  numPowerInterruptions = folly::Endian::big(numPowerInterruptions);
  *maxPhasesToNetralVoltage_THDPercent =
      folly::Endian::big(*maxPhasesToNetralVoltage_THDPercent);
  *maxPhaseToPhaseVoltage_THDPercent =
      folly::Endian::big(*maxPhaseToPhaseVoltage_THDPercent);
  *maxPhaseCurrent_TDDPercent = folly::Endian::big(*maxPhaseCurrent_TDDPercent);
  *maxCapacitorPhaseCurrent_TDDPercent =
      folly::Endian::big(*maxCapacitorPhaseCurrent_TDDPercent);
}

/* static */ DailyData DailyData::fromByteStream(std::string_view data) {
  if (data.size() != sizeof(DailyData)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into DailyData of size {}",
        data.size(), sizeof(DailyData)));
  }

  DailyData result;
  std::memcpy(&result, data.data(), sizeof(DailyData));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y