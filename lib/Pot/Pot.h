#pragma once
#include <Wire.h>
#include <Printer.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(int pin);
  void calibrate(Adafruit_IS31FL3731 displays[], uint8_t totalNumOfPots, int calButtonPin);
  int getLEDNumRead(void);
private:
  int pin;
  int max;
  int min;

  Printer printer;

  bool isFirstCalDone;
  bool isSecondCalDone;
  bool isTwoCalDone;

  double sampleValue(Adafruit_IS31FL3731 displays[]);
  double getNormalizedRead(void);
};
