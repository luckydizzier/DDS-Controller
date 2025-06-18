#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>
#include <Wire.h>


#define EEPROM_I2C_ADDRESS 0x50
#define EEPROM_FREQ_ADDR 0x0000
#define EEPROM_WAVEFORM_ADDR 0x0004

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
