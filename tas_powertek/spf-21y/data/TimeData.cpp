
#include "TimeData.h"

#include <date/tz.h>
#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
namespace {
// By convention, all timestamps from devices are against IST
constexpr std::string_view kIstTimeZone = "Asia/Kolkata";
}  // namespace

std::chrono::sys_seconds TimeData::toTimePoint() const {
  std::chrono::year_month_day ymd{std::chrono::year(year),
                                  std::chrono::month(month),
                                  std::chrono::day(day_of_month)};
  date::local_seconds localTime{
      std::chrono::local_days{ymd}.time_since_epoch() +
      std::chrono::hours(hour) + std::chrono::minutes(min) +
      std::chrono::seconds(sec)};
  date::zoned_time zt(kIstTimeZone, localTime);
  return zt.get_sys_time();
}

void TimeData::bigEndian() {
  // Although 1 byte integers don't have endianness, we include them for
  // completeness
  sec = folly::Endian::big(sec);
  min = folly::Endian::big(min);
  hour = folly::Endian::big(hour);
  day_of_month = folly::Endian::big(day_of_month);
  month = folly::Endian::big(month);
  year = folly::Endian::big(year);
}

/* static */ TimeData TimeData::fromByteStream(std::string_view data) {
  if (data.size() != sizeof(TimeData)) {
    throw std::runtime_error(fmt::format(
        "Cannot deserialize data of size {} into TimeData of size {}",
        data.size(), sizeof(TimeData)));
  }
  TimeData result;
  std::memcpy(&result, data.data(), sizeof(TimeData));
  result.bigEndian();
  return result;
}
}  // namespace tas_powertek::spf21y