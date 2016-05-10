#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Pot.h>

//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


Pot::Pot(int pin, Adafruit_IS31FL3731* display){
  this->display = display;
  this->pin = pin;
}

/*public*/
int Pot::getLEDNumRead(){
  int ledNum = 15 * getNormalizedRead();
  return ledNum > 15 ? -1 : ledNum;
}
int Pot::getLEDNumRead(double min, double max){
  int ledNum = 15 * getNormalizedRead(min, max);
  return ledNum > 15 ? -1 : ledNum;
}

//TODO untested
bool Pot::test(){
  display->printText(0, 0, "Test", 10, true, false, 0, 5);
  delay(500);
  display->printText(0, 0, "Press button when done", 10, true, true, 2, 5);
  delay(500);
  bool done = false; //TODO can remove and return true
  while(!done){
    display->setLEDPWM(getLEDNumRead(), 254);
    done = digitalRead(pin);
  }
  return done;
}



/*private*/
double Pot::getNormalizedRead(){
  return (analogRead(pin)-reference.potMin)/(reference.potMax-reference.potMin);
}
double Pot::getNormalizedRead(double min, double max){
  return (analogRead(pin)-min)/(max-min);
}
