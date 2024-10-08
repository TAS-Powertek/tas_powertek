#pragma once
#include <string_view>
#include <type_traits>

namespace tas_powertek::spf21y {
enum class DataType {
  UNKNOWN = 0,
  EVENT,
  INTERVAL_64,
  INTERVAL_128,
  INTERVAL_256,
  INTERVAL_512,
  DAILY,
  USER_SETTINGS,
  REAL_TIME_64,
  REAL_TIME_128,
  REAL_TIME_256,
  REAL_TIME_512,
};

template <typename T>
  requires(std::is_enum_v<T>)
std::string_view toString(T enumVal);

template <>
std::string_view toString(DataType datatype);
}  // namespace tas_powertek::spf21y