#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#ifdef ARDUINO
#include <Arduino.h>
#else
#include "mocks/Arduino.h"
#endif
#include "DDSDriver.h"
#include "EEPROMManager.h"

class CommandParser {
public:
    void begin(DDSDriver& d, EEPROMManager& e);
    String handleCommand(const String& cmd);

private:
    DDSDriver* dds = nullptr;
    EEPROMManager* eeprom = nullptr;
};

#endif // COMMAND_PARSER_H
