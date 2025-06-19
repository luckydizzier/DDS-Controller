# OTA Update Procedure

This guide describes enabling and using OTA updates for the ESP8266-01 module. The state of `USE_ESP_OTA` in `config/pins.conf` determines whether GPIO0 is reserved for the bootloader.

Steps:
1. Ensure `USE_ESP=1` and `USE_ESP_OTA=1` in `config/pins.conf`.
2. Power on the ESP8266-01 and connect it to the same network as your PC.
3. Upload new firmware using the tool of your choice (`espota.py` or the web UI).
4. The Arduino Due should avoid toggling GPIO0 during the upload.

See also `docs/guides/ota_esp8266.md` for a walkthrough.
Quick reference: [`docs/configuration/ota.md`](../configuration/ota.md)
