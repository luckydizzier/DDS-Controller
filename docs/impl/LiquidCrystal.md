# LiquidCrystal Mock Implementation

`firmware/due/mocks/LiquidCrystal.h` provides a bare bones stand‑in for the
Arduino `LiquidCrystal` class. It implements the constructor and methods used by
`MenuSystem` such as `begin()`, `clear()`, `setCursor()`, and `print()`.

Each function is empty and performs no I/O. The mock exists so that the firmware
can be compiled and linked on a PC during `make test_build` without an actual
LCD attached. No cursor state or display content is tracked.
