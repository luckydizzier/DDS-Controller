# EEPROMMap Implementation

`EEPROMMap.h` defines the address layout used by `EEPROMManager`. The constants
mirror the table found in `docs/design/storage_map.md`.

```cpp
#define EEPROM_ADDR_FREQ      0x0000
#define EEPROM_ADDR_WAVEFORM  0x0004
#define EEPROM_ADDR_VERSION   0x0005
#define EEPROM_PRESET_START   0x0100
#define EEPROM_PRESET_SIZE    0x0080
#define EEPROM_PRESET_COUNT   5
```

The optional `Settings` struct packs frequency, waveform and a version byte into
a single record for preset storage. Any change in this map must stay in sync with
the design document and the progress logs that tracked its creation
(`2025-06-18_06-52-46_storage_agent_layout.md`).
