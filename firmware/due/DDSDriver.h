#ifndef DDS_DRIVER_H
#define DDS_DRIVER_H

#include <stdint.h>

class DDSDriver {
public:
    void begin();
    void setFrequency(uint32_t freq);
    void setFrequency(double freqHz);
    void setWaveform(uint8_t type);
    uint32_t getFrequency() const { return currentFreq; }
    uint8_t getWaveform() const { return currentWave; }

private:
    void sendByte(uint8_t b);

    uint32_t currentFreq = 0;
    uint8_t currentWave = 0;
};

#endif // DDS_DRIVER_H
