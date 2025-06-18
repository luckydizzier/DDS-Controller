#include <Arduino.h>
#include <LiquidCrystal.h>
#include "ButtonManager.h"
#include "EEPROMManager.h"
#include "DDSDriver.h"
#include "CommandParser.h"
#include "MenuSystem.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
ButtonManager buttons;
EEPROMManager eeprom;
DDSDriver dds;
MenuSystem menu(lcd, buttons, eeprom, dds);
CommandParser parser;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);

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
}
