#include <libhal-tmpxxx/tmp102.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

#include "../hardware_map.hpp"

hal::status application(hardware_map& p_map)
{
  using namespace std::chrono_literals;
  using namespace hal::literals;

  auto& clock = *p_map.clock;
  auto& console = *p_map.console;
  auto& i2c = *p_map.i2c;

  hal::print(console, "tmp102 Application Starting...\n\n");
  auto tmp102 = HAL_CHECK(hal::tmpxxx::tmp102::create(i2c));

  while (true) {
    HAL_CHECK(hal::delay(clock, 500ms));
    hal::print(console, "Reading temperature... ");
    auto temperature = HAL_CHECK(tmp102.read()).temperature;
    hal::print<32>(console, "measured temperature = %f °C\n", temperature);
  }

  return hal::success();
}
