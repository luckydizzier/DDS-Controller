#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "../shared/config/config.h"
#include "../shared/config/pins.h"

struct ConfigState {
  bool use_esp = USE_ESP;
  bool use_esp_ota = USE_ESP_OTA;
  int pin_dds_wclk = PIN_DDS_WCLK;
  int pin_dds_fqud = PIN_DDS_FQUD;
  int pin_dds_data = PIN_DDS_DATA;
  int pin_dds_reset = PIN_DDS_RESET;
  int pin_esp_rx = PIN_ESP_RX;
  int pin_esp_tx = PIN_ESP_TX;
  int pin_esp_led = PIN_ESP_LED;
  int pin_output_control = PIN_OUTPUT_CONTROL;
  int pin_esp_gpio0 = PIN_ESP_GPIO0;
} cfg;

ESP8266WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
#include "web_ui/index.html"
)rawliteral";

void handle_root() {
  server.send_P(200, "text/html", index_html);
}

void handle_get_config() {
  String json = "{";
  json += "\"USE_ESP\":" + String(cfg.use_esp ? 1 : 0) + ",";
  json += "\"USE_ESP_OTA\":" + String(cfg.use_esp_ota ? 1 : 0) + ",";
  json += "\"PIN_ESP_RX\":" + String(cfg.pin_esp_rx) + ",";
  json += "\"PIN_ESP_TX\":" + String(cfg.pin_esp_tx) + ",";
  json += "\"PIN_ESP_LED\":" + String(cfg.pin_esp_led) + ",";
  json += "\"PIN_OUTPUT_CONTROL\":" + String(cfg.pin_output_control) + ",";
  json += "\"PIN_ESP_GPIO0\":" + String(cfg.pin_esp_gpio0);
  json += "}";
  server.send(200, "application/json", json);
}

void handle_get_pins() {
  String json = "{";
  json += "\"LED\":" + String(digitalRead(cfg.pin_esp_led)) + ",";
  json += "\"OUT\":" + String(digitalRead(cfg.pin_output_control));
  json += "}";
  server.send(200, "application/json", json);
}

void handle_set_pins() {
  String body = server.arg("plain");
  if (body.indexOf("\"LED\":1") != -1) {
    digitalWrite(cfg.pin_esp_led, HIGH);
  } else if (body.indexOf("\"LED\":0") != -1) {
    digitalWrite(cfg.pin_esp_led, LOW);
  }
  if (body.indexOf("\"OUT\":1") != -1) {
    digitalWrite(cfg.pin_output_control, HIGH);
  } else if (body.indexOf("\"OUT\":0") != -1) {
    digitalWrite(cfg.pin_output_control, LOW);
  }
  handle_get_pins();
}

void handle_status() {
  String json = "{";
  json += "\"wifi\":" + String(WiFi.status() == WL_CONNECTED ? 1 : 0) + ",";
  json += "\"ota\":" + String(cfg.use_esp_ota ? 1 : 0);
  json += "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(ESP_BAUD_RATE);
  pinMode(cfg.pin_esp_led, OUTPUT);
  pinMode(cfg.pin_output_control, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin("DDS", "password");

  server.on("/", handle_root);
  server.on("/api/config", HTTP_GET, handle_get_config);
  server.on("/api/pins", HTTP_GET, handle_get_pins);
  server.on("/api/pins", HTTP_POST, handle_set_pins);
  server.on("/api/status", HTTP_GET, handle_status);
  server.begin();
  Serial.println("ESP web server ready");
}

void loop() {
  server.handleClient();
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    Serial1.println(line);
  }
  if (Serial1.available()) {
    String line = Serial1.readStringUntil('\n');
    Serial.println(line);
  }
}
