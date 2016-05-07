#pragma once

#include <Adafruit_IS31FL3731.h>
#include <string.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

class Printer{
private:
public:
  Printer();
  void printText(uint8_t x, uint8_t y, String text, uint8_t brightness, uint8_t fontSize, Adafruit_IS31FL3731 displays[], uint16_t pause, uint8_t times);
};
