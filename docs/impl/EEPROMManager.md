# EEPROMManager Implementation

`EEPROMManager` handles persistent configuration stored in the external 24LC256
EEPROM. The memory layout is defined in `firmware/due/EEPROMMap.h` and documented
in `docs/design/storage_map.md`.

## Public API
- `begin()` – initialises the I²C interface via `Wire`.
- `saveFrequency(uint32_t)` / `loadFrequency()` – store or retrieve the last
  used frequency.
- `saveWaveform(uint8_t)` / `loadWaveform()` – same for waveform selection.
- `savePreset(id, freq, wave)` / `loadPreset(id, freq, wave)` – manage five
  preset slots (`EEPROM_PRESET_COUNT`).
- `deletePreset(id)` – clear a preset slot.

## Internal Helpers
`writeBytes()` and `readBytes()` perform byte level access to the EEPROM and
include a short delay after each write cycle. All addresses are 16‑bit and
little endian as documented in the progress logs
`2025-06-18_05-44-35_storage_agent.md` and
`2025-06-18_06-52-46_storage_agent_layout.md`.
