#include "ws2801_strip.h"

using std::size_t;
using std::vector;
using std::string;
using std::fstream;
using std::runtime_error;

using colour_code = std::array<uint8_t, 3>;

static constexpr colour_code WHITE{{0xff, 0xff, 0xff}};
static constexpr colour_code BLACK{{0x00, 0x00, 0x00}};
static constexpr colour_code BLUE_VIOLET{{0x8a, 0x2b, 0xe2}};


namespace led { namespace chip {

ws2801_chip::ws2801_chip(const string &device_name)
  : device_{device_name} {

  if (!device_.is_open()) {
    throw runtime_error{"Unable to open device!"};
  }
}

ws2801_chip::~ws2801_chip() {
  device_.close();
}

void ws2801_chip::turn_leds_on(size_t led_count) {
  if (!led_count) {
    throw runtime_error{"Bad led count!"};
  }

  vector<uint8_t> led_array(led_count);
  for (size_t i = 0; i < led_count; ++i) {
    led_array[i] = WHITE[0];
    led_array[i + 1] = WHITE[1];
    led_array[i + 2] = WHITE[2];
  }

  device_.write(reinterpret_cast<char *>(led_array.data()), led_count);
  device_.flush();
}

void ws2801_chip::turn_leds_off(size_t led_count) {
  if (!led_count) {
    throw runtime_error{"Bad led count!"};
  }

  vector<uint8_t> led_array(led_count);
  for (size_t i = 0; i < led_count; ++i) {
    led_array[i] = BLACK[0];
    led_array[i + 1] = BLACK[1];
    led_array[i + 2] = BLACK[2];
  }

  device_.write(reinterpret_cast<char *>(led_array.data()), led_count);
  device_.flush();
}

void ws2801_chip::set_strip_colour(const vector<uint8_t> &pixels) {
  ;
}

} // namespace chip
} // namespace led
