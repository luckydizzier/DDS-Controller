// ButtonManager.h
#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H
#ifdef ARDUINO
#include <Arduino.h>
#else
#include "firmware/due/mocks/Arduino.h"
#endif

#define BUTTON_PIN A0

enum ButtonCode {
  BUTTON_NONE,
  BUTTON_SELECT,
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_LEFT,
  BUTTON_RIGHT
};

class ButtonManager {
public:
  void begin();
  void update();
  bool isPressed(ButtonCode code);
  bool wasReleased(ButtonCode code);

private:
  ButtonCode current;
  ButtonCode last;
  unsigned long lastDebounceTime;
  const unsigned long debounceDelay = 50;

  ButtonCode readButton();
};

#endif
