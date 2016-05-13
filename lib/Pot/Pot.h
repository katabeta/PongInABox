#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <Reference.h>

class Adafruit_IS31FL3731;

class Pot{
public:
  Pot(uint8_t pin, Adafruit_IS31FL3731* display, bool inverse); /**< Constructor for the class */
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
  bool test(void);
private:
  int pin; /**< holds the pin of the pot. If you are setting this value, please use Reference */
  int max; /**< holds the maximum possible raw value of the pot. If you are setting this value, please use Reference */
  int min; /**< holds the minimum possible raw value of the pot. If you are setting this value, please use Reference */
  bool inverse; /**< holds whether this pot is reversed */

  Reference reference = Reference(); /**< Initializes the constants library */

  Adafruit_IS31FL3731* display; /**< Holds the pointer to the display that is associated with this pot */

  double getNormalizedRead(void);
  double getNormalizedRead(double min, double max);
};
