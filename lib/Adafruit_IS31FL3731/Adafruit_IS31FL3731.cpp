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
void Adafruit_IS31FL3731::printText(uint8_t x, uint8_t y, String text, uint8_t brightness,
  bool clearAfter, bool scroll, uint8_t multiplier, uint8_t spacing){
  if(scroll){
    for(uint8_t s = 0; s < text.length() * multiplier; s++){
      for(uint8_t i = 0; i < text.length(); i++){
        Adafruit_GFX::drawChar(x + i*spacing - s * multiplier, y, text[i], brightness, 0, 1);
        
      }
      clear();
    }
    delay(50);
  } else{
    for(uint8_t i = 0; i < text.length(); i++){
      Adafruit_GFX::drawChar(x + i*spacing, y, text[i], brightness, 0, 1);
    }
  }
  if(clearAfter){
    clear();
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
