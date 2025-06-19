#include "DDSDriver.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif
#include "../shared/config/pins.h"

// Pin mapping for AD9850 module comes from config
static constexpr int PIN_WCLK  = PIN_DDS_WCLK;
static constexpr int PIN_FQUD  = PIN_DDS_FQUD;
static constexpr int PIN_DATA  = PIN_DDS_DATA;
static constexpr int PIN_RESET = PIN_DDS_RESET;

void DDSDriver::begin() {
#ifdef ARDUINO
    pinMode(PIN_WCLK, OUTPUT);
    pinMode(PIN_FQUD, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);
    pinMode(PIN_RESET, OUTPUT);

    digitalWrite(PIN_RESET, LOW);
    digitalWrite(PIN_WCLK, LOW);
    digitalWrite(PIN_FQUD, LOW);
    digitalWrite(PIN_DATA, LOW);

    digitalWrite(PIN_RESET, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_RESET, LOW);
    delayMicroseconds(10);
#endif
    currentFreq = 0;
    currentWave = 0;
}

void DDSDriver::sendByte(uint8_t b) {
#ifdef ARDUINO
    for (uint8_t i = 0; i < 8; ++i) {
        digitalWrite(PIN_DATA, (b >> i) & 0x01);
        digitalWrite(PIN_WCLK, HIGH);
        delayMicroseconds(1);
        digitalWrite(PIN_WCLK, LOW);
    }
#else
    (void)b;
#endif
}

void DDSDriver::setFrequency(uint32_t freq) {
    setFrequency(static_cast<double>(freq));
}

void DDSDriver::setFrequency(double freqHz) {
#ifdef ARDUINO
    const double refClk = 125000000.0; // AD9850 reference clock
    uint32_t tuningWord = static_cast<uint32_t>((freqHz * (1ULL << 32)) / refClk);

    for (int i = 0; i < 4; ++i) {
        sendByte(static_cast<uint8_t>(tuningWord >> (8 * i)));
    }
    sendByte(0x00); // control byte

    digitalWrite(PIN_FQUD, HIGH);
    delayMicroseconds(1);
    digitalWrite(PIN_FQUD, LOW);
#else
    (void)freqHz;
#endif
    currentFreq = static_cast<uint32_t>(freqHz);
}

void DDSDriver::setWaveform(uint8_t type) {
    currentWave = type;
    // actual waveform control would require external circuitry
}
