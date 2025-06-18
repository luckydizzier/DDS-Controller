#include "CommandParser.h"
#include <cstdlib>

void CommandParser::begin(DDSDriver& d, EEPROMManager& e) {
    dds = &d;
    eeprom = &e;
}

String CommandParser::handleCommand(const String& cmd) {
    if (!dds || !eeprom)
        return "ERR:NOT_INIT";

    if (cmd.rfind("SETFREQ", 0) == 0) {
        uint32_t val = std::strtoul(cmd.substr(7).c_str(), nullptr, 10);
        dds->setFrequency(val);
        return "OK:SETFREQ";
    }
    if (cmd == "GETFREQ") {
        return String("OK:FREQ ") + std::to_string(dds->getFrequency());
    }
    if (cmd.rfind("SETWAVE", 0) == 0) {
        uint8_t wf = static_cast<uint8_t>(std::strtoul(cmd.substr(7).c_str(), nullptr, 10));
        dds->setWaveform(wf);
        return "OK:SETWAVE";
    }
    if (cmd == "GETWAVE") {
        return String("OK:WAVE ") + std::to_string(dds->getWaveform());
    }
    if (cmd == "SAVE") {
        eeprom->saveFrequency(dds->getFrequency());
        eeprom->saveWaveform(dds->getWaveform());
        return "OK:SAVE";
    }
    if (cmd == "LOAD") {
        uint32_t f = eeprom->loadFrequency();
        uint8_t w = eeprom->loadWaveform();
        dds->setFrequency(f);
        dds->setWaveform(w);
        return "OK:LOAD";
    }
    if (cmd == "STATUS") {
        return String("OK:FREQ ") + std::to_string(dds->getFrequency()) +
               " WAVE " + std::to_string(dds->getWaveform());
    }
    if (cmd == "VERSION") {
        return "OK:VERSION 0.0.1";
    }
    return "ERR:INVALID_COMMAND";
}
