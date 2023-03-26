#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

#include "../hardware_map.hpp"

hal::status application(hardware_map& p_map)
{
  using namespace std::chrono_literals;
  using namespace hal::literals;

  auto& clock = *p_map.clock;
  auto& console = *p_map.console;

  hal::print(console, "Demo Application Starting...\n\n");

  while (true) {
    HAL_CHECK(hal::delay(clock, 500ms));
    hal::print(console, "Hello, world\n");
  }

  return hal::success();
}
