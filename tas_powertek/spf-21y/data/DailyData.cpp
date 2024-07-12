#include "DailyData.h"

#include <fmt/core.h>
#include <folly/lang/Bits.h>

#include <cstring>

namespace tas_powertek::spf21y {
void DailyData::bigEndian() {
  time.bigEndian();
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