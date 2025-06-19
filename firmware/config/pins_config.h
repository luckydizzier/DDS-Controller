#ifndef FIRMWARE_PINS_CONFIG_H
#define FIRMWARE_PINS_CONFIG_H

// Default pin mapping for DDS-Controller.
// Modify these values to match your wiring.
// All custom peripherals start from pin 20 and above.

// ESP8266-01 SoftwareSerial
#define PIN_ESP_RX 20
#define PIN_ESP_TX 21

// DDS module (AD9850)
#define PIN_DDS_WCLK 22
#define PIN_DDS_FQUD 23
#define PIN_DDS_DATA 24
#define PIN_DDS_RESET 25

// Status LED on ESP GPIO2
#define PIN_ESP_LED 26

// Output enable control for DDS
#define PIN_OUTPUT_CONTROL 27

// ESP8266 GPIO0 (reserved for OTA)
#define PIN_ESP_GPIO0 28

#endif // FIRMWARE_PINS_CONFIG_H
