#include <Printer.h>

Adafruit_IS31FL3731 m_ledmat;

/*Constructor*/
Printer::Printer(Adafruit_IS31FL3731 ledmat){
  m_ledmat = ledmat;
}


void printText(String text, uint8_t x, uint8_t y, uint8_t brightness){
  for(uint8_t i = 0; i < text.length(); i++){
    m_ledmat.drawChar(x, y, text[i], brightness, 0, 1);
  }
}
