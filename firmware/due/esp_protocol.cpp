#include "esp_protocol.h"
#include "CommandParser.h"

#ifdef USE_ESP
static SerialPort* espPort = nullptr;
static CommandParser* cmdParser = nullptr;

void esp_begin(SerialPort& serial, CommandParser& parser) {
    espPort = &serial;
    cmdParser = &parser;
}

void esp_send(const String& cmd) {
    if (espPort) {
        espPort->println(cmd);
    }
}

void esp_handle() {
    if (!espPort || !cmdParser) return;
    if (espPort->available()) {
        String c = espPort->readStringUntil('\n');
        String resp = cmdParser->handleCommand(c);
        espPort->println(resp);
    }
}
#endif // USE_ESP
