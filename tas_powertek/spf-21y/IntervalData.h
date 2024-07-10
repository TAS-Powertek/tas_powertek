#pragma once
#include "RecordData.h"

namespace tas_powertek::spf21y {
class IntervalData : public RecordData {
 public:
  IntervalType type() const;
};
}  // namespace tas_powertek::spf21y