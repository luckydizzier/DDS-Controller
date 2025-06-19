#include <cassert>
#include "firmware/due/DDSDriver.h"
#include "firmware/due/CommandParser.h"
#include "firmware/due/EEPROMManager.h"
#include "firmware/due/MenuSystem.h"
#include "firmware/due/ButtonManager.h"
#include "firmware/due/mocks/LiquidCrystal.h"

int main() {
    DDSDriver d;
    d.begin();
    d.setFrequency(1000000u);
    assert(d.getFrequency() == 1000000u);

    d.setFrequency(4321.0);
    assert(d.getFrequency() == 4321u);
    d.setWaveform(2);
    assert(d.getWaveform() == 2);

    EEPROMManager e;
    CommandParser p;
    p.begin(d, e);
    assert(p.handleCommand("SF 12345") == "OK:SETFREQ");
    assert(d.getFrequency() == 12345u);

    LiquidCrystal lcd(0,0,0,0,0,0);
    ButtonManager btn;
    MenuSystem menu(lcd, btn, e, d);
    menu.update();

    return 0;
}
