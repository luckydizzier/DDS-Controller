# CommandParser Implementation

`CommandParser` provides a tiny ASCII command handler for the Arduino firmware.
It is used by both the USB and ESP8266 serial interfaces.

## API
- `begin(DDSDriver&, EEPROMManager&)` – stores pointers to the driver and EEPROM
  helpers used by the parser.
- `handleCommand(const String& cmd)` – interprets a single line without the
  newline character.

The implementation currently supports `SETFREQ` and `GETFREQ` as defined in
`docs/dev_protocols/command_spec.md`. Additional commands can be added following
that specification. All parsing is case-sensitive and relies on `std::strtoul`
for numeric conversion.

Progress logs `2025-06-18_16-55_root_agent_remediation.md` mention the initial
stub creation.
