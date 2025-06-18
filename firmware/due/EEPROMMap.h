#ifndef EEPROM_MAP_H
#define EEPROM_MAP_H

#ifdef ARDUINO
#include <Arduino.h>
#else
#include "mocks/Arduino.h"
#endif

#define EEPROM_I2C_ADDRESS 0x50

// Basic settings
#define EEPROM_ADDR_FREQ      0x0000
#define EEPROM_ADDR_WAVEFORM  0x0004
#define EEPROM_ADDR_VERSION   0x0005

// Reserved space for additional configuration fields
#define EEPROM_RESERVED_START 0x0006
#define EEPROM_RESERVED_END   0x00FF

// Preset storage
#define EEPROM_PRESET_START   0x0100
#define EEPROM_PRESET_SIZE    0x0080  // 128 bytes per preset
#define EEPROM_PRESET_COUNT   5

#define EEPROM_PRESET1_ADDR   (EEPROM_PRESET_START)
#define EEPROM_PRESET2_ADDR   (EEPROM_PRESET_START + EEPROM_PRESET_SIZE)
#define EEPROM_PRESET3_ADDR   (EEPROM_PRESET_START + 2 * EEPROM_PRESET_SIZE)
#define EEPROM_PRESET4_ADDR   (EEPROM_PRESET_START + 3 * EEPROM_PRESET_SIZE)
#define EEPROM_PRESET5_ADDR   (EEPROM_PRESET_START + 4 * EEPROM_PRESET_SIZE)

// Struct used for bulk save/load if required
struct Settings {
    uint32_t frequency;
    uint8_t  waveform;
    uint8_t  version;
} __attribute__((packed));

#endif // EEPROM_MAP_H
