# Hardware Connection Map

This file lists the recommended wiring between the Arduino Due, AD9850, and ESP8266-01 peripherals. It mirrors the table in `docs/hardware/pinmap.md` and can be customised through `config/pins.conf`.

See also:
- `docs/config/pins.conf` – editable pin assignments
- `docs/impl/ota_update.md` – OTA flashing procedure

| Peripheral | Signal | Due Pin |
|------------|-------|--------|
| AD9850     | WCLK  | 10 |
| AD9850     | FQUD  | 11 |
| AD9850     | DATA  | 12 |
| AD9850     | RESET | 13 |
| ESP8266-01 | RX    | 20 |
| ESP8266-01 | TX    | 21 |
| ESP8266-01 | GPIO2 | 24 |
| DDS Output | CTRL  | 25 |
