#include <iostream>
#include <thread>
#include <chrono>

#include "colour.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

namespace chrono = std::chrono;
namespace this_thread = std::this_thread;

static constexpr uint16_t TEST_LED_COUNT{90};

static const string DEVICE_NAME{"/dev/spidev0.0"};

int main(int argc, char *argv[]) {
  try {
    auto &&chip =
        led::colour_strip::create_strip(led::led_chip::ws2801, DEVICE_NAME);

    vector<uint8_t> leds(TEST_LED_COUNT * 3);
    leds[0] = led::rgb_colours::BLUE_VIOLET[0];
    leds[1] = led::rgb_colours::BLUE_VIOLET[1];
    leds[2] = led::rgb_colours::BLUE_VIOLET[2];

    chip->set_strip_colour(leds);
    this_thread::sleep_for(chrono::seconds(5));

    chip->turn_leds_off(TEST_LED_COUNT);

  } catch (const exception &ex) {
    cout << ex.what() << endl;
  }

  return 0;
}
