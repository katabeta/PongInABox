#include <Arduino.h>
#include <Button.h>

uint8_t m_pin;

Button::Button(uint8_t pin){
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
  m_pin = pin;
}

bool isPressed(){
  if(digitalRead(m_pin) == HIGH){
    return true;
  } else {
    return false;
  }
}
