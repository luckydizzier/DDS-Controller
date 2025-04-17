// AD9850Driver.cpp
#include "AD9850Driver.h"

void AD9850Driver::begin() {
  pinMode(DDS_PIN_DATA, OUTPUT);
  pinMode(DDS_PIN_W_CLK, OUTPUT);
  pinMode(DDS_PIN_FQ_UD, OUTPUT);
  pinMode(DDS_PIN_RESET, OUTPUT);

  digitalWrite(DDS_PIN_RESET, LOW);
  digitalWrite(DDS_PIN_W_CLK, LOW);
  digitalWrite(DDS_PIN_FQ_UD, LOW);
  digitalWrite(DDS_PIN_DATA, LOW);

  digitalWrite(DDS_PIN_RESET, HIGH);
  delay(5);
  digitalWrite(DDS_PIN_RESET, LOW);
}

void AD9850Driver::setFrequency(uint32_t freq) {
  uint32_t tuningWord = (uint32_t)((freq * 4294967296ULL) / DDS_CLOCK_HZ);
  updateDDS(tuningWord, 0x00); // alap: SINE
}

void AD9850Driver::setWaveform(uint8_t type) {
  uint32_t freq = 1000000; // dummy frekvencia állandó, override-olva lesz kívülről
  uint32_t tuningWord = (uint32_t)((freq * 4294967296ULL) / DDS_CLOCK_HZ);
  uint8_t ctrl = (type == 1) ? 0x01 : 0x00; // bit0: square
  updateDDS(tuningWord, ctrl);
}

void AD9850Driver::updateDDS(uint32_t tuningWord, uint8_t control) {
  for (int i = 0; i < 4; i++) {
    sendByte((uint8_t)(tuningWord >> (8 * i)));
  }
  sendByte(control);
  pulse(DDS_PIN_FQ_UD);
}

void AD9850Driver::sendByte(uint8_t b) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(DDS_PIN_DATA, (b >> i) & 0x01);
    pulse(DDS_PIN_W_CLK);
  }
}

void AD9850Driver::pulse(int pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin, LOW);
}
