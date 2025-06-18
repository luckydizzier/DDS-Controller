#include <cassert>
#include "firmware/due/CommandParser.h"
#include "firmware/due/DDSDriver.h"
#include "firmware/due/EEPROMManager.h"

int main() {
    DDSDriver d;
    EEPROMManager e;
    CommandParser p;
    d.begin();
    e.begin();
    p.begin(d, e);

    assert(p.handleCommand("SF 1000") == "OK:SETFREQ");
    assert(d.getFrequency() == 1000u);
    assert(p.handleCommand("GF").find("OK:FREQ") != std::string::npos);
    assert(p.handleCommand("SW 1") == "OK:SETWAVE");
    assert(d.getWaveform() == 1);
    assert(p.handleCommand("GW").find("OK:WAVE") != std::string::npos);
    assert(p.handleCommand("SAVE 1") == "OK:SAVE");
    assert(p.handleCommand("LOAD 1") == "OK:LOAD");
    assert(p.handleCommand("DELETE 1") == "OK:DELETE");
    assert(p.handleCommand("STATUS").find("OK:FREQ") != std::string::npos);
    assert(p.handleCommand("VERSION") == "OK:VERSION 0.0.1");
    assert(p.handleCommand("BAD") == "ERR:INVALID_COMMAND");
    return 0;
}

