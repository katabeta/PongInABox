#pragma once
#include <Button.h>
#include <Adafruit_IS31FL3731.h>
#include <Pot.h>

class Player{
private:
public:
  Player(Button* button, Pot* pot, Adafruit_IS31FL3731* display, uint8_t number);

  void displayNumber();

  Button* button;
  Pot* pot;
  Adafruit_IS31FL3731* display;
  uint8_t number;
  uint16_t score;
};
