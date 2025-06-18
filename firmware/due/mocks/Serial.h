#ifndef SERIAL_MOCK_H
#define SERIAL_MOCK_H

#include <cstdint>
#include <string>
#include <iostream>

class SerialMock {
public:
    void begin(unsigned long) {}
    bool available() { return !buffer.empty(); }
    char read() {
        if (buffer.empty()) return 0;
        char c = buffer.front();
        buffer.erase(buffer.begin());
        return c;
    }
    std::string readStringUntil(char term) {
        std::string out;
        while (!buffer.empty()) {
            char c = read();
            if (c == term) break;
            out += c;
        }
        return out;
    }
    void inject(const std::string& s) { buffer += s; }
    void print(const std::string& s) { std::cout << s; }
    void println(const std::string& s) { std::cout << s << std::endl; }

private:
    std::string buffer;
};

extern SerialMock Serial;

#endif // SERIAL_MOCK_H

