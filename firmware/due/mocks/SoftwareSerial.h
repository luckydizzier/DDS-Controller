#ifndef SOFTWARESERIAL_MOCK_H
#define SOFTWARESERIAL_MOCK_H

#include <string>
#include <iostream>

class SoftwareSerialMock {
public:
    SoftwareSerialMock(int rx, int tx) {}
    void begin(long) {}
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

#endif // SOFTWARESERIAL_MOCK_H
