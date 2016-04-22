#ifndef _PRINTTER_H_
#define _PRINTER_H_
#endif


#include <Adafruit_IS31FL3731.h>
#include <string.h>


//#include <string>

class Printer /*: Adafruit_GFX*/{
public:
  Printer(Adafruit_IS31FL3731 ledmat);
  void printText(String text, uint8_t lednum);

private:
};
