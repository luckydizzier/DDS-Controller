# DDS Web + Local Controller – Arduino Due

DDS-Controller is a modular system for driving an AD9850 Direct Digital Synthesizer. It runs on an **Arduino Due** with an LCD Keypad Shield for local control and communicates with an **ESP8266-01** module for Wi-Fi access.

The project is fully documented in `docs/` and follows the architecture described in [architecture_overview.md](docs/design/architecture_overview.md).

## Features

- Local menu navigation on the LCD shield
- Remote commands over Wi-Fi (ASCII or REST)
- Configuration stored in 24LC256 EEPROM
- Cross-platform CLI and experimental GUI tools

## Directory Overview

- `firmware/` – Arduino Due and ESP8266 source code
- `pc/` – CLI (`ddsctl.py`) and Go GUI
- `protocol/` – ASCII, REST and JSON formats
- `dev_tools/` – small helper programs
- `tests/` – unit tests for firmware, CLI and GUI
- `logs/` – audit logs created by agents
- `docs/` – design documents and user guides

## Quick Start

### Firmware
1. Open `firmware/due/main.ino` in the Arduino IDE and flash it to the Due.
2. Build and flash `firmware/esp/main.ino` to the ESP8266.

### CLI example
```bash
$ python pc/cli/ddsctl.py setfreq 1000000
OK
```

### GUI example
```bash
$ cd pc/gui
$ go run .
```

## Diagram
A system diagram will be added here.

## License

This project is licensed under the MIT license.

