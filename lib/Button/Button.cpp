#include <Button.h>


/**
@class Button
    defines a button and a sampling method
@param pin
    the pin of this button. Please use Reference.

@author Irina Lavryonova (katabeta)
*/
Button::Button(uint8_t pin){
  this->pin = pin;
  this->lastDebounceTime = 0;
  this->lastButtonState = HIGH;
  this->debounceDelay = 50;
  this->state = true;
  this->initState = get();
}


/**
gets the current state of the button. Works like a toggle, not like a button
See https://www.arduino.cc/en/Tutorial/Debounce to learn about how this works.

@return the current state of the button

@test

@author modified from Limor Fried
*/
bool Button::get(){
  initState = state;
  int reading = digitalRead(pin);
  Serial.println("r: "+ String(reading) + " s: " + String(state) + " b: " +String(buttonState));
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

bool Button::isPressed(){
  if(get() != initState){
    initState = state;
    return true;
  } else{
    return false;
  }
}
