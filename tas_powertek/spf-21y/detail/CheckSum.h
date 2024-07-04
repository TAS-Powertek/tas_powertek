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
  CheckSum(const CheckSum&) = delete;
  CheckSum(CheckSum&&) noexcept = default;
  CheckSum& operator=(const CheckSum&) = delete;
  CheckSum& operator=(CheckSum&&) noexcept = default;
  ~CheckSum() = default;

  static inline CheckSum compute(std::string_view data) {
    TUnderlying sum = std::accumulate(data.begin(), data.end(), TUnderlying{});
    return CheckSum(TUnderlying{} - sum);
  }
  TUnderlying underlying() const { return underlying_; }
  bool verify(std::string_view data) {
    TUnderlying sum = std::accumulate(data.begin(), data.end(), TUnderlying{});
    return static_cast<TUnderlying>(underlying_ + sum) == TUnderlying{};
  }

 private:
  TUnderlying underlying_;
};

using CheckSum16 = CheckSum<uint16_t>;
}  // namespace tas_powertek::spf21y::detail