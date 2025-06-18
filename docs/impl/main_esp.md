# ESP8266 Firmware

`firmware/esp/main.ino` implements the optional WiFi bridge described in
`docs/design/architecture_overview.md`. The current code only echoes received
serial data back to the sender. Future versions should initialise the ESP8266
module, connect to a WLAN and expose a small REST API as outlined in
`docs/design/protocol_layers.md`.
