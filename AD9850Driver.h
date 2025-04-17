// AD9850Driver.h
#ifndef AD9850_DRIVER_H
#define AD9850_DRIVER_H
#include <Arduino.h>

#define DDS_PIN_DATA   10
#define DDS_PIN_W_CLK  11
#define DDS_PIN_FQ_UD  12
#define DDS_PIN_RESET  13

#define DDS_CLOCK_HZ   125000000UL

class AD9850Driver {
public:
  void begin();
  void setFrequency(uint32_t freq);
  void setWaveform(uint8_t type); // 0=SINE, 1=SQUARE

private:
  void pulse(int pin);
  void sendByte(uint8_t b);
  void updateDDS(uint32_t tuningWord, uint8_t control);
};

#endif
