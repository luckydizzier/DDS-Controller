#include <cassert>
#include "firmware/due/MenuSystem.h"
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
    // simulate OUTPUT_ON action
    menu.update();
    // no assertion possible without hardware, but ensure no crash
    return 0;
}

