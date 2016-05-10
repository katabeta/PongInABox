#pragma once

#include <Arduino.h>

class Button{
private:
  uint8_t pin;
  uint8_t lastDebounceTime;
  uint16_t lastButtonState;
  uint8_t debounceDelay;
  uint16_t buttonState;
  bool state;
  
public:
  Button(uint8_t pin);
  bool get(void);
};
