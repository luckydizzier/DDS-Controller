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

// Diagnostic commands
#define CMD_STATUS  "STATUS"
#define CMD_VERSION "VERSION"

// Preset management
#define CMD_SAVE   "SAVE"   // Save to EEPROM or preset slot
#define CMD_LOAD   "LOAD"   // Load from EEPROM or preset slot
#define CMD_DELETE "DELETE" // Delete preset slot

// ESP8266 control commands (all prefixed with 'E')
#define CMD_ESP_ON       "EON"
#define CMD_ESP_OFF      "EOF"
#define CMD_ESP_STATUS   "EST"
#define CMD_ESP_VERSION  "EVR"
#define CMD_ESP_MODE     "EMD"
#define CMD_ESP_LED_ON   "EL1"
#define CMD_ESP_LED_OFF  "EL0"

#endif // SHARED_COMMANDS_H
