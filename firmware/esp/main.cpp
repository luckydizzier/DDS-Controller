#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <ArduinoOTA.h>
#include "../shared/config/config.h"
#include "esp_config.h"

// See docs/hardware/esp8266.md for wiring and voltage notes.

static EspConfig cfg;
static SoftwareSerial dueSerial(cfg.rx_pin, cfg.tx_pin);

void setup() {
  Serial.begin(115200);
  SPIFFS.begin();
  loadEspConfig("/config_esp.ini", cfg);

  dueSerial.begin(ESP_BAUD_RATE);
  pinMode(PIN_ESP_LED, OUTPUT);
  pinMode(PIN_OUTPUT_CONTROL, OUTPUT);

  // GPIO0 controls WiFi status LED when OTA enabled
  if (cfg.enable_ota) {
    pinMode(PIN_ESP_GPIO0, OUTPUT);
    digitalWrite(PIN_ESP_GPIO0, LOW);
    ArduinoOTA.begin();
  } else {
    pinMode(PIN_ESP_GPIO0, INPUT); // allow Arduino to drive if needed
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin("DDS", "password");
}

void loop() {
  if (cfg.enable_ota) {
    ArduinoOTA.handle();
  }
  if (Serial.available()) {
    dueSerial.write(Serial.read());
  }
  if (dueSerial.available()) {
    Serial.write(dueSerial.read());
  }
}
