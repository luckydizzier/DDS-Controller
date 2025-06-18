// firmware/due/MenuSystem.h
#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#ifdef ARDUINO
#include <Arduino.h>
#include <LiquidCrystal.h>
#else
#include "mocks/Arduino.h"
#include "mocks/LiquidCrystal.h"
#endif
#include "ButtonManager.h"
#include "EEPROMManager.h"
#include "DDSDriver.h"

// Digital pin used to enable or disable the DDS output
#define OUTPUT_CONTROL_PIN 2

class MenuSystem {
public:
    MenuSystem(LiquidCrystal& lcd, ButtonManager& buttons, EEPROMManager& eeprom, DDSDriver& dds);
    void update();

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
        PRESET_MENU,
        PRESET_SAVE,
        PRESET_LOAD,
        PRESET_DELETE,
        EXIT_MENU
    };

    struct MenuItem {
        MenuID id;
        const char* label;
        MenuID parent;
        MenuID children[4];
        uint8_t childCount;
        bool editable;
    };

private:
    LiquidCrystal& lcd;
    ButtonManager& buttons;
    EEPROMManager& eeprom;
    DDSDriver& dds;

    MenuID current;
    uint32_t freq;
    uint8_t waveform;

    enum class EditContext { NONE, FREQ, PRESET_SAVE, PRESET_LOAD, PRESET_DELETE };
    EditContext editContext = EditContext::NONE;
    uint8_t editPresetId = 1;
    uint32_t editValue = 0;

    void display();
    void navigate();
    void applyAction(MenuID action);
};

#endif
