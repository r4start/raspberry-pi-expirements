#!/usr/bin/env python

import re

if __name__ == '__main__':
  result = re.search(r"^([A-Z]+)\ *=\ *bytearray\(b'\\x([0-9A-Fa-f]{2})\\x([0-9A-Fa-f]{2})\\x([0-9A-Fa-f]{2})'\)", r"CORNFLOWERBLUE = bytearray(b'\x64\x95\xed')")
  print(result.group(0))
  print(result.group(1))
  print(result.group(2))
  print(result.group(3))
  print(result.group(4))
