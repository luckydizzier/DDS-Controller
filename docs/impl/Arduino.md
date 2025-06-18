# Arduino Mock Implementation

`firmware/due/mocks/Arduino.h` provides a minimal subset of the Arduino API so that the
firmware sources can be compiled on a desktop PC. It defines common macros like
`HIGH`, `LOW`, `INPUT` and `OUTPUT` and implements the basic functions used by the
project:

- `pinMode()`
- `digitalWrite()`
- `analogRead()`
- `millis()`
- `delay()` / `delayMicroseconds()`

All functions are empty inline stubs that return default values. They allow unit
or build tests to run without access to the real microcontroller environment.
No timing or I/O behaviour is emulated, therefore the mock should only be used
for compilation tests and not for functional verification.

Dependencies: standard C++ headers only.
