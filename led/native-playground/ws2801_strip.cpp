#include "ws2801_strip.h"

using std::size_t;
using std::vector;
using std::string;

using colour_code = std::array<uint8_t, 3>;

static constexpr colour_code BLACK{{0x00, 0x00, 0x00}};
static constexpr colour_code BLUE_VIOLET{{0x8a, 0x2b, 0xe2}};


namespace led { namespace chip {

ws2801_chip::ws2801_chip(const string &device_name) {}

void ws2801_chip::turn_leds_on(size_t led_count) {
  ;
}

void ws2801_chip::turn_leds_off(size_t led_count) {
  ;
}

void ws2801_chip::set_strip_colour(const vector<uint8_t> &pixels) {
  ;
}

} // namespace chip
} // namespace led
