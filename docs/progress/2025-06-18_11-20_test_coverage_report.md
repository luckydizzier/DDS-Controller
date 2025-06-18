# Test Coverage Report
Date: 2025-06-18 11:20 CEST

## Coverage Summary

- `go test ./...` failed due to blocked module downloads. No Go coverage produced.
- `pytest` suite executed 2 CLI tests successfully.
- Firmware C++ test built and ran without output; no coverage metric available.

## Untested Functions

### CLI
- `preset-save` and `preset-load` branches in `ddsctl.main`
- Invalid frequency handling in `ddsctl.main` and `send` errors

### Firmware
- All `EEPROMManager` routines (save/load/preset)
- `CommandParser` commands: `GF`, `SW`, `GW`, `SAVE`, `LOAD`, `STATUS`, `VERSION`
- `MenuSystem` actions for output control and preset management

### GUI
- `SerialBridge` error paths and close semantics
- Button callbacks for Set/Read operations

## Recommendations

- Extend CLI tests to cover presets and invalid input.
- Mock EEPROM to test read/write logic.
- Cover remaining `CommandParser` branches and MenuSystem actions.
- Use `fyne/test` for GUI Set/Read buttons once dependencies are available.
- Provide vendored Go modules to unblock CI coverage.
