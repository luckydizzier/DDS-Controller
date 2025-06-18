#include "EEPROMManager.h"

void EEPROMManager::begin() {
  Wire.begin();
}

void EEPROMManager::saveFrequency(uint32_t freq) {
  writeBytes(EEPROM_FREQ_ADDR, (uint8_t *)&freq, sizeof(freq));
}

uint32_t EEPROMManager::loadFrequency() {
  uint32_t val = 0;
  readBytes(EEPROM_FREQ_ADDR, (uint8_t *)&val, sizeof(val));
  return val;
}

void EEPROMManager::saveWaveform(uint8_t wf) {
  writeBytes(EEPROM_WAVEFORM_ADDR, &wf, sizeof(wf));
}

uint8_t EEPROMManager::loadWaveform() {
  uint8_t wf = 0;
  readBytes(EEPROM_WAVEFORM_ADDR, &wf, sizeof(wf));
  return wf;
}

void EEPROMManager::writeBytes(uint16_t addr, const uint8_t *data, uint8_t len) {
  for (uint8_t i = 0; i < len; i++) {
    Wire.beginTransmission(EEPROM_I2C_ADDRESS);
    Wire.write((uint8_t)((addr + i) >> 8));
    Wire.write((uint8_t)((addr + i) & 0xFF));
    Wire.write(data[i]);
    Wire.endTransmission();
    delay(5);
  }
}

void EEPROMManager::readBytes(uint16_t addr, uint8_t *data, uint8_t len) {
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((uint8_t)(addr >> 8));
  Wire.write((uint8_t)(addr & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_I2C_ADDRESS, len);
  for (uint8_t i = 0; i < len && Wire.available(); i++) {
    data[i] = Wire.read();
  }
}

