#include <cassert>
#define private public
#include "firmware/due/MenuSystem.h"
#undef private
#include "firmware/due/ButtonManager.h"
#include "firmware/due/EEPROMManager.h"
#include "firmware/due/DDSDriver.h"
#include "firmware/due/mocks/LiquidCrystal.h"

int main() {
    LiquidCrystal lcd(0,0,0,0,0,0);
    ButtonManager btn;
    EEPROMManager e;
    DDSDriver d;
    btn.begin();
    e.begin();
    d.begin();

    MenuSystem menu(lcd, btn, e, d);

    menu.applyAction(MenuSystem::WAVE_SINE);
    assert(d.getWaveform() == 0);
    menu.freq = 2222;
    menu.applyAction(MenuSystem::FREQ_SAVE);
    menu.freq = 0;
    menu.applyAction(MenuSystem::FREQ_LOAD);
    assert(d.getFrequency() == 2222u);
    menu.applyAction(MenuSystem::OUTPUT_ON);
    menu.applyAction(MenuSystem::OUTPUT_OFF);
    return 0;
}

