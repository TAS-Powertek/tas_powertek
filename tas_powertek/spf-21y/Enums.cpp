
#include "Enums.h"

namespace tas_powertek::spf21y {

template <>
std::string_view toString(DataType dataType) {
  switch (dataType) {
    case DataType::EVENT:
      return "Event/Fault";
    case DataType::INTERVAL_64:
      return "Interval 64";
    case DataType::INTERVAL_128:
      return "Interval 128";
    case DataType::INTERVAL_256:
      return "Interval 256";
    case DataType::INTERVAL_512:
      return "Interval 512";
    case DataType::DAILY:
      return "Daily";
    case DataType::USER_SETTINGS:
      return "User Settings";
    case DataType::REAL_TIME:
      return "Real Time";
    case DataType::UNKNOWN:
      return "(Error) Unknown";
  }
  return "(Error) Out of enum range / corruption";
}
}  // namespace tas_powertek::spf21y