#include "EEPROMManager.h"

#define EEPROM_ADDR_FREQ 0x0000
#define EEPROM_I2C_ADDRESS 0x50

void EEPROMManager::begin() {
  Wire.begin();
}

uint32_t EEPROMManager::readFreq() {
  uint32_t val = 0;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((uint8_t)(EEPROM_ADDR_FREQ >> 8));
  Wire.write((uint8_t)(EEPROM_ADDR_FREQ & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_I2C_ADDRESS, (uint8_t)4);
  for (int i = 0; i < 4 && Wire.available(); i++) {
    ((uint8_t*)&val)[i] = Wire.read();
  }
  return val;
}

void EEPROMManager::writeFreq(uint32_t freq) {
  for (int i = 0; i < 4; i++) {
    Wire.beginTransmission(EEPROM_I2C_ADDRESS);
    Wire.write((uint8_t)((EEPROM_ADDR_FREQ + i) >> 8));
    Wire.write((uint8_t)((EEPROM_ADDR_FREQ + i) & 0xFF));
    Wire.write(((uint8_t*)&freq)[i]);
    Wire.endTransmission();
    delay(5);
  }
}

