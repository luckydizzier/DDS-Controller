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
