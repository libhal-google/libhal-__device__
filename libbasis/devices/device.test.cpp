#include "device.hpp"

#include <libcore/testing/testing_frameworks.hpp>

namespace sjsu::basis
{
TEST_CASE("Testing Placeholder Device Driver")
{
  DeviceDriver test_subject;

  // Setup for all sections ...
  SECTION("Placeholder test section")
  {
    // Test a portion of the device driver here ...
  }

  SECTION("DeviceDriver::SetValue1() && DeviceDriver::GetValue()")
  {
    test_subject.SetValue1(5);
    CHECK(5 == test_subject.GetValue());

    test_subject.SetValue1(-3445);
    CHECK(-3445 == test_subject.GetValue());

    CHECK_THROWS_AS(test_subject.SetValue1(101), std::range_error);

    // Should not have been updated and should equal the previous value
    CHECK(-3445 == test_subject.GetValue());
  }
}
}  // namespace sjsu::basis
