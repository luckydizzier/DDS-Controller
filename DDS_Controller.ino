// DDS_Controller.ino
#include "ConfigStore.h"
#include "AD9850Driver.h"
#include "DisplayManager.h"
#include "ButtonManager.h"

ConfigStore config;
AD9850Driver dds;
DisplayManager display;
ButtonManager buttons;

void setup() {
  Serial.begin(9600);
  config.begin();
  dds.begin();
  display.begin();
  buttons.begin();

  // Beállítás betöltés EEPROM-ból
  uint32_t freq = config.loadFreq();
  uint8_t wave = config.loadWaveform();
  dds.setFrequency(freq);
  dds.setWaveform(wave);

  display.showStartup(freq, wave);
}

void loop() {
  buttons.update();
  // később: menürendszer és ESP UART kezelése
}
