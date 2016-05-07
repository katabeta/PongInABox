#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();
const int pin0 = 0;
const int pin5 = 5;

const int max0 = 15;
const int min0 = 8;

const int max5 = 16;
const int min5 = 10;

double const constant = 0.0216;

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(0x74) || !ledmatrix75.begin(0x75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(0);
}

//TODO create a calibration method
void loop(){
  double lednum0 = analogRead(pin0)*constant;
  double lednum5 = analogRead(pin5)*constant;
  Serial.println("Pin 0: " + String(lednum0) + " Pin 5: " + String(lednum5));
  if(lednum0 <=16){
    lednum0 = 15*(lednum0-min0)/(max0-min0);
    ledmatrix74.setLEDPWM(lednum0, 20, 0);
    ledmatrix74.clear();
  }

  if(lednum5 <=16){
    lednum5 = 15*(lednum5-min5)/(max5-min5);
    ledmatrix75.setLEDPWM(lednum5, 20, 0);
    ledmatrix75.clear();
  }
}
