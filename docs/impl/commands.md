# commands.h

`firmware/shared/commands.h` defines short ASCII command strings that are shared
between the firmware and the PC tools. The table below lists the currently
implemented constants and their meaning.

| Constant | Command | Description | Example Request | Example Response |
| --- | --- | --- | --- | --- |
| `CMD_SET_FREQ` | `SF` | Set frequency in Hz as integer | `SF 1000000` | `OK:SETFREQ` |
| `CMD_GET_FREQ` | `GF` | Query current frequency | `GF` | `OK:FREQ 1000000` |
| `CMD_SET_WAVE` | `SW` | Set waveform index (0-2) | `SW 1` | `OK:SETWAVE` |
| `CMD_GET_WAVE` | `GW` | Query current waveform | `GW` | `OK:WAVE 1` |
| `CMD_OUTPUT_ON` | `ON` | Enable DDS output | `ON` | `OK` |
| `CMD_OUTPUT_OFF` | `OFF` | Disable DDS output | `OFF` | `OK` |

Commands for saving or loading presets continue to use the words `SAVE` and
`LOAD`. The constants keep request strings short while responses still use the
human-readable tokens documented in `command_spec.md`.

Hardware pin names referenced here match the tables in
[`docs/configuration/pins.md`](../configuration/pins.md).

## ESP Interface Commands

These commands target the optional ESP8266-01 WiFi bridge. All ESP commands
start with the letter `E` to distinguish them from the regular DDS commands.

| Constant | Command | Description |
| --- | --- | --- |
| `CMD_ESP_ON` | `EON` | Enable the ESP bridge |
| `CMD_ESP_OFF` | `EOF` | Disable the ESP bridge |
| `CMD_ESP_STATUS` | `EST` | Query ESP status |
| `CMD_ESP_VERSION` | `EVR` | Request ESP firmware version |
| `CMD_ESP_MODE` | `EMD` | Set bridge mode / argument required |
| `CMD_ESP_LED_ON` | `EL1` | Turn WiFi status LED on |
| `CMD_ESP_LED_OFF` | `EL0` | Turn WiFi status LED off |

General diagnostic commands `CMD_STATUS` and `CMD_VERSION` are also available
and apply to the Arduino Due firmware itself.
