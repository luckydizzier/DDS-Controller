#include "esp_config.h"

bool loadEspConfig(const char* path, EspConfig& cfg) {
  if (!SPIFFS.begin()) {
    return false;
  }
  File f = SPIFFS.open(path, "r");
  if (!f) {
    return false;
  }
  bool inSection = false;
  while (f.available()) {
    String line = f.readStringUntil('\n');
    line.trim();
    if (line.length() == 0 || line.startsWith("#")) continue;
    if (line.startsWith("[") && line.endsWith("]")) {
      inSection = line.equalsIgnoreCase("[ESP]");
      continue;
    }
    if (!inSection) continue;
    int eq = line.indexOf('=');
    if (eq <= 0) continue;
    String key = line.substring(0, eq); key.trim();
    String val = line.substring(eq + 1); val.trim();
    if (key.equalsIgnoreCase("ENABLE_OTA")) {
      cfg.enable_ota = (val == "true" || val == "1");
    } else if (key.equalsIgnoreCase("GPIO0_LED")) {
      cfg.gpio0_led = (val == "true" || val == "1");
    } else if (key.equalsIgnoreCase("TX_PIN")) {
      cfg.tx_pin = val.toInt();
    } else if (key.equalsIgnoreCase("RX_PIN")) {
      cfg.rx_pin = val.toInt();
    }
  }
  f.close();
  return true;
}
