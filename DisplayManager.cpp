// DisplayManager.cpp
#include "DisplayManager.h"

void DisplayManager::begin() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("DDS Vezetoseg");
  delay(1000);
}

void DisplayManager::showStartup(uint32_t freq, uint8_t waveform) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Freq:");
  lcd.print(freq);
  lcd.print("Hz");

  lcd.setCursor(0, 1);
  lcd.print("Wave:");
  printWaveform(waveform);
}

void DisplayManager::printWaveform(uint8_t waveform) {
  if (waveform == 1) {
    lcd.print("SQUARE");
  } else {
    lcd.print("SINE");
  }
}
