# SerialBridge Implementation

`SerialBridge.go` now defines a `SerialBridge` struct that wraps the
`tarm/serial` package. It manages the port handle with a small mutex and offers
three methods:

- `Open(name, baud)` – open the serial device.
- `Close()` – close if open.
- `Send(cmd)` – write a line and read the response.

This is used by the GUI to interact with the firmware reliably.
