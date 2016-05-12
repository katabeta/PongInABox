#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_IS31FL3731.h>

#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif


/* Constructor */
Adafruit_IS31FL3731::Adafruit_IS31FL3731(void) : Adafruit_GFX(16, 9) {

}

boolean Adafruit_IS31FL3731::begin(uint8_t addr) {
  Wire.begin();

  _i2caddr = addr;
  _frame = 0;

  // shutdown
  writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x00);

  delay(10);

  // out of shutdown
  writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_SHUTDOWN, 0x01);

  // picture mode
  writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_CONFIG, ISSI_REG_CONFIG_PICTUREMODE);

  displayFrame(_frame);

  // all LEDs on & 0 PWM
  clear(); // set each led to 0 PWM

  for (uint8_t f=0; f<8; f++) {
    for (uint8_t i=0; i<=0x11; i++)
      writeRegister8(f, i, 0xff);     // each 8 LEDs on
  }

  audioSync(false);

  return true;
}

/*custom method*/
/**
Prints the passed text on the display on which this method is called.

_If you are calling this method on a **pointer**
to a display, don't use exampleDisplay.printText(...); rather, use exampleDisplay->printText(...);_

Display coordination system (x, y)
↓y x→|  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   10  |   11  |   12  |   13  |   14  |   15  |
-----|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
8    | 0, 8 | 1, 8 | 2, 8 | 3, 8 | 4, 8 | 5, 8 | 6, 8 | 7, 8 | 8, 8 | 9, 8 | 10, 8 | 11, 8 | 12, 8 | 13, 8 | 14, 8 | 15, 8 |
7    | 0, 7 | 1, 7 | 2, 7 | 3, 7 | 4, 7 | 5, 7 | 6, 7 | 7, 7 | 8, 7 | 9, 7 | 10, 7 | 11, 7 | 12, 7 | 13, 7 | 14, 7 | 15, 7 |
6    | 0, 6 | 1, 6 | 2, 6 | 3, 6 | 4, 6 | 5, 6 | 6, 6 | 7, 6 | 8, 6 | 9, 6 | 10, 6 | 11, 6 | 12, 6 | 13, 6 | 14, 6 | 15, 6 |
5    | 0, 5 | 1, 5 | 2, 3 | 5, 5 | 4, 5 | 5, 5 | 6, 5 | 7, 5 | 8, 5 | 9, 5 | 10, 5 | 11, 5 | 12, 5 | 13, 5 | 14, 5 | 15, 5 |
4    | 0, 4 | 1, 4 | 2, 4 | 3, 4 | 4, 4 | 5, 4 | 6, 4 | 7, 4 | 8, 4 | 9, 4 | 10, 4 | 11, 4 | 12, 4 | 13, 4 | 14, 4 | 15, 4 |
3    | 0, 3 | 1, 3 | 2, 3 | 3, 3 | 4, 3 | 5, 3 | 6, 3 | 7, 3 | 8, 3 | 9, 3 | 10, 3 | 11, 3 | 12, 3 | 13, 3 | 14, 3 | 15, 3 |
2    | 0, 2 | 1, 2 | 2, 2 | 3, 2 | 4, 2 | 5, 2 | 6, 2 | 7, 2 | 8, 2 | 9, 2 | 10, 2 | 11, 2 | 12, 2 | 13, 2 | 14, 2 | 15, 2 |
1    | 0, 1 | 1, 1 | 2, 1 | 3, 1 | 4, 1 | 5, 1 | 6, 1 | 7, 1 | 8, 1 | 9, 1 | 10, 1 | 11, 1 | 12, 1 | 13, 1 | 14, 1 | 15, 1 |
0    | 0, 0 | 1, 0 | 2, 0 | 3, 0 | 4, 0 | 5, 0 | 6, 0 | 7, 0 | 8, 0 | 9, 0 | 10, 0 | 11, 0 | 12, 0 | 13, 0 | 14, 0 | 15, 0 |


@param x
    the x coordinate of the bottom left of your text, 0 is usually sufficient
@param y
    the y coordinate of the bottom left of your text, 0 is usually sufficient
@param text
    the text that you would like to print
@param brightness
    how bright you would like to display your text (0-254, where 0 is not lit up at all and 254 is the brightest)
@param clearAfter
    do you want to erase all of the text after it is done printing? You can do this manually as well by calling clear()
@param scroll
    do you want the text to scroll?
@param scrollSpeed
    the speed with which you want the text to scroll, with 1 being the lowest. The units for this variable are arbitrary
@param spacing
    the spacing, in pixels, that you want between each character of your text. 5 is usually sufficient. A spacing
    of 0 will result in every character being drawn over the others.

@todo can only print to one display at a time. Make it so that the update can be alternated
@todo might need to update the whole display at once, not scroll
@todo may need to scroll with blocks, not by pixel column to allow for update times of both displays and for an easy time of reading
@todo is background brightness needed?
*/
void Adafruit_IS31FL3731::printText(uint8_t x, uint8_t y, String text, uint8_t brightness,
  bool clearAfter, bool scroll, uint8_t scrollSpeed, uint8_t spacing){
  if(scroll){
    for(uint8_t s = 0; s < text.length() * spacing + 10 * scrollSpeed; s++){
      for(uint8_t i = 0; i < text.length(); i++){
        Adafruit_GFX::drawChar(x + i*spacing - s * scrollSpeed, y, text[i], brightness, 0, 1);
      }
      //clear();
    }
    delay(50);
    if(clearAfter){
      clear();
    }
  } else{
    for(uint8_t i = 0; i < text.length(); i++){
      Adafruit_GFX::drawChar(x + i*spacing, y, text[i], brightness, 0, 1);
    }
  }
}


