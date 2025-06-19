#ifndef CONFIG_PINS_H
#define CONFIG_PINS_H

// Centralized pin definitions for DDS-Controller hardware
// Adjust these values to match the wiring as documented in docs/hardware/pinmap.md

// DDS (AD9850)
#define PIN_DDS_WCLK   20
#define PIN_DDS_FQUD   21
#define PIN_DDS_DATA   22
#define PIN_DDS_RESET  23

// ESP8266-01 communication via SoftwareSerial
#define PIN_ESP_RX     52  // Due TX to ESP8266 RX
#define PIN_ESP_TX     53  // Due RX to ESP8266 TX
#define PIN_ESP_LED    24  // GPIO2 on ESP8266

// Control output
#define OUTPUT_CONTROL_PIN 25

#endif // CONFIG_PINS_H
