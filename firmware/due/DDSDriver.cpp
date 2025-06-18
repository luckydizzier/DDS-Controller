#include "DDSDriver.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

void DDSDriver::begin() {
    // Initialization stub for DDS chip
}

void DDSDriver::setFrequency(uint32_t freq) {
    (void)freq; // placeholder to avoid unused warning
}

void DDSDriver::setWaveform(uint8_t type) {
    (void)type;
}
