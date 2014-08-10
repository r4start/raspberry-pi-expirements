#include "global.h"

#include "colour.h"
#include "ws2801_strip.h"

using std::unique_ptr;
using std::logic_error;

namespace led {

unique_ptr<colour_strip> colour_strip::create_strip(led_chip type) {
  switch (type) {
    case led_chip::ws2801:
      return unique_ptr<chip::ws2801_chip>{new chip::ws2801_chip{}};
    default:
      throw logic_error{"Unimplemented chip!"};
  }
}

} // namespace led
