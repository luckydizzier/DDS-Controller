#ifndef CONFIG_PINS_H
#define CONFIG_PINS_H

// Centralized pin definitions for DDS-Controller hardware
// All numeric values are provided by firmware/config/pins_config.h

#include "../../config/pins_config.h"

// Re-export for firmware modules
#define OUTPUT_CONTROL_PIN PIN_OUTPUT_CONTROL

// Validate that no two pins share the same number
#define VALIDATE_PIN_UNIQUE(a,b) static_assert((a) != (b), "Pin conflict: " #a " and " #b)

VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_ESP_TX);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_DDS_WCLK);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_DDS_FQUD);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_DDS_DATA);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_DDS_RESET);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_ESP_RX, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_DDS_WCLK);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_DDS_FQUD);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_DDS_DATA);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_DDS_RESET);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_ESP_TX, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_DDS_FQUD);
VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_DDS_DATA);
VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_DDS_RESET);
VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_DDS_WCLK, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_DDS_FQUD, PIN_DDS_DATA);
VALIDATE_PIN_UNIQUE(PIN_DDS_FQUD, PIN_DDS_RESET);
VALIDATE_PIN_UNIQUE(PIN_DDS_FQUD, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_DDS_FQUD, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_DDS_FQUD, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_DDS_DATA, PIN_DDS_RESET);
VALIDATE_PIN_UNIQUE(PIN_DDS_DATA, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_DDS_DATA, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_DDS_DATA, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_DDS_RESET, PIN_ESP_LED);
VALIDATE_PIN_UNIQUE(PIN_DDS_RESET, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_DDS_RESET, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_ESP_LED, PIN_OUTPUT_CONTROL);
VALIDATE_PIN_UNIQUE(PIN_ESP_LED, PIN_ESP_GPIO0);

VALIDATE_PIN_UNIQUE(PIN_OUTPUT_CONTROL, PIN_ESP_GPIO0);

#undef VALIDATE_PIN_UNIQUE

#endif // CONFIG_PINS_H
