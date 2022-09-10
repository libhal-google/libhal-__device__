#pragma once

#include <libhal/adc/interface.hpp>

namespace hal::basis {
class adc : public hal::adc
{
private:
  result<float> driver_read() noexcept override
  {
    return 1.0f;
  }
}
}  // namespace hal::basis
