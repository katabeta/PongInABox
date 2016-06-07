#pragma once

#include <Arduino.h>

class Button{
private:
  uint8_t pin; /**< */
  uint8_t lastDebounceTime; /**< */
  uint16_t lastButtonState; /**< */
  uint8_t debounceDelay; /**< */
  uint16_t buttonState; /**< @todo might be null on the first run, so impossible to compare and it will never be set*/
  bool state;
  bool initState;

public:
  Button(uint8_t pin);
  bool get(void);
  bool isPressed(void);
};
