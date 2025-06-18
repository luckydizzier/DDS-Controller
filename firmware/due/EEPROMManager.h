#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>
#include <Wire.h>

class EEPROMManager {
public:
  void begin();
  uint32_t readFreq();
  void writeFreq(uint32_t freq);
};

#endif
