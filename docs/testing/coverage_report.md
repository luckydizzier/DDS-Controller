# Test Coverage Report

The test suite covers firmware logic and the PC tools. Short command handling
is verified across all layers.

- **Firmware**: unit tests for `DDSDriver`, `CommandParser` and `MenuSystem`
  (about 60% line coverage after v0.4.0 additions).
- **CLI**: `ddsctl` command parsing with mocked serial communication. Coverage
  increased to roughly 65% with new ESP and config tests.
- **GUI**: Fyne-based window interaction using a mock `SerialBridge`; these tests
  currently fail to run in CI due to blocked module downloads.

Basic preset storage and menu actions are now covered, though EEPROM failures remain untested.
