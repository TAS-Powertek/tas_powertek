#include "Enums.h"

namespace tas_powertek::spf21y {

template <>
std::string_view toString(DataType dataType) {
  switch (dataType) {
    case DataType::FAULT:
      return "Fault/Event";
    case DataType::INTERVAL:
      return "Interval";
    case DataType::DAILY:
      return "Daily";
    case DataType::USER_SETTINGS:
      return "User Settings";
    case DataType::REAL_TIME:
      return "Real Time";
    case DataType::UNKNOWN:
      return "(Error) Unknown";
  }
}
}  // namespace tas_powertek::spf21y