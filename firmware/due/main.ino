#include <Arduino.h>
#include <LiquidCrystal.h>
#include "ButtonManager.h"
#include "EEPROMManager.h"
#include "DDSDriver.h"
#include "CommandParser.h"
#include "MenuSystem.h"
#include "../shared/config/config.h"
#ifdef USE_ESP
#ifdef ARDUINO
#include <SoftwareSerial.h>
#else
#include "mocks/SoftwareSerial.h"
#endif
#include "esp_protocol.h"
#endif

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
ButtonManager buttons;
EEPROMManager eeprom;
DDSDriver dds;
MenuSystem menu(lcd, buttons, eeprom, dds);
CommandParser parser;
#ifdef USE_ESP
SoftwareSerial espSerial(PIN_ESP_RX, PIN_ESP_TX);
#endif

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
#ifdef USE_ESP
  espSerial.begin(ESP_BAUD_RATE);
  esp_begin(espSerial, parser);
  pinMode(PIN_ESP_LED, OUTPUT);
#if !USE_ESP_OTA
  pinMode(PIN_ESP_GPIO0, OUTPUT);
  digitalWrite(PIN_ESP_GPIO0, HIGH);
#endif
#endif

  buttons.begin();
  eeprom.begin();
  dds.begin();
  parser.begin(dds, eeprom);

  pinMode(OUTPUT_CONTROL_PIN, OUTPUT);
  digitalWrite(OUTPUT_CONTROL_PIN, LOW);
}

void loop() {
  menu.update();

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    Serial.println(parser.handleCommand(cmd));
  }

  if (Serial1.available()) {
    String cmd = Serial1.readStringUntil('\n');
    Serial1.println(parser.handleCommand(cmd));
  }
#ifdef USE_ESP
  esp_handle();
#endif
}
