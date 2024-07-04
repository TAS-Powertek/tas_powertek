#pragma once
#include <string_view>
#include <type_traits>

namespace tas_powertek::spf21y {
enum class DataType {
  UNKNOWN = 0,
  FAULT,
  INTERVAL,
  DAILY,
  USER_SETTINGS,
  REAL_TIME,
};

template <typename T>
  requires(std::is_enum_v<T>)
std::string_view toString(T enumVal);

template <>
std::string_view toString(DataType datatype);
}  // namespace tas_powertek::spf21y