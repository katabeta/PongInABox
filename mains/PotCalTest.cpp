#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>
#include <Reference.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Reference reference = Reference();

Pot pots[] = {Pot(reference.dPin74, &ledmatrix74), Pot(reference.dPin75, &ledmatrix75)};

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

}

void loop() {
  double lednum0 = pots[0].getLEDNumRead();
  double lednum5 = pots[1].getLEDNumRead();

  Serial.println("Pin 0: " + String(lednum0) + " Pin 5: " + String(lednum5));

  ledmatrix74.setLEDPWM(lednum0, 20, 0);
  ledmatrix74.clear();
  ledmatrix75.setLEDPWM(lednum5, 20, 0);
  ledmatrix75.clear();
}
