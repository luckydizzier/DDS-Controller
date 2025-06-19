# Pin Assignments

This table lists all recommended connections for the DDS-Controller hardware. The ESP8266-01 module works at **3.3V** logic levels only. All peripherals except the LCD shield must be connected on Arduino pins **20** and above.

| Arduino Pin | Peripheral  | Function           |
|-------------|-------------|-------------------|
| 8,9,4,5,6,7 | LCD Shield  | RS,E,D4,D5,D6,D7  |
| A0          | LCD Shield  | Buttons ADC       |
| 10          | AD9850      | WCLK              |
| 11          | AD9850      | FQUD              |
| 12          | AD9850      | DATA              |
| 13          | AD9850      | RESET             |
| 20          | ESP8266-01  | RX (from Due TX)  |
| 21          | ESP8266-01  | TX (to Due RX)    |
| 24          | ESP8266-01  | GPIO2 status LED  |
| 25          | DDS Output  | Control line      |
| 26          | ESP8266-01  | GPIO0 (OTA)       |

```
D20..D53  -> custom peripherals
< D20     -> reserved for shield and internal functions
```

See `docs/hardware/pinmap.md` for an expanded diagram.
