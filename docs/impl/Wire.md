# Wire Mock Implementation

The files `firmware/due/mocks/Wire.h` and `Wire.cpp` provide a tiny replacement
for the Arduino `Wire` (I²C) library. The `TwoWire` class implements the methods
used by `EEPROMManager` such as `begin()`, `beginTransmission()`, `write()`,
`endTransmission()`, `requestFrom()`, `available()` and `read()`.

All methods are empty and return fixed values; they allow the firmware to be
compiled on a PC without linking against the real Arduino core. A single global
instance `Wire` is defined in `Wire.cpp`.
