# esp_protocol_sync.md – ESP8266 Protocol Synchronisation

> Last updated: 2025-06-18
> Maintainer: esp_agent & protocol_agent

This document aligns the ESP8266 firmware behaviour with the ASCII protocol
definitions for DDS-Controller milestone **v0.4.0**.

## ESP subsystem summary
- **File**: `firmware/esp/main.ino`
- **Role**: UART bridge between the Arduino Due and optional Wi-Fi API.
- **Stack**: two UART ports at 115200 8N1, planned HTTP endpoints
  `/api/frequency`, `/api/status` and `/api/save`.
- **Framing**: lines terminated by `\n`; forwarded without parsing.
- **Retries/Timeouts**: none, relies on Serial buffers. The Due generates
  all `OK:` or `ERR:` responses.
- **Limitations**: no command validation, no heartbeat, no version check.

## Protocol command summary
The shared header `firmware/shared/commands.h` defines these tokens:

| Macro | Command | Arguments | Example Response |
|-------|---------|-----------|-----------------|
| `CMD_SET_FREQ` | `SF` | `<Hz>` | `OK:SETFREQ` |
| `CMD_GET_FREQ` | `GF` | – | `OK:FREQ <Hz>` |
| `CMD_SET_WAVE` | `SW` | `0\|1\|2` | `OK:SETWAVE` |
| `CMD_GET_WAVE` | `GW` | – | `OK:WAVE <id>` |
| `CMD_OUTPUT_ON` | `ON` | – | `OK` |
| `CMD_OUTPUT_OFF` | `OFF` | – | `OK` |
| `CMD_SAVE` | `SAVE` | `[slot]` | `OK:SAVE` |
| `CMD_LOAD` | `LOAD` | `[slot]` | `OK:LOAD` |
| `CMD_DELETE` | `DELETE` | `<slot>` | `OK:DELETE` |

Additional parser-only commands:
- `STATUS` → `OK:FREQ <Hz> WAVE <id>`
- `VERSION` → `OK:VERSION <ver>`

## Ambiguities
- `STATUS` and `VERSION` lack constants in `commands.h`.
- Output on/off responses are plain `OK` with no token.

## Alignment proposal
- Keep newline-delimited ASCII with `OK:`/`ERR:` prefixes.
- Add `CMD_STATUS` and `CMD_VERSION` macros for completeness.
- Implement a heartbeat and optional version negotiation in later revisions.

## Test coverage
- Firmware command parsing tested under `tests/firmware/`.
- CLI interaction tested with stubs in `tests/cli/`.
- GUI tests run in stub mode due to network limits.
- No dedicated ESP integration tests yet; planned for v0.4.0.
