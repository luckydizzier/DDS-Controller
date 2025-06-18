# main.ino

`firmware/due/main.ino` contains the Arduino Due entry point. The sketch initialises all firmware modules and starts the runtime loop used both for local control and for commands coming through the ESP8266 bridge.

During `setup()` it creates `LiquidCrystal`, `ButtonManager`, `EEPROMManager`, `DDSDriver`, `MenuSystem` and `CommandParser` objects. USB and UART serial ports are configured and the DDS output control pin is set to a safe state.

The `loop()` function updates the menu system and checks the two serial ports for incoming commands. Each command is parsed by `CommandParser` and the response is sent back on the originating interface, enabling transparent USB or WiFi operation.

Output on/off actions are handled via `MenuSystem` by toggling `OUTPUT_CONTROL_PIN`.
