#ifndef _PRINTTER_H_
#define _PRINTER_H_
#endif

#include <Arduino.h>
#include <Adafruit_IS31FL3731.h>
#include <string.h>


//#include <string>

class Printer{
public:
  Printer(Adafruit_IS31FL3731 printermatrix);
  void printText(String text, uint8_t lednum);

private:
  Adafruit_IS31FL3731 ledMat;
};
