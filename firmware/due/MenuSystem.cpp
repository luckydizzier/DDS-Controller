#include "MenuSystem.h"

void MenuSystem::begin(ButtonManager* btns, EEPROMManager* eeprom, AD9850Driver* driver) {
  buttons = btns;
  ee = eeprom;
  dds = driver;

  lcd.begin(16, 2);
  lcd.clear();

  freqValue = ee->readFreq();
  waveform = 0;
  editing = false;

  setupMenu();
  current = &freqMenu; // first menu item under root
  render();
}

void MenuSystem::setupMenu() {
  root = {MENU_ROOT, "F\xF5men\xFC", nullptr, &freqMenu, nullptr, nullptr, false, false};

  freqMenu = {MENU_FREQ_SETTINGS, "Frekv. Be\xE1ll.", &root, &setFreq, &waveMenu, nullptr, false, false};
  setFreq = {MENU_SET_FREQ, "Frekvencia [Hz]", &freqMenu, nullptr, &saveEeprom, nullptr, true, false};
  saveEeprom = {MENU_SAVE_EE, "Ment\xE9s EEPROM-ba", &freqMenu, nullptr, &loadEeprom, &setFreq, false, true};
  loadEeprom = {MENU_LOAD_EE, "Bet\xF6lt\xE9s EEPROM", &freqMenu, nullptr, nullptr, &saveEeprom, false, true};

  waveMenu = {MENU_WAVEFORM, "Hull\xE1mforma", &root, &sineItem, &outputMenu, &freqMenu, false, false};
  sineItem = {MENU_WAVE_SINE, "Sz\xEDnusz", &waveMenu, nullptr, &squareItem, nullptr, false, true};
  squareItem = {MENU_WAVE_SQUARE, "N\xE9gysz\xF6g", &waveMenu, nullptr, &triangleItem, &sineItem, false, true};
  triangleItem = {MENU_WAVE_TRIANGLE, "H\xE1romsz\xF6g", &waveMenu, nullptr, nullptr, &squareItem, false, true};

  outputMenu = {MENU_OUTPUT_CTRL, "Kimenet", &root, &outputToggle, &systemMenu, &waveMenu, false, false};
  outputToggle = {MENU_OUTPUT_TOGGLE, "Be/Ki", &outputMenu, nullptr, nullptr, nullptr, false, true};

  systemMenu = {MENU_SYSTEM, "Rendszer", &root, &fwVersion, nullptr, &outputMenu, false, false};
  fwVersion = {MENU_FW_VERSION, "Firmware", &systemMenu, nullptr, &restoreDefaults, nullptr, false, true};
  restoreDefaults = {MENU_RESTORE_DEFAULTS, "Alap\xE9rt\xE9k", &systemMenu, nullptr, &exitItem, &fwVersion, false, true};
  exitItem = {MENU_EXIT, "Kil\xE9p\xE9s", &systemMenu, nullptr, nullptr, &restoreDefaults, false, true};
}

void MenuSystem::update() {
  buttons->update();

  if (editing) {
    if (buttons->isPressed(BUTTON_LEFT) && editValue > 0) {
      editValue--;
      render();
    }
    if (buttons->isPressed(BUTTON_RIGHT)) {
      editValue++;
      render();
    }
    if (buttons->wasReleased(BUTTON_SELECT)) {
      editing = false;
      freqValue = editValue;
      dds->setFrequency(freqValue);
      render();
    }
    return;
  }

  if (buttons->wasReleased(BUTTON_UP) && current->prev) {
    current = current->prev;
    render();
    return;
  }
  if (buttons->wasReleased(BUTTON_DOWN) && current->next) {
    current = current->next;
    render();
    return;
  }
  if (buttons->wasReleased(BUTTON_LEFT) && current->parent) {
    current = current->parent;
    render();
    return;
  }
  if (buttons->wasReleased(BUTTON_SELECT)) {
    if (current->editable) {
      editing = true;
      editValue = freqValue;
      render();
      return;
    }
    if (current->child) {
      current = current->child;
      render();
      return;
    }
    if (current->action) {
      handleAction(current);
      render();
      return;
    }
  }
}

void MenuSystem::handleAction(MenuItem* item) {
  switch (item->id) {
    case MENU_SAVE_EE:
      ee->writeFreq(freqValue);
      break;
    case MENU_LOAD_EE:
      freqValue = ee->readFreq();
      dds->setFrequency(freqValue);
      break;
    case MENU_WAVE_SINE:
      waveform = 0;
      dds->setWaveform(0);
      break;
    case MENU_WAVE_SQUARE:
      waveform = 1;
      dds->setWaveform(1);
      break;
    case MENU_WAVE_TRIANGLE:
      waveform = 2;
      dds->setWaveform(2);
      break;
    case MENU_EXIT:
      current = &root;
      break;
    default:
      break;
  }
}

void MenuSystem::render() {
  lcd.clear();
  if (current->parent) {
    lcd.setCursor(0, 0);
    lcd.print(current->parent->label);
  } else {
    lcd.setCursor(0, 0);
    lcd.print(current->label);
  }

  lcd.setCursor(0, 1);
  if (editing) {
    lcd.print(editValue);
    lcd.print(" Hz");
  } else if (current->editable) {
    lcd.print(current->label);
    lcd.setCursor(0, 1);
    lcd.print(freqValue);
    lcd.print(" Hz");
  } else {
    lcd.print(current->label);
  }
}

