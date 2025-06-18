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

private:
  void writeBytes(uint16_t addr, const uint8_t* data, uint8_t len);
  void readBytes(uint16_t addr, uint8_t* data, uint8_t len);
};

#endif
