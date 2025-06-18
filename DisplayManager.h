// DisplayManager.h
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#ifdef ARDUINO
#include <Arduino.h>
#include <LiquidCrystal.h>
#else
#include "firmware/due/mocks/Arduino.h"
#include "firmware/due/mocks/LiquidCrystal.h"
#endif

#define LCD_PIN_RS 8
#define LCD_PIN_EN 9
#define LCD_PIN_D4 4
#define LCD_PIN_D5 5
#define LCD_PIN_D6 6
#define LCD_PIN_D7 7

class DisplayManager {
public:
  void begin();
  void showStartup(uint32_t freq, uint8_t waveform);

private:
  LiquidCrystal lcd = LiquidCrystal(LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7);
  void printWaveform(uint8_t waveform);
};

#endif
