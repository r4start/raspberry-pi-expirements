#ifndef COLOUR_H__
#define COLOUR_H__

#include <memory>
#include <vector>
#include <string>

#include <cstdint>

namespace led {

enum class led_chip {
  ws2801
};

struct colour_strip {
  virtual ~colour_strip() = default;

  virtual void turn_leds_on(std::size_t led_count) = 0;
  virtual void turn_leds_off(std::size_t led_count) = 0;

  /*!
   * pixels is in RGB format.
   */
  virtual void set_strip_colour(const std::vector<uint8_t> &pixels) = 0;

  static std::unique_ptr<colour_strip> create_strip(
                                                led_chip type,
                                                const std::string &device_name);
};


struct rgb_colours {
  using colour_code = std::array<uint8_t, 3>;

  static constexpr colour_code WHITE{{0xff, 0xff, 0xff}};
  static constexpr colour_code BLACK{{0x00, 0x00, 0x00}};
  static constexpr colour_code BLUE_VIOLET{{0x8a, 0x2b, 0xe2}};
};


}

#endif // COLOUR_H__
