# Test Coverage Report

The initial test suite covers basic functionality across firmware, CLI and GUI layers.

- **Firmware**: simple unit tests for `DDSDriver`, `CommandParser` and `MenuSystem` (approx. 30% of lines).
- **CLI**: `ddsctl` command parsing using mocked serial communication.
- **GUI**: window interaction through Fyne test utilities with a mock `SerialBridge`.

Known edge cases such as EEPROM failures and invalid menu navigation remain untested for now.
