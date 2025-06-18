// firmware/due/MenuSystem.h
#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "ButtonManager.h"
#include "EEPROMManager.h"
#include "DDSDriver.h"

class MenuSystem {
public:
    MenuSystem(LiquidCrystal& lcd, ButtonManager& buttons, EEPROMManager& eeprom, DDSDriver& dds);
    void update();

private:
    enum MenuID {
        MAIN_MENU,
        FREQ_SETTINGS,
        FREQ_EDIT,
        FREQ_SAVE,
        FREQ_LOAD,
        WAVEFORM_MENU,
        WAVE_SINE,
        WAVE_SQUARE,
        WAVE_TRIANGLE,
        OUTPUT_CTRL,
        OUTPUT_ON,
        OUTPUT_OFF,
        SYSTEM_MENU,
        SHOW_VERSION,
        RESET_DEFAULTS,
        EXIT_MENU
    };

    struct MenuItem {
        MenuID id;
        const char* label;
        MenuID parent;
        MenuID children[3];
        uint8_t childCount;
        bool editable;
    };

    LiquidCrystal& lcd;
    ButtonManager& buttons;
    EEPROMManager& eeprom;
    DDSDriver& dds;

    MenuID current;
    uint16_t freq;

    void display();
    void navigate();
    void applyAction(MenuID action);
};

#endif
