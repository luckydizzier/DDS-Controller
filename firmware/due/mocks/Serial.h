#ifndef SERIAL_MOCK_H
#define SERIAL_MOCK_H

#include <cstdint>
#include <string>
#include <iostream>

class SerialMock {
public:
    void begin(unsigned long) {}
    bool available() { return false; }
    char read() { return 0; }
    std::string readStringUntil(char) { return {}; }
    void print(const std::string& s) { std::cout << s; }
    void println(const std::string& s) { std::cout << s << std::endl; }
};

extern SerialMock Serial;

#endif // SERIAL_MOCK_H
