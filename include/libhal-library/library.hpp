#pragma once

#include <array>
#include <span>

#include <libhal-util/as_bytes.hpp>
#include <libhal-util/i2c.hpp>
#include <libhal/i2c.hpp>
#include <libhal/temperature_sensor.hpp>
#include <libhal/timeout.hpp>

namespace hal::tmpxxx {
class tmp102 : public hal::temperature_sensor
{
public:
  /// The device address when A0 is connected to GND.
  static constexpr hal::byte address_ground = 0b100'1000;
  /// The device address when A0 is connected to V+.
  static constexpr hal::byte address_voltage_high = 0b100'1001;
  /// The device address when A0 is connected to SDA.
  static constexpr hal::byte address_sda = 0b100'1010;
  /// The device address when A0 is connected to SCL.
  static constexpr hal::byte address_scl = 0b100'1011;

  /// The address of the read-only register containing the temperature data.
  static constexpr hal::byte temperature_register = 0x00;
  /// The address of the register used to configure the device.
  static constexpr hal::byte configuration_register = 0x01;

  /// The command to enable one-shot shutdown mode.
  static constexpr hal::byte one_shot_shutdown_mode = 0x81;

  static result<tmp102> create(hal::i2c& i2c,
                               hal::byte device_address = address_ground)
  {
    return tmp102(i2c, device_address);
  }

private:
  /// @param i2c The I2C peripheral used for communication with the device.
  /// @param device_address The device address of the sensor. The address is
  ///                       configured by physically modifying the connection of
  ///                       the P0 pin.
  explicit constexpr tmp102(hal::i2c& i2c, hal::byte device_address)
    : m_i2c(&i2c)
    , m_address(device_address)
  {
  }

  hal::result<temperature_sensor::read_t> driver_read() override
  {
    std::array<hal::byte, 1> payload{ temperature_register };
    constexpr float celsius_per_digit = 0.0625f;
    std::array<hal::byte, 2> buffer;

    HAL_CHECK(one_shot_shutdown());

    HAL_CHECK(hal::write_then_read(
      *m_i2c, m_address, payload, buffer, hal::never_timeout()));

    // The temperature value is from bits [15:3], with the rest being zeros
    // The MSB is received first in the byte.
    const int32_t temperature_reading = (buffer[0] << 4) | (buffer[1] >> 4);

    return temperature_sensor::read_t{
      .temperature =
        static_cast<float>(temperature_reading) * celsius_per_digit,
    };
  }

  /// Sets the device to use one-shot shutdown mode. This allows power to be
  /// conserved by putting the device in the shutdown state once a reading is
  /// obtained.
  status one_shot_shutdown()
  {
    std::array<hal::byte, 2> payload{ configuration_register,
                                      one_shot_shutdown_mode };
    return hal::write(*m_i2c, m_address, payload, hal::never_timeout());
  }

  /// The I2C peripheral used for communication with the device.
  hal::i2c* m_i2c;
  /// The configurable device address used for communication.
  hal::byte m_address;
};
}  // namespace hal::tmpxxx
