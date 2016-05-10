#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Reference.h>
#include <Button.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Reference reference = Reference();

uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

bool turn75 = false;
bool turn74 = false;

Button b1 = Button(reference.dPin74);
Button b2 = Button(reference.dPin75);

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");
  pinMode(reference.dPin74, INPUT);
  pinMode(reference.dPin75, INPUT);
  digitalWrite(reference.dPin74, HIGH);
  digitalWrite(reference.dPin75, HIGH);

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
}


void loop(){
  if(b1.get()){
    turn74 ^= true;
  } if(b1.get()){
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
