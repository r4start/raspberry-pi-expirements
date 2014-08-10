#include <iostream>

#include "colour.h"

using std::cout;
using std::endl;
using std::string;
using std::exception;

static constexpr uint16_t TEST_LED_COUNT{90};

static const string DEVICE_NAME{"/dev/spidev0.0"};

int main(int argc, char *argv[]) {
  try {
    auto &&chip =
        led::colour_strip::create_strip(led::led_chip::ws2801, DEVICE_NAME);

    chip->turn_leds_on(1);
    chip->turn_leds_off(1);
  } catch (const exception &ex) {
    cout << ex.what() << endl;
  }

  return 0;
}
