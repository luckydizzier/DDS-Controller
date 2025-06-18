#include "firmware/due/DDSDriver.h"
#include "firmware/due/EEPROMManager.h"
#include "firmware/due/CommandParser.h"
#include <iostream>

int main() {
    DDSDriver dds;
    EEPROMManager eep;
    dds.begin();
    eep.begin();
    CommandParser parser;
    parser.begin(dds, eep);
    std::cout << parser.handleCommand("SETFREQ 2000000") << std::endl;
    std::cout << parser.handleCommand("GETFREQ") << std::endl;
    return 0;
}
