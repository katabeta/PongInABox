#include <Button.h>

Button::Button(uint8_t pin){
  this->pin = pin;
  this->lastDebounceTime = 0;
  this->lastButtonState = LOW;
  this->debounceDelay = 50;
  this->state = false;
}


//TODO untested

//https://www.arduino.cc/en/Tutorial/Debounce
bool Button::get(){
  int reading = digitalRead(pin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        state = !state;
      }
    }
  }
  lastButtonState = reading;
  return state;
}
