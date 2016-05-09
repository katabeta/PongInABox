#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Hardware.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Hardware hardware = Hardware();

bool turn75 = false;
bool turn74 = false;

uint8_t startpos = 5;

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
  ledmatrix74.setRotation(2);
}


void loop(){
  for(uint8_t x = 0; x < 150; x++){
    ledmatrix74.drawChar(startpos - x, 0, 'r', 1, 0, 1);
    ledmatrix75.drawChar(startpos - x, 0, 'r', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 5 - x, 0, 'e', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 5 - x, 0, 'e', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 10 - x, 0, 'a', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 10 - x, 0, 'a', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 15 - x, 0, 'd', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 15 - x, 0, 'd', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 20 - x, 0, 'y', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 20 - x, 0, 'y', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 25 - x, 0, ' ', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 25 - x, 0, ' ', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 30 - x, 0, '?', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 30 - x, 0, '?', 1, 0, 1);
    ledmatrix74.drawChar(startpos + 35 - x, 0, '1', 1, 0, 1);
    ledmatrix75.drawChar(startpos + 35 - x, 0, '1', 1, 0, 1);
    if (x == 0) {
      delay(1000);
    }
  }

  for(uint8_t x = 0; x < 150; x++){

    if (x == 0) {
      delay(1000);
    }
  }
}
