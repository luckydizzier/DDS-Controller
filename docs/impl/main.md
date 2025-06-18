# main.ino

The `firmware/due/main.ino` sketch will initialise all firmware modules and run
the main loop. At the moment it is only a placeholder. According to
`docs/design/architecture_overview.md` the final version should:

1. instantiate `DDSDriver`, `EEPROMManager`, `ButtonManager`, `MenuSystem` and
   `CommandParser`;
2. set up serial ports for USB and ESP8266 communication; and
3. call `MenuSystem.update()` repeatedly inside `loop()`.
