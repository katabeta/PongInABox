#pragma once
#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <Reference.h>

class Adafruit_IS31FL3731;

class Pot{
public:
<<<<<<< HEAD
  Pot(uint8_t pin, Adafruit_IS31FL3731* display, bool inverse, uint8_t paddleSize); /**< Constructor for the class */
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
  bool test(void);
  void drawPaddle();
  uint8_t getPaddleSize(void);
  uint8_t getPaddlePos(void);
  void printStats(void);
=======
  Pot(uint8_t pin, Adafruit_IS31FL3731* display); /**< Constructor for the class */
  int getLEDNumRead(void);
  int getLEDNumRead(double min, double max);
  bool test(void);
  void drawPaddle(void);
  int getCoord(void);
  void clear(int x0, int y0, int x1, int y1);
>>>>>>> 0df60bc24b96fcefa4670f02c5314b11fca55191
private:
  int pin; /**< holds the pin of the pot. If you are setting this value, please use Reference */
  int max; /**< holds the maximum possible raw value of the pot. If you are setting this value, please use Reference */
  int min; /**< holds the minimum possible raw value of the pot. If you are setting this value, please use Reference */
  bool inverse; /**< holds whether this pot is reversed */
  uint8_t paddleSize;

  Reference reference = Reference(); /**< Initializes the constants library */

  Adafruit_IS31FL3731* display; /**< Holds the pointer to the display that is associated with this pot */

  double getNormalizedRead(void);
  double getNormalizedRead(double min, double max);

  void clear(int ledNum);
};
