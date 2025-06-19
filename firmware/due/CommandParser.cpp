#include "CommandParser.h"
#include <cstdlib>
#include <cstring>
#include "../shared/commands.h"
#include "../shared/config/config.h"
#ifdef USE_ESP
#include "esp_protocol.h"
#endif

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
#ifdef USE_ESP
    if (cmd == CMD_ESP_ON) {
        esp_send(CMD_ESP_ON);
        return "OK:ESPON";
    }
    if (cmd == CMD_ESP_OFF) {
        esp_send(CMD_ESP_OFF);
        return "OK:ESPOFF";
    }
    if (cmd == CMD_ESP_STATUS) {
        esp_send(CMD_ESP_STATUS);
        return "OK:REQ";
    }
    if (cmd.rfind(CMD_ESP_MODE, 0) == 0) {
        esp_send(cmd);
        return "OK:MODE";
    }
    if (cmd == CMD_ESP_LED_ON) {
        digitalWrite(PIN_ESP_LED, HIGH);
        return "OK:LEDON";
    }
    if (cmd == CMD_ESP_LED_OFF) {
        digitalWrite(PIN_ESP_LED, LOW);
        return "OK:LEDOFF";
    }
#else
    if (cmd.rfind("ESP", 0) == 0) {
        return "ERR:ESP_DISABLED";
    }
#endif
    if (cmd == "STATUS") {
        return String("OK:FREQ ") + std::to_string(dds->getFrequency()) +
               " WAVE " + std::to_string(dds->getWaveform());
    }
    if (cmd == "VERSION") {
        return "OK:VERSION 0.0.1";
    }
    return "ERR:INVALID_COMMAND";
}
