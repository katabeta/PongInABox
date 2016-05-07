#include <Printer.h>
#include <Adafruit_IS31FL3731.h>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

Printer::Printer(){}

void Printer::printText(uint8_t x, uint8_t y, String text, uint8_t brightness, uint8_t fontSize, Adafruit_IS31FL3731 displays[], uint16_t pause, uint8_t times){
  for(int i = 0; i < times; i++){
    for(int c = 0; c < text.length(); c++){
      for(int d = 0; d < ARRAY_SIZE(displays); d++){
        displays[d].drawChar(x + c*5, y, text[c], brightness, 0, fontSize);
      }
    }
    delay(pause);
  }
}
