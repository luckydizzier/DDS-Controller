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

    EEPROMManager e;
    CommandParser p;
    p.begin(d, e);
    assert(p.handleCommand("SETFREQ 12345") == "OK:SETFREQ");
    assert(d.getFrequency() == 12345u);

    LiquidCrystal lcd(0,0,0,0,0,0);
    ButtonManager btn;
    MenuSystem menu(lcd, btn, e, d);
    menu.update();

    return 0;
}
