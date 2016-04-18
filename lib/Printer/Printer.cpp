#include <Arduino.h>
#include <Printer.h>
#include <Adafruit_IS31FL3731.h>
#include <string.h>

/*Constructor*/
Printer::Printer(Adafruit_IS31FL3731 ledmat){
  ledMat = ledmat;
}


void printText(String text, uint8_t lednum){
  for(uint8_t i = 0; i < text.length(); i++){
    ledMat.drawChar(text.substring(i, i+2));
  }
}
