#ifndef ESP_CONFIG_H
#define ESP_CONFIG_H

#include <Arduino.h>
#include <FS.h>

struct EspConfig {
  bool enable_ota = true;
  bool gpio0_led = true;
  int tx_pin = 2;
  int rx_pin = 3;
};

bool loadEspConfig(const char* path, EspConfig& cfg);

#endif // ESP_CONFIG_H