void Adafruit_IS31FL3731::clear(void) {
  // all LEDs on & 0 PWM

  selectBank(_frame);

  for (uint8_t i=0; i<6; i++) {
    Wire.beginTransmission(_i2caddr);
    Wire.write((byte) 0x24+i*24);
    // write 24 bytes at once
    for (uint8_t j=0; j<24; j++) {
      Wire.write((byte) 0);
    }
    Wire.endTransmission();
  }
}

void Adafruit_IS31FL3731::setLEDPWM(uint8_t lednum, uint8_t pwm, uint8_t bank) {
  if (lednum >= 144) return;
  writeRegister8(bank, 0x24+lednum, pwm);
}


void Adafruit_IS31FL3731::drawPixel(int16_t x, int16_t y, uint16_t color) {
 // check rotation, move pixel around if necessary
  switch (getRotation()) {
  case 1:
    _swap_int16_t(x, y);
    x = 16 - x - 1;
    break;
  case 2:
    x = 16 - x - 1;
    y = 9 - y - 1;
    break;
  case 3:
    _swap_int16_t(x, y);
    y = 9 - y - 1;
    break;
  }

  if ((x < 0) || (x >= 16)) return;
  if ((y < 0) || (y >= 9)) return;
  if (color > 255) color = 255; // PWM 8bit max

  setLEDPWM(x + y*16, color, _frame);
  return;
}

void Adafruit_IS31FL3731::setFrame(uint8_t f) {
  _frame = f;
}

void Adafruit_IS31FL3731::displayFrame(uint8_t f) {
  if (f > 7) f = 0;
  writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_PICTUREFRAME, f);
}


void Adafruit_IS31FL3731::selectBank(uint8_t b) {
 Wire.beginTransmission(_i2caddr);
 Wire.write((byte)ISSI_COMMANDREGISTER);
 Wire.write(b);
 Wire.endTransmission();
}

void Adafruit_IS31FL3731::audioSync(boolean sync) {
  if (sync) {
    writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_AUDIOSYNC, 0x1);
  } else {
    writeRegister8(ISSI_BANK_FUNCTIONREG, ISSI_REG_AUDIOSYNC, 0x0);
  }
}

/*************/
void Adafruit_IS31FL3731::writeRegister8(uint8_t b, uint8_t reg, uint8_t data) {
  selectBank(b);

  Wire.beginTransmission(_i2caddr);
  Wire.write((byte)reg);
  Wire.write((byte)data);
  Wire.endTransmission();
  //Serial.print("$"); Serial.print(reg, HEX);
  //Serial.print(" = 0x"); Serial.println(data, HEX);
}

uint8_t  Adafruit_IS31FL3731::readRegister8(uint8_t bank, uint8_t reg) {
 uint8_t x;

 selectBank(bank);

 Wire.beginTransmission(_i2caddr);
 Wire.write((byte)reg);
 Wire.endTransmission();

 Wire.beginTransmission(_i2caddr);
 Wire.requestFrom(_i2caddr, (byte)1);
 x = Wire.read();
 Wire.endTransmission();

// Serial.print("$"); Serial.print(reg, HEX);
//  Serial.print(": 0x"); Serial.println(x, HEX);

  return x;
}
