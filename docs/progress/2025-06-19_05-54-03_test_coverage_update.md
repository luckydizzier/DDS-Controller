# Test Coverage Update Log – 2025-06-19 05:54:03 CEST

- Added new unit tests for firmware modules covering DDSDriver frequency/waveform setters, CommandParser ESP commands, and MenuSystem actions.
- Expanded `tests/cli/test_ddsctl.py` with OTA failure handling, send helper checks, ESP warning output, and missing config detection.
- Generated coverage reports via `go test -tags=fyne_stub -coverprofile=coverage.out`.
- Current coverage roughly doubled to ~60% across firmware and CLI packages.
