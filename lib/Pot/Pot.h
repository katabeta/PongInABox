#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <Hardware.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(int pin, Adafruit_IS31FL3731* display);
  //void calibrate(uint8_t totalNumOfPots);
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
private:
  int pin;
  int max;
  int min;

  Hardware hardware = Hardware();

  //bool syncCal(Pot pots[]);

  Adafruit_IS31FL3731* display;

  //double sampleValue(void);
  double getNormalizedRead(void);
  double getNormalizedRead(double min, double max);
  //bool calTest(void);
};
