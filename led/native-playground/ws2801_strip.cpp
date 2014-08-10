#include <cstring>

#include "ws2801_strip.h"

using std::size_t;
using std::vector;
using std::string;
using std::fstream;
using std::runtime_error;

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

  vector<uint8_t> led_array(led_count * 3);
  memset(led_array.data(), 0xff, led_count * 3);

  device_.write(reinterpret_cast<char *>(led_array.data()), led_count);
  device_.flush();
}

void ws2801_chip::turn_leds_off(size_t led_count) {
  if (!led_count) {
    throw runtime_error{"Bad led count!"};
  }

  vector<uint8_t> led_array(led_count * 3);
  memset(led_array.data(), 0x00, led_count * 3);

  device_.write(reinterpret_cast<char *>(led_array.data()), led_count);
  device_.flush();
}

void ws2801_chip::set_strip_colour(const vector<uint8_t> &pixels) {
  if (pixels.empty()) {
    throw runtime_error{"Pixels can not be empty!"};
  }

  device_.write(reinterpret_cast<const char *>(pixels.data()), pixels.size());
  device_.flush();
}

} // namespace chip
} // namespace led
