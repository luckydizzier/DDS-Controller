// ButtonManager.cpp
#include "ButtonManager.h"

void ButtonManager::begin() {
  pinMode(BUTTON_PIN, INPUT);
  current = BUTTON_NONE;
  last = BUTTON_NONE;
  lastDebounceTime = millis();
}

void ButtonManager::update() {
  ButtonCode reading = readButton();
  if (reading != last) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    current = reading;
  }
  last = reading;
}

bool ButtonManager::isPressed(ButtonCode code) {
  return (current == code);
}

bool ButtonManager::wasReleased(ButtonCode code) {
  return (last == code && current == BUTTON_NONE);
}

ButtonCode ButtonManager::readButton() {
  int val = analogRead(BUTTON_PIN);
  if (val < 60)   return BUTTON_RIGHT;
  if (val < 200)  return BUTTON_UP;
  if (val < 400)  return BUTTON_DOWN;
  if (val < 600)  return BUTTON_LEFT;
  if (val < 800)  return BUTTON_SELECT;
  return BUTTON_NONE;
}
