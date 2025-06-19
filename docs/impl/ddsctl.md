# ddsctl Implementation

`ddsctl.py` is a command line helper for sending ASCII commands over a serial
port. The script now includes sub‑commands for setting and reading the
frequency, as well as saving and loading presets.

The tool is described in `docs/design/pc_ui_mockups.md` and shares the command
set with the GUI. It opens the serial port using `pyserial`, sends the chosen
command, waits for one line of response and prints it.

As of v0.4.0 the script loads `config/pins.conf` on startup. It prints the
current GPIO mapping and warns about missing or conflicting pin numbers. If the
ESP8266 is enabled, the OTA status from the config is reported before executing
any command.
