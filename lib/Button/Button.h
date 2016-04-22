#ifndef _BUTTON_H_
#define _BUTTON_H_
#endif

#include <Arduino.h>

class Button{
public:
  Button(uint8_t pin);
  bool isPressed(void);
private:
};
