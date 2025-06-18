# CommandParser Implementation

`CommandParser` interprets ASCII commands coming from the USB or ESP8266
interfaces and applies them to `DDSDriver` and `EEPROMManager`.

## API
- `begin(DDSDriver&, EEPROMManager&)` – stores pointers to the driver and
  EEPROM helpers used by the parser.
- `handleCommand(const String& cmd)` – executes a command and returns the
  firmware response string.

Supported commands now include `SF`, `GF`, `SW`, `GW`,
`SAVE`, `LOAD`, `STATUS` and `VERSION`. Parsing is case-sensitive and relies on
`std::strtoul` for numeric conversion. Responses use the `OK:`/`ERR:` scheme
from the command specification.

See `dev_tools/commandparser_example.cpp` for a usage snippet.

Progress logs `2025-06-18_16-55_root_agent_remediation.md` mention the initial
stub creation.
