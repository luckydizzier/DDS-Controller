# ESP8266-01 OTA Update Guide

This guide describes how to update the ESP8266-01 firmware over the air.

1. Ensure the module is powered with **3.3V** and connected to a stable WiFi network.
2. Upload the new firmware via the web update interface or the ESP8266 OTA Python script.
3. During update the Arduino Due should not reset or pull GPIO0 low.
4. The ESP8266-01 will reboot automatically after the upload completes.

The Arduino Due plays no role in OTA updates. The ESP module manages the entire process independently.
