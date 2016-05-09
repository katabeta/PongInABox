#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Hardware.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Hardware hardware = Hardware();

uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

bool turn75 = false;
bool turn74 = false;

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");
  pinMode(hardware.dPin74, INPUT);
  pinMode(hardware.dPin75, INPUT);
  digitalWrite(hardware.dPin74, HIGH);
  digitalWrite(hardware.dPin75, HIGH);

  if(!ledmatrix74.begin(hardware.address74) || !ledmatrix75.begin(hardware.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
}


void loop(){
  if(digitalRead(hardware.dPin74) == LOW){
    turn74 ^= true;
  } if(digitalRead(hardware.dPin75) == LOW){
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
