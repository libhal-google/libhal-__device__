#pragma once

#include <exception>
#include <libcore/module.hpp>

/// Delete this file in a real library implementation. The following code is
/// here to verify that libbasis's CI is working correctly
class DeviceDriver : sjsu::Module<>
{
 public:
  /// Default value for DeviceDriver objects
  constexpr static int kDefaultValue = 15;

  /// Set the value of the device driver
  ///
  /// @param new_value1 - a new value to assign to value, must be below 100
  /// @throws std::range_error if new_value is above 100
  void SetValue1(int new_value1)
  {
    if (new_value1 > 100)
    {
      throw std::range_error("This value is WAY too big!");
    }
    value = new_value1;
  }

  /// @returns value of device driver
  auto GetValue()
  {
    return value;
  }

 private:
  int value = kDefaultValue;
};
