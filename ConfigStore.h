// ConfigStore.h
#ifndef CONFIG_STORE_H
#define CONFIG_STORE_H
#include <Arduino.h>
#include <Wire.h>

#define EEPROM_ADDR_FREQ       0   // int32_t
#define EEPROM_ADDR_WAVEFORM   4   // uint8_t
#define EEPROM_I2C_ADDRESS     0x50
#define USE_EMULATED_EEPROM    false

class ConfigStore {
public:
  void begin();
  uint32_t loadFreq();
  void saveFreq(uint32_t freq);
  uint8_t loadWaveform();
  void saveWaveform(uint8_t wave);

private:
  void writeBytes(uint16_t addr, const uint8_t* data, uint8_t len);
  void readBytes(uint16_t addr, uint8_t* data, uint8_t len);
};

#endif
