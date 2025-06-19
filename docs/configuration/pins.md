# Pin Assignments

This table lists all recommended connections for the DDS-Controller hardware. The ESP8266-01 module works at **3.3V** logic levels only. All peripherals except the LCD shield are placed on pins **20** and above. Change the values in `firmware/config/pins_config.h` if you use a different layout.

| Arduino Pin | Peripheral  | Function           |
|-------------|-------------|-------------------|
| 8,9,4,5,6,7 | LCD Shield  | RS,E,D4,D5,D6,D7  |
| A0          | LCD Shield  | Buttons ADC       |
| 20          | ESP8266-01  | RX (from Due TX)  |
| 21          | ESP8266-01  | TX (to Due RX)    |
| 22          | AD9850      | WCLK              |
| 23          | AD9850      | FQUD              |
| 24          | AD9850      | DATA              |
| 25          | AD9850      | RESET             |
| 26          | ESP8266-01  | GPIO2 status LED  |
| 27          | DDS Output  | Control line      |
| 28          | ESP8266-01  | GPIO0 (OTA)       |

```
D20..D53  -> custom peripherals
< D20     -> reserved for shield and internal functions
```

See `docs/hardware/pinmap.md` for an expanded diagram.
