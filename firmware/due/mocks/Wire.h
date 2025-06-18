#ifndef WIRE_MOCK_H
#define WIRE_MOCK_H

#include <cstdint>

class TwoWire {
public:
    void begin() {}
    void beginTransmission(int addr) { txAddr = addr; pos = 0; }
    void write(uint8_t b) {
        if (pos == 0)
            hi = b;
        else if (pos == 1)
            lo = b;
        else
            memory[(hi << 8) | lo] = b, lo++;
        pos++;
    }
    void endTransmission() { pos = 0; }
    void requestFrom(int addr, int len) {
        (void)addr;
        readAddr = (hi << 8) | lo;
        readLen = len;
        readPos = 0;
    }
    int available() { return readPos < readLen; }
    int read() { return memory[readAddr + readPos++]; }

private:
    int txAddr = 0;
    uint8_t hi = 0, lo = 0;
    int pos = 0;
    int readAddr = 0;
    int readLen = 0;
    int readPos = 0;
    uint8_t memory[65536] = {0};
};

extern TwoWire Wire;

#endif // WIRE_MOCK_H

