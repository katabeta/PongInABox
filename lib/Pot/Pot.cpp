#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Pot.h>

//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


/**
@class Pot
    the soft potentiometer. Defines all of the necessary methods.

@param pin
    the pin of the potentiometer. Please use Reference.
@param display
    the *pointer* to the display that is associated with this potentiometer (make sure that the display, potentiometer and button all belong to the same Player).
@param inverse
    true if the output should be reverse, false otherwise

@todo use Adafruit_IS31FL3731::drawPixel() instead of Adafruit_IS31FL3731::setLEDPWM();

@author Irina Lavryonova (katabeta)
*/
Pot::Pot(uint8_t pin, Adafruit_IS31FL3731* display, bool inverse, uint8_t paddleSize){
  this->display = display;
  this->pin = pin;
  this->inverse = inverse;
  this->paddleSize = paddleSize;
}

/*public*/
/**
returns the LED number along the bottom of the display that the current status of this pot would light up.

@return the LED number (0-15) that the current status of this pot would light up.

@todo update docs for inverse
*/
int Pot::getLEDNumRead(){
  int ledNum = inverse ? 15 - 15 * getNormalizedRead() : 15 * getNormalizedRead();
  // Serial.println(String(ledNum));
  // Serial.println();
  return ledNum > 15 ? -1 : inverse ? 143 - ledNum : ledNum;
}
/**
returns the LED number along the bottom of the display that the current status of this pot would light up.
This method exists mainly for testing and you shouldn't have to use it.

@param min
    the minimum raw value possible for the pot, some margin acceptable. Please use Reference.
@param max
    the maximum raw value possible for the pot, some margin acceptable. Please use Reference.

@return the LED number (0-15) that the current status of this pot would light up.
*/
int Pot::getLEDNumRead(double min, double max){
  int ledNum = inverse ? 15 - 15 * getNormalizedRead(min, max) : 15 * getNormalizedRead(min, max);
  return ledNum > 15 ? -1 : inverse ? 143 - ledNum : ledNum;
}

/**
@todo documentation
@todo prints upto 3 on the screen on the left, but 2 on the right
*/
void Pot::drawPaddle(){
  int ledNum = getLEDNumRead();
  // if(ledNum < 16 && ledNum > -1){
  //   display->drawLine(ledNum - paddleSize/2, 0, ledNum + paddleSize/2, 0, reference.qBright);
  //   clear(ledNum);
  // }
  if(ledNum == 0 || ledNum == 143 - 15){
    ledNum++;
  } else if (ledNum == 15 || ledNum == 143){
    ledNum--;
  }
  if((ledNum > 0 && ledNum < 15) || (ledNum > 143 - 15 && ledNum < 143)){
    for(int i = -1; i < paddleSize - 1; i++){
      display->setLEDPWM(ledNum + i, reference.qBright);
    }
  }
  clear(ledNum);
}

/**
@todo documentation
*/
uint8_t Pot::getPaddleSize(void){
  return paddleSize;
}

/**
@todo documentation
*/
uint8_t Pot::getPaddlePos(void){
  return getLEDNumRead() - getPaddleSize()/2;
}


/**
for testing only
*/
void Pot::printStats(void){
  Serial.println("analog: " + String(analogRead(pin)) + " lednum: " + String(getLEDNumRead()) + " paddlepos: " + getPaddlePos());
}

/*private*/
/**
normalizes the raw reading from the potentiometer. It ranges the output from 0 to 1,
effectively giving the percentage.
See: http://stats.stackexchange.com/questions/70801/how-to-normalize-data-to-0-1-range for more details.
Feeds the getLEDNumRead() method.

@return normalized reading.
*/
double Pot::getNormalizedRead(){
  return (double)(analogRead(pin)-reference.potMin)/(reference.potMax-reference.potMin);
}
/**
normalizes the raw reading from the potentiometer. It ranges the output from 0 to 1,
effectively giving the percentage.
See: http://stats.stackexchange.com/questions/70801/how-to-normalize-data-to-0-1-range for more details.
Feeds the getLEDNumRead() method.
This method exists mainly for testing and you shouldn't have to use it.

@param min
    the minimum raw value possible for the pot, some margin acceptable. Please use Reference.
@param max
    the maximum raw value possible for the pot, some margin acceptable. Please use Reference.

@return normalized reading
*/
double Pot::getNormalizedRead(double min, double max){
  return (double)(analogRead(pin)-min)/(max-min);
}

/**
@todo documentation
*/
void Pot::clear(int ledNum){
  for(int i = -1; i < paddleSize - 1; i++){
    display->setLEDPWM(ledNum + i, 0);
  }
}
