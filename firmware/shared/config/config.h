#ifndef CONFIG_H
#define CONFIG_H

#include "pins.h"

// Set to 1 to enable ESP8266 support
#ifndef USE_ESP
#define USE_ESP 1
#endif

// Set to 1 to enable OTA mode. If disabled, Arduino can pull GPIO0 low for flashing
#ifndef USE_ESP_OTA
#define USE_ESP_OTA 1
#endif

#define ESP_BAUD_RATE 9600

#endif // CONFIG_H
