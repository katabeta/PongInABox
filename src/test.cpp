#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Reference.h>
#include <Pot.h>
#include <Player.h>
#include <Button.h>
#include <Ball.h>


Adafruit_IS31FL3731 ledmatrix74 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 ledmatrix75 = Adafruit_IS31FL3731();

Reference reference = Reference();

Pot pot = Pot(reference.aPin74, &ledmatrix74, false, 3);
Pot pot1 = Pot(reference.aPin75, &ledmatrix75, true, 3);
Button b1 = Button(reference.dPin74R);
Button b2 = Button(reference.dPin75R);

Player player1 = Player(&b1, &pot, &ledmatrix74, 1);
Player player2 = Player(&b2, &pot1, &ledmatrix75, 2);

Ball ball = Ball(&player1, &player2, 150);

int lastTime=0;
void setup(){
  Serial.println("Enter setup");
  Serial.begin(9600);
  Serial.println("On/Off");

  if(!ledmatrix74.begin(reference.address74) || !ledmatrix75.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  ledmatrix74.setRotation(2);
  //Test orientation
   //ledmatrix74.printText("Tt", 1, false, 1);
   //ledmatrix75.printText("Tt", 1, false, 1);
   //ledmatrix74.drawPixel(0, 0, 2);
   ledmatrix74.drawPixel(0, 0, 2);
  //  ledmatrix74.setLEDPWM(0, 3);
  //  ledmatrix75.setLEDPWM(143, 3);
   //ledmatrix74.drawLine(0, 0, 3, 0, 1);
}


void loop(){
  player1.pot->drawPaddle();
  player2.pot->drawPaddle();

  ball.draw();

  //game.countdown();
  //pot.test();
}
