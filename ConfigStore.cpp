// ConfigStore.cpp
#include "ConfigStore.h"

void ConfigStore::begin() {
  if (!USE_EMULATED_EEPROM) {
    Wire.begin();
  }
}

uint32_t ConfigStore::loadFreq() {
  uint32_t val;
  readBytes(EEPROM_ADDR_FREQ, (uint8_t*)&val, sizeof(val));
  return val;
}

void ConfigStore::saveFreq(uint32_t freq) {
  writeBytes(EEPROM_ADDR_FREQ, (uint8_t*)&freq, sizeof(freq));
}

uint8_t ConfigStore::loadWaveform() {
  uint8_t val;
  readBytes(EEPROM_ADDR_WAVEFORM, &val, sizeof(val));
  return val;
}

void ConfigStore::saveWaveform(uint8_t wave) {
  writeBytes(EEPROM_ADDR_WAVEFORM, &wave, sizeof(wave));
}

void ConfigStore::writeBytes(uint16_t addr, const uint8_t* data, uint8_t len) {
  if (USE_EMULATED_EEPROM) {
    for (uint8_t i = 0; i < len; i++) {
      *((uint8_t*)addr + i) = data[i]; // veszélyes, csak debug
    }
    return;
  }
  for (uint8_t i = 0; i < len; i++) {
    Wire.beginTransmission(EEPROM_I2C_ADDRESS);
    Wire.write((uint8_t)((addr + i) >> 8));
    Wire.write((uint8_t)((addr + i) & 0xFF));
    Wire.write(data[i]);
    Wire.endTransmission();
    delay(5);
  }
}

void ConfigStore::readBytes(uint16_t addr, uint8_t* data, uint8_t len) {
  if (USE_EMULATED_EEPROM) {
    for (uint8_t i = 0; i < len; i++) {
      data[i] = *((uint8_t*)addr + i); // veszélyes, csak debug
    }
    return;
  }
  for (uint8_t i = 0; i < len; i++) {
    Wire.beginTransmission(EEPROM_I2C_ADDRESS);
    Wire.write((uint8_t)((addr + i) >> 8));
    Wire.write((uint8_t)((addr + i) & 0xFF));
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
    if (Wire.available()) {
      data[i] = Wire.read();
    }
  }
}
