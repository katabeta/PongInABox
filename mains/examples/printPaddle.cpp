#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Reference.h>
#include <Pot.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Reference reference = Reference();

Pot pot = Pot(reference.aPin74, &ledmatrix74, false, 3);
Pot pot1 = Pot(reference.aPin75, &ledmatrix75, false, 3);

bool turn75 = false;
bool turn74 = false;

uint8_t startpos = 5;

void setup(){
  Serial.begin(9600);
  //Serial.println("Enter setup");
  Serial.println("On/Off");

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(0);
}


void loop(){
  //Serial.println("Enter loop");
  pot.drawPaddle();
  pot1.drawPaddle();
}
