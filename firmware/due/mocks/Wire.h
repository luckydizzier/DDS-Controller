#ifndef WIRE_MOCK_H
#define WIRE_MOCK_H

#include <cstdint>

class TwoWire {
public:
    void begin() {}
    void beginTransmission(int) {}
    void write(uint8_t) {}
    void endTransmission() {}
    void requestFrom(int, int) {}
    int available() { return 0; }
    int read() { return 0; }
};

extern TwoWire Wire;

#endif // WIRE_MOCK_H
