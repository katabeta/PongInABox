#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <ErrorCodes.h>
#include <Reference.h>

Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

int nums[] = {1,2,3,4,5,6,7,8,9};

ErrorCodes errorCodes = ErrorCodes();

bool print = true;
String testString = "TESTING, testing. 123!@$";

Reference reference = Reference();

void setup() {
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    errorCodes.writeErrorCode(errorCodes.DISP_NOT_FOUND);
    //Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix75.setRotation(0);
  ledmatrix74.setRotation(2);


}

void loop() {
  ledmatrix74.printText(testString, 1, false, reference.minBright);
  ledmatrix75.printText(testString, 1, false, reference.minBright);
}
