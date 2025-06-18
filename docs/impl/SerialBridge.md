# SerialBridge Implementation

`SerialBridge.go` provides minimal helpers for opening a serial port from the Go
GUI. It wraps the `tarm/serial` package and currently exposes only the
`openPort(name, baud)` function which returns a `serial.Port` object.

The bridge will be used by `MainWindow.go` to forward commands to the Arduino Due
using the ASCII protocol defined in `docs/dev_protocols/command_spec.md`. The
implementation is still a placeholder without error handling or message parsing.
