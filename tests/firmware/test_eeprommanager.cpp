#include <cassert>
#include "firmware/due/EEPROMManager.h"

int main() {
    EEPROMManager e;
    e.begin();
    e.saveFrequency(12345);
    e.loadFrequency();
    e.saveWaveform(2);
    e.loadWaveform();
    e.savePreset(1, 555, 1);
    uint32_t f = 0; uint8_t w = 0;
    e.loadPreset(1, f, w);
    e.deletePreset(1);
    e.loadPreset(1, f, w);
    return 0;
}

