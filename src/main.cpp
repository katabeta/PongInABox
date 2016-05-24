#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Reference.h>
#include <Pot.h>
#include <ball.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();
Ball ball = Ball(0,0,&ledmatrix74);

Reference reference = Reference();

Pot pots[] = {Pot(reference.aPin74, &ledmatrix74), Pot(reference.aPin75, &ledmatrix75)};

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix75.setRotation(2);
}

//TODO create a calibration method
void loop(){


  //ledmatrix74.setLEDPWM(pots[0].getLEDNumRead(reference.potMin, reference.potMax), 254);
  //delay(05);
  //ledmatrix74.clear();
  //ledmatrix75.setLEDPWM(pots[1].getLEDNumRead(reference.potMin, reference.potMax), 254);
  //delay(05);
  ledmatrix74.clear();
  ball.drawBall();
  ball.move();
    //Serial.println(String(analogRead(reference.aPin75)));
}
