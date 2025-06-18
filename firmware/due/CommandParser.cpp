#include "CommandParser.h"
#include <cstdlib>
#include <cstring>
#include "../shared/commands.h"

void CommandParser::begin(DDSDriver& d, EEPROMManager& e) {
    dds = &d;
    eeprom = &e;
}

String CommandParser::handleCommand(const String& cmd) {
    if (!dds || !eeprom)
        return "ERR:NOT_INIT";

    if (cmd.rfind(CMD_SET_FREQ, 0) == 0) {
        uint32_t val = std::strtoul(cmd.substr(strlen(CMD_SET_FREQ) + 1).c_str(), nullptr, 10);
        dds->setFrequency(val);
        return "OK:SETFREQ";
    }
    if (cmd == CMD_GET_FREQ) {
        return String("OK:FREQ ") + std::to_string(dds->getFrequency());
    }
    if (cmd.rfind(CMD_SET_WAVE, 0) == 0) {
        uint8_t wf = static_cast<uint8_t>(std::strtoul(cmd.substr(strlen(CMD_SET_WAVE) + 1).c_str(), nullptr, 10));
        dds->setWaveform(wf);
        return "OK:SETWAVE";
    }
    if (cmd == CMD_GET_WAVE) {
        return String("OK:WAVE ") + std::to_string(dds->getWaveform());
    }
    if (cmd.rfind(CMD_SAVE, 0) == 0) {
        if (cmd.size() > strlen(CMD_SAVE)) {
            uint8_t id = static_cast<uint8_t>(std::strtoul(cmd.substr(strlen(CMD_SAVE) + 1).c_str(), nullptr, 10));
            eeprom->savePreset(id, dds->getFrequency(), dds->getWaveform());
        } else {
            eeprom->saveFrequency(dds->getFrequency());
            eeprom->saveWaveform(dds->getWaveform());
        }
        return "OK:SAVE";
    }
    if (cmd.rfind(CMD_LOAD, 0) == 0) {
        if (cmd.size() > strlen(CMD_LOAD)) {
            uint8_t id = static_cast<uint8_t>(std::strtoul(cmd.substr(strlen(CMD_LOAD) + 1).c_str(), nullptr, 10));
            uint32_t f = 0; uint8_t w = 0;
            eeprom->loadPreset(id, f, w);
            dds->setFrequency(f);
            dds->setWaveform(w);
        } else {
            uint32_t f = eeprom->loadFrequency();
            uint8_t w = eeprom->loadWaveform();
            dds->setFrequency(f);
            dds->setWaveform(w);
        }
        return "OK:LOAD";
    }
    if (cmd.rfind(CMD_DELETE, 0) == 0) {
        uint8_t id = static_cast<uint8_t>(std::strtoul(cmd.substr(strlen(CMD_DELETE) + 1).c_str(), nullptr, 10));
        eeprom->deletePreset(id);
        return "OK:DELETE";
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
