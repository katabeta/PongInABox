#include <Pong.h>

uint8_t startpos = 5;
Button b1 = Button(reference.dPin74R);
Button b2 = Button(reference.dPin75R);
Adafruit_IS31FL3731 d1 = Adafruit_IS31FL3731();
Adafruit_IS31FL3731 d2 = Adafruit_IS31FL3731();
Pot pot1 = Pot(reference.aPin74, &d1, false, 3);
Pot pot2 = Pot(reference.aPin75, &d2, true, 3);
Player p1 = Player(&b1, &pot1, &d1, 1);
Player p2 = Player(&b2, &pot2, &d2, 2);
Button button = Button(reference.dPin0);
Pong pong = Pong(&p1, &p2, &button, false, 5);;

void setup(){
  Serial.begin(9600);
  Serial.println("On/Off");
  if(!d1.begin(reference.address74) || !d2.begin(reference.address75)){
    Serial.println("Error! Display not found!");
    while(1);
  }
  Serial.println("Display found");
  d2.setRotation(2);
  pong.start();
}


void loop(){
  pong.update();
}
