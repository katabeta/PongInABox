#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <ErrorCodes.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

int nums[] = {1,2,3,4,5,6,7,8,9};

ErrorCodes errorCodes = ErrorCodes();

bool print = true;
String testString = "TESTING, testing. 123!@$";

//Printer printer = Printer();

void setup() {
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(0x74) || !ledmatrix75.begin(0x75)){
    errorCodes.writeErrorCode(errorCodes.DISP_NOT_FOUND);
    //Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix75.setRotation(0);
  ledmatrix74.setRotation(2);


}

void loop() {
  ledmatrix74.printText(5, 0, testString, 1, false, true, 4, 5);
  ledmatrix75.printText(5, 0, testString, 1, false, true, 1, 5);
}
