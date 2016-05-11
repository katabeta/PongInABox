#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <Reference.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(uint8_t pin, Adafruit_IS31FL3731* display); /*</class Pot with stuff*/
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
  bool test(void);
private:
  int pin;
  int max;
  int min;

  Reference reference = Reference();

  //bool syncCal(Pot pots[]);

  Adafruit_IS31FL3731* display;

  //double sampleValue(void);
  double getNormalizedRead(void);
  double getNormalizedRead(double min, double max);
  //bool calTest(void);
};
