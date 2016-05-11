#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <Reference.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(uint8_t pin, Adafruit_IS31FL3731* display); /**< Constructor for the class */
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
  bool test(void);
private:
  int pin; /**< Holds the pin of the pot */
  int max; /**< Holds the maximum possible raw value of the pot */
  int min; /**< Holds the minimum possible raw value of the pot */

  Reference reference = Reference(); /**< Initializes the constants library */

  Adafruit_IS31FL3731* display; /**< Holds the pointer to the display that is associated with this pot */

  double getNormalizedRead(void);
  double getNormalizedRead(double min, double max);
};
