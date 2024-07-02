
#include <type_traits>
#include <string_view>

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
} // namespace tas_powertek::spf21y