#ifndef COLOUR_H__
#define COLOUR_H__

#include "global.h"

namespace led {

enum class led_chip {
  ws2801
};

struct colour_strip {
  virtual ~colour_strip() = default;

  virtual void turn_leds_on(std::size_t led_count) = 0;
  virtual void turn_leds_off(std::size_t led_count) = 0;
  virtual void set_strip_colour(const std::vector<uint8_t> &pixels) = 0;

  static std::unique_ptr<colour_strip> create_strip(led_chip type);
};

}

#endif // COLOUR_H__
