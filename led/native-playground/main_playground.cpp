#include <iostream>
#include <fstream>
#include <array>

#include <cstdint>

using std::cout;
using std::endl;
using std::ofstream;

using colour_code = std::array<uint8_t, 3>;

static constexpr colour_code BLUE_VIOLET{ {0x8a, 0x2b, 0xe2} };

int main(int argc, char *argv[]) {
  ofstream spi_dev{"/dev/spidev0.0", ofstream::binary | ofstream::out};

  cout << spi_dev.is_open() << endl;

  spi_dev.close();
}
