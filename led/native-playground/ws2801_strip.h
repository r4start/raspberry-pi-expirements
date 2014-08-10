#ifndef WS2801_STRIP_H__
#define WS2801_STRIP_H__

#include "colour.h"

namespace led { namespace chip {

class ws2801_chip : public virtual colour_strip {
public:
  explicit ws2801_chip(const std::string &device_name);
  ~ws2801_chip() override = default;

  ws2801_chip(const ws2801_chip &) = delete;
  ws2801_chip &operator=(const ws2801_chip &) = delete;

  void turn_leds_on(std::size_t led_count) override;
  void turn_leds_off(std::size_t led_count) override;
  void set_strip_colour(const std::vector<uint8_t> &pixels) override;
};

}
}

#endif // WS2801_STRIP_H__
