#ifndef DDS_DRIVER_H
#define DDS_DRIVER_H

#include <stdint.h>

class DDSDriver {
public:
    void begin();
    void setFrequency(uint32_t freq);
    void setWaveform(uint8_t type);
};

#endif // DDS_DRIVER_H
