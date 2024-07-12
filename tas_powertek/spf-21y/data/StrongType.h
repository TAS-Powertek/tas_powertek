#pragma once

#include <folly/Portability.h>

#include <chrono>
#include <cstdint>

namespace tas_powertek::spf21y {

namespace detail {
template <typename T, typename TTag>
  requires std::is_standard_layout_v<T>
class strong_type {
 public:
  T& operator*() { return value; }
  const T& operator*() const { return value; }
  auto operator<=>(const strong_type&) const noexcept = default;

 private:
  T value;
} FOLLY_PACK_ATTR;
}  // namespace detail

class amp : public detail::strong_type<float, amp> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(amp) == 4);
static_assert(std::is_standard_layout_v<amp>);

class hertz : public detail::strong_type<float, hertz> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(hertz) == 4);
static_assert(std::is_standard_layout_v<hertz>);

class volt : public detail::strong_type<float, volt> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(volt) == 4);
static_assert(std::is_standard_layout_v<volt>);

class percent : public detail::strong_type<uint8_t, percent> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(percent) == 1);
static_assert(std::is_standard_layout_v<percent>);

class watt : public detail::strong_type<float, watt> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(watt) == 4);
static_assert(std::is_standard_layout_v<watt>);

class var : public detail::strong_type<float, var> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(var) == 4);
static_assert(std::is_standard_layout_v<var>);

class va : public detail::strong_type<float, va> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(va) == 4);
static_assert(std::is_standard_layout_v<va>);

class pf : public detail::strong_type<float, pf> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(pf) == 4);
static_assert(std::is_standard_layout_v<pf>);

class dpf : public detail::strong_type<float, dpf> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(dpf) == 4);
static_assert(std::is_standard_layout_v<dpf>);

class celsius : public detail::strong_type<float, celsius> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(celsius) == 4);
static_assert(std::is_standard_layout_v<celsius>);

class kwh : public detail::strong_type<uint64_t, kwh> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(kwh) == 8);
static_assert(std::is_standard_layout_v<kwh>);

class kvarh : public detail::strong_type<uint64_t, kvarh> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(kvarh) == 8);
static_assert(std::is_standard_layout_v<kvarh>);

class kvah : public detail::strong_type<uint64_t, kvah> {
} FOLLY_PACK_ATTR;
static_assert(sizeof(kvah) == 8);
static_assert(std::is_standard_layout_v<kvah>);

template <size_t kSize>
class fixed_sized_string
    : public detail::strong_type<std::array<char, kSize>,
                                 fixed_sized_string<kSize>> {
 public:
  operator std::string_view() const {
    auto begin = (**this).begin();
    for (size_t i = 0; i < kSize; i++) {
      if ((**this)[i] == '\x00') {
        return std::string_view(begin, begin + i);
      }
    }
    return std::string_view(begin, begin + kSize);
  }
} FOLLY_PACK_ATTR;
}  // namespace tas_powertek::spf21y
