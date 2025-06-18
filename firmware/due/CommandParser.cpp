#include "CommandParser.h"
#include <cstdlib>

void CommandParser::begin(DDSDriver& d, EEPROMManager& e) {
    dds = &d;
    eeprom = &e;
}

void CommandParser::handleCommand(const String& cmd) {
    if (cmd.rfind("SETFREQ", 0) == 0) {
        uint32_t val = std::strtoul(cmd.substr(7).c_str(), nullptr, 10);
        if (dds) dds->setFrequency(val);
    } else if (cmd == "GETFREQ") {
        if (eeprom) eeprom->saveFrequency(0); // placeholder
    }
}
