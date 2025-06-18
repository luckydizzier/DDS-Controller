#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include "EEPROMMap.h"

class EEPROMManager {
public:
  void begin();

  void saveFrequency(uint32_t freq);
  uint32_t loadFrequency();

  void saveWaveform(uint8_t wf);
  uint8_t loadWaveform();

  void savePreset(uint8_t id, uint32_t freq, uint8_t waveform);
  void loadPreset(uint8_t id, uint32_t &freq, uint8_t &waveform);
  void deletePreset(uint8_t id);

private:
  void writeBytes(uint16_t addr, const uint8_t* data, uint8_t len);
  void readBytes(uint16_t addr, uint8_t* data, uint8_t len);
};

#endif
