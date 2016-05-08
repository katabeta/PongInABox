#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>

Pot pot = Pot(0);
Pot pot1 = Pot(5);

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Adafruit_IS31FL3731 displays[] = {ledmatrix74, ledmatrix75};

uint8_t calButtonPin = 7;

void setup() {
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(0x74) || !ledmatrix75.begin(0x75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(0);

  pot.calibrate(ledmatrix74, 2, calButtonPin);
  pot1.calibrate(ledmatrix75, 2, calButtonPin);

}

void loop() {
  double lednum0 = pot.getLEDNumRead();
  double lednum5 = pot1.getLEDNumRead();
  Serial.println("Pin 0: " + String(lednum0) + " Pin 5: " + String(lednum5));
  if(lednum0 <=16){
    ledmatrix74.setLEDPWM(lednum0, 20, 0);
    ledmatrix74.clear();
  }

  if(lednum5 <=16){
    ledmatrix75.setLEDPWM(lednum5, 20, 0);
    ledmatrix75.clear();
  }
}
