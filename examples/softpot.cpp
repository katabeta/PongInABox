#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();
const int pin = 0;
const int pin1 = 5;

const int max = 15;
const int min = 8;

const int max1 = 16;
const int min1 = 10;

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
  double lednum = analogRead(pin)*constant;
  double lednum1 = analogRead(pin1)*constant;
  Serial.println("Pin 0: " + String(lednum) + " Pin 5: " + String(lednum1));
  if(lednum <=16){
    lednum = 15*(lednum-min)/(max-min);
    ledmatrix74.setLEDPWM(lednum, 20, 0);
    ledmatrix74.clear();
  }

  if(lednum1 <=16){
    lednum1 = 15*(lednum1-min1)/(max1-min1);
    ledmatrix75.setLEDPWM(lednum1, 20, 0);
    ledmatrix75.clear();
  }
}
