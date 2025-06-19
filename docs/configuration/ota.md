# OTA Update Instructions

OTA updates rely on the ESP8266-01 bootloader pin **GPIO0**. When `USE_ESP_OTA` is set, keep this pin free from other hardware so the module can enter boot mode. Toggle the pin low only during firmware upload.

1. Enable `USE_ESP=1` and `USE_ESP_OTA=1` in `config/pins.conf`.
2. Connect the ESP8266-01 to your WiFi network.
3. Upload new firmware through the web interface or `espota.py`.
4. After a successful upload the module restarts automatically.

For a detailed walkthrough see `docs/guides/ota_esp8266.md`.
