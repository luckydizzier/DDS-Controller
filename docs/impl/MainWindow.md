# MainWindow Implementation

`pc/gui/MainWindow.go` provides a small Fyne application for interacting with
the firmware over USB. It now exposes basic widgets to set and read the
frequency and waveform using `SerialBridge`.

## Features

- Port entry and connect button (defaults to `/dev/ttyACM0`).
- Frequency and waveform controls with `Set` and `Read` actions.
- Live status labels showing the last response from the firmware.

The application relies on `SerialBridge.go` for communication. The mock-ups in
`docs/design/pc_ui_mockups.md` served as reference for this initial
implementation.

Version 0.4.0 introduces a small status label showing whether the ESP8266 is
present and if OTA mode is active. This information is read from
`config/pins.conf` at startup and shown below the connection status.
