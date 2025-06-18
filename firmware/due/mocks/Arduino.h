#ifndef ARDUINO_MOCK_H
#define ARDUINO_MOCK_H

#include <cstdint>
#include <string>

#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define A0 0

inline void pinMode(int, int) {}
inline void digitalWrite(int, int) {}
inline int analogRead(int) { return 0; }
inline unsigned long millis() { return 0; }
inline void delay(unsigned long) {}
inline void delayMicroseconds(unsigned int) {}

using String = std::string;

#endif // ARDUINO_MOCK_H
