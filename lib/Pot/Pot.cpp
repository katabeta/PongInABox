#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Pot.h>

//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


/**
@class Pot
    The soft potentiometer. Defines all of the necessary methods
@param pin pin of the potentiometer
@param display the display that is associated with this potentiometer (make sure that the display, potentiometer and button all belong to the same player)
*/
Pot::Pot(uint8_t pin, Adafruit_IS31FL3731* display){
  this->display = display;
  this->pin = pin;
}

/*public*/
/**
Returns the LED number along the bottom of the display the status of this pot would like up
Public.
@return the LED number (0-15) that the current status of the pot would like up
*/
int Pot::getLEDNumRead(){
  int ledNum = 15 * getNormalizedRead();
  return ledNum > 15 ? -1 : ledNum;
}
/**
Returns the LED number along the bottom of the display the status of this pot would like up
Public.
@param min the minimum raw value possible for the pot, some margin acceptable
@param max the maximum raw value possible for the pot, some margin acceptable
@return the LED number (0-15) that the current status of the pot would like up
*/
int Pot::getLEDNumRead(double min, double max){
  int ledNum = 15 * getNormalizedRead(min, max);
  return ledNum > 15 ? -1 : ledNum;
}

/**
Allows the player to test that the pot is working as expected. When
the player is done testing, they can press their button to stop.
Public.
@TODO untested
@return whether the test has finished
*/
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
/**
Normalizes the raw reading from the potentiometer. It ranges the output from 0 to 1,
effectively giving the percentage.
See: http://stats.stackexchange.com/questions/70801/how-to-normalize-data-to-0-1-range for more details.
Feeds the getLEDNumRead() method.
Private.
@return normalized reading
*/
double Pot::getNormalizedRead(){
  return (analogRead(pin)-reference.potMin)/(reference.potMax-reference.potMin);
}
/**
Normalizes the raw reading from the potentiometer. It ranges the output from 0 to 1,
effectively giving the percentage.
See: http://stats.stackexchange.com/questions/70801/how-to-normalize-data-to-0-1-range for more details.
Feeds the getLEDNumRead() method.
Private.
@param min the minimum raw value possible for the pot, some margin acceptable
@param max the maximum raw value possible for the pot, some margin acceptable
@return normalized reading
*/
double Pot::getNormalizedRead(double min, double max){
  return (analogRead(pin)-min)/(max-min);
}
