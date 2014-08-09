#include <array>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>

#include <cstdint>

using std::cout;
using std::endl;
using std::thread;
using std::string;
using std::vector;
using std::ofstream;

// 90 leds

using colour_code = std::array<uint8_t, 3>;

using namespace std::chrono;

static constexpr colour_code BLUE_VIOLET{{0x8a, 0x2b, 0xe2}};

static constexpr uint16_t TEST_LED_COUNT{90};

static const string DEVICE_NAME{"/dev/spidev0.0"};

int main(int argc, char *argv[]) {
  ofstream spi_dev{DEVICE_NAME, ofstream::binary | ofstream::out};

  if (!spi_dev.is_open()) {
    cout << "Unable to open " << DEVICE_NAME << endl;
    return -1;
  }

  vector<uint8_t> led_array(TEST_LED_COUNT * 3);
  for (size_t i = 0; i < led_array.size(); i += 3) {
    led_array[i] = BLUE_VIOLET[0];
    led_array[i + 1] = BLUE_VIOLET[1];
    led_array[i + 2] = BLUE_VIOLET[2];
  }

  spi_dev.write(reinterpret_cast<char *>(led_array.data()), led_array.size());

  spi_dev.close();

  return 0;
}
