// Shared command definitions for ASCII protocol
#ifndef SHARED_COMMANDS_H
#define SHARED_COMMANDS_H

// Frequency control
#define CMD_SET_FREQ  "SF"  // Set frequency
#define CMD_GET_FREQ  "GF"  // Query frequency

// Waveform control
#define CMD_SET_WAVE  "SW"  // Set waveform type
#define CMD_GET_WAVE  "GW"  // Query waveform

// Output enable/disable
#define CMD_OUTPUT_ON  "ON"
#define CMD_OUTPUT_OFF "OFF"

// Preset management
#define CMD_SAVE   "SAVE"   // Save to EEPROM or preset slot
#define CMD_LOAD   "LOAD"   // Load from EEPROM or preset slot
#define CMD_DELETE "DELETE" // Delete preset slot

// ESP8266 control commands
#define CMD_ESP_ON      "ESPON"
#define CMD_ESP_OFF     "ESPOFF"
#define CMD_ESP_STATUS  "ESPSTS"
#define CMD_ESP_MODE    "ESPMODE"
#define CMD_ESP_LED_ON  "ESPLEDON"
#define CMD_ESP_LED_OFF "ESPLEDOFF"

#endif // SHARED_COMMANDS_H
