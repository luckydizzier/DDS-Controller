# Test Coverage Report

The test suite covers firmware logic and the PC tools. Short command handling
is verified across all layers.

- **Firmware**: unit tests for `DDSDriver`, `CommandParser` and `MenuSystem`
  (around 30% line coverage).
- **CLI**: `ddsctl` command parsing with mocked serial communication (new tests
  ensure `SF` and `GF` work).
- **GUI**: Fyne-based window interaction using a mock `SerialBridge`; these tests
  currently fail to run in CI due to blocked module downloads.

Known edge cases such as EEPROM failures and invalid menu navigation remain untested for now.
