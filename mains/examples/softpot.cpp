#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Hardware.h>
#include <Pot.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Hardware hardware = Hardware();

Pot pots[] = {Pot(hardware.aPin74, &ledmatrix74), Pot(hardware.aPin75, &ledmatrix75)};

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(hardware.address74) || !ledmatrix75.begin(hardware.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(0);
}

//TODO create a calibration method
void loop(){
  ledmatrix74.setLEDPWM(pots[0].getLEDNumRead(hardware.potMin, hardware.potMax), 2); //TODO this display is dimmer for some reason
  ledmatrix75.setLEDPWM(pots[1].getLEDNumRead(hardware.potMin, hardware.potMax), 2);
  ledmatrix74.clear();
  ledmatrix75.clear();

  //Serial.println(String(analogRead(hardware.aPin75)));
}
