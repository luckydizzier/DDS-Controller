# Hardware Pin Mapping – DDS-Controller

> _This document acts as the single source of truth for wiring. See `firmware/shared/config/pins.h` for the authoritative definitions._

| Arduino Due Pin | Peripheral        | Peripheral Pin | Notes                              |
|-----------------|-------------------|----------------|------------------------------------|
| 8, 9, 4, 5, 6, 7| LCD Keypad Shield | RS,E,D4,D5,D6,D7 | Uses standard Arduino shield layout |
| A0              | LCD Keypad Shield | Buttons ADC    | Reads multiple buttons via resistor ladder |
| 20              | AD9850 DDS        | WCLK           | Serial clock to DDS module         |
| 21              | AD9850 DDS        | FQUD           | Frequency update                   |
| 22              | AD9850 DDS        | DATA           | Serial data                        |
| 23              | AD9850 DDS        | RESET          | Module reset                       |
| 24              | ESP8266-01        | GPIO2          | WiFi status LED                    |
| 52              | ESP8266-01        | RX             | Connected to Due TX (SoftwareSerial) |
| 53              | ESP8266-01        | TX             | Connected to Due RX (SoftwareSerial) |
| 25              | DDS Output Enable | Control line   | Toggles DDS output                 |

**Safety Notice:** The ESP8266-01 module operates at **3.3V** logic levels only. Connecting it directly to 5V will permanently damage the module.
