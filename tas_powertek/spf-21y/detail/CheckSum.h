#pragma once
#include <numeric>
#include <string_view>

#include "folly/logging/xlog.h"

namespace tas_powertek::spf21y::detail {

template <typename TUnderlying>
  requires std::unsigned_integral<TUnderlying>
class CheckSum {
 public:
  explicit CheckSum(TUnderlying underlying) : underlying_(underlying) {}
  CheckSum() = default;
  CheckSum(const CheckSum&) = default;
  CheckSum(CheckSum&&) noexcept = default;
  CheckSum& operator=(const CheckSum&) = default;
  CheckSum& operator=(CheckSum&&) noexcept = default;
  ~CheckSum() = default;

  static inline CheckSum compute(std::string_view data) {
    TUnderlying sum = accumulate(data);
    return CheckSum(TUnderlying{} - sum);
  }
  TUnderlying underlying() const { return underlying_; }
  bool verify(std::string_view data) {
    TUnderlying sum = accumulate(data);
    return static_cast<TUnderlying>(underlying_ + sum) == TUnderlying{};
  }

  auto operator<=>(const CheckSum&) const noexcept = default;

  std::string toString() const {
    std::string result;
    result.reserve(sizeof(uint16_t));
    uint16_t bigEndianUnderlying = folly::Endian::big(underlying());
    std::array<char, sizeof(uint16_t)>& asArray =
        reinterpret_cast<std::array<char, sizeof(uint16_t)>&>(
            bigEndianUnderlying);
    for (char c : asArray) {
      result.append(1, c);
    }

    return result;
  }

 private:
  static TUnderlying accumulate(std::string_view data) {
    return std::accumulate(
        data.begin(), data.end(), TUnderlying{},
        [](TUnderlying acc, char c) { return acc + static_cast<uint8_t>(c); });
  }
  TUnderlying underlying_;
};

using CheckSum16 = CheckSum<uint16_t>;
static_assert(std::is_standard_layout_v<CheckSum16>);
static_assert(sizeof(CheckSum16) == 2);
}  // namespace tas_powertek::spf21y::detail