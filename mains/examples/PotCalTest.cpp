#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>
#include <Reference.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Reference reference = Reference();

Pot pots[] = {Pot(reference.aPin74, &ledmatrix74, false, 3), Pot(reference.aPin75, &ledmatrix75, true, 3)};

uint8_t calButtonPin = 7;

void setup() {
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(2);

  // pots[0].calibrate(2, calButtonPin);
  // pots[1].calibrate(2, calButtonPin);
  //Test orientation
  //  ledmatrix74.printText("Tt", 1, false, 1);
  //  ledmatrix75.printText("Tt", 1, false, 1);
   //ledmatrix74.drawPixel(0, 0, 2);
   //ledmatrix75.drawPixel(0, 0, 2);
  //  ledmatrix74.setLEDPWM(0, 3);
  //  ledmatrix75.setLEDPWM(143-15, 3);
   //ledmatrix74.drawLine(0, 0, 3, 0, 1);

}

void loop() {
  int lednum0 = pots[0].getLEDNumRead();
  int lednum5 = pots[1].getLEDNumRead();

  //Serial.println("Pin 0: " + String(lednum0) + " Pin 5: " + String(lednum5));
  Serial.println("Pin 0: " + String(pots[0].getAnalogRead()) + " Pin 5: " + String(pots[1].getAnalogRead()));

  ledmatrix74.setLEDPWM(lednum0, 20, 0);
  ledmatrix74.clear();
  ledmatrix75.setLEDPWM(lednum5, 20, 0);
  ledmatrix75.clear();
}
