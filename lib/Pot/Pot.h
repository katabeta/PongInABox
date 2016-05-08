#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(int pin, Adafruit_IS31FL3731* display);
  void calibrate(uint8_t totalNumOfPots, int calButtonPin);
  int getLEDNumRead(void);
private:
  int pin;
  int max;
  int min;

  Adafruit_IS31FL3731 display;

  double sampleValue(void);
  double getNormalizedRead(void);
  bool test(void);
};
