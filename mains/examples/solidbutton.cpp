#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

const int pin74 = 7;
const int pin75 = 8;
uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

bool turn75 = false;
bool turn74 = false;

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");
  pinMode(pin74, INPUT);
  pinMode(pin75, INPUT);
  digitalWrite(pin74, HIGH);
  digitalWrite(pin75, HIGH);

  if(!ledmatrix74.begin(0x74) || !ledmatrix75.begin(0x75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
}


void loop(){
  if(digitalRead(pin74) == LOW){
    turn74 ^= true;
  } if(digitalRead(pin75) == LOW){
    turn75 ^= true;
  }


  if(turn74){
    for(uint8_t x = 0; x < 16; x++){
      for(uint8_t y = 0; y < 9; y++){
        ledmatrix74.drawPixel(x, y, 1);
      }
    }
  } else {
    ledmatrix74.clear();
  }
  if(turn75){
    for(uint8_t x = 0; x < 16; x++){
      for(uint8_t y = 0; y < 9; y++){
        ledmatrix75.drawPixel(x, y, 1);
      }
    }
  } else {
    ledmatrix75.clear();
  }
  delay(50);
}
