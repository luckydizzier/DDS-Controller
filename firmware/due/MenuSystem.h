#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "ButtonManager.h"
#include "EEPROMManager.h"
#include "AD9850Driver.h"

class MenuSystem {
public:
  void begin(ButtonManager* btns, EEPROMManager* eeprom, AD9850Driver* dds);
  void update();

private:
  enum MenuId {
    MENU_ROOT = 0,
    MENU_FREQ_SETTINGS,
    MENU_SET_FREQ,
    MENU_SAVE_EE,
    MENU_LOAD_EE,
    MENU_WAVEFORM,
    MENU_WAVE_SINE,
    MENU_WAVE_SQUARE,
    MENU_WAVE_TRIANGLE,
    MENU_OUTPUT_CTRL,
    MENU_OUTPUT_TOGGLE,
    MENU_SYSTEM,
    MENU_FW_VERSION,
    MENU_RESTORE_DEFAULTS,
    MENU_EXIT
  };

  struct MenuItem {
    MenuId id;
    const char* label;
    MenuItem* parent;
    MenuItem* child;
    MenuItem* next;
    MenuItem* prev;
    bool editable;
    bool action;
  };

  LiquidCrystal lcd = LiquidCrystal(LCD_PIN_RS, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7);
  ButtonManager* buttons;
  EEPROMManager* ee;
  AD9850Driver* dds;

  MenuItem* current;
  bool editing;
  uint32_t freqValue;
  uint32_t editValue;
  uint8_t waveform;

  // Menu items
  MenuItem root;
  MenuItem freqMenu;
  MenuItem setFreq;
  MenuItem saveEeprom;
  MenuItem loadEeprom;
  MenuItem waveMenu;
  MenuItem sineItem;
  MenuItem squareItem;
  MenuItem triangleItem;
  MenuItem outputMenu;
  MenuItem outputToggle;
  MenuItem systemMenu;
  MenuItem fwVersion;
  MenuItem restoreDefaults;
  MenuItem exitItem;

  void setupMenu();
  void render();
  void handleAction(MenuItem* item);
};

#endif
