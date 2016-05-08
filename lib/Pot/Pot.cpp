#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


Pot::Pot(int pin, Adafruit_IS31FL3731* display){
  this->display = display; // TODO how to fix this?
  this->pin = pin;
}

void Pot::calibrate(uint8_t totalNumOfPots, int calButtonPin){
  for(int i = 0; i < totalNumOfPots; i++){
      //Calibrate one of the pots
      //Touch top of the pot and record the value. Make sure to sample for a little bit to get an accurate value.
      //Draw instructions for the user
      do{
        display.printText(0, 0, "Press and hold the top of one pot", 1, true, true, 0, 5);
        this->max = sampleValue();
        display.printText(0, 0, "Press and hold the bottom of one pot", 1, true, true, 0, 5);
        this->min = sampleValue();
      } while(false);
      //Touch bottom of the pot and record the value. Make sure to sample for a little bit to get an accurate value.
      //Draw instructions for the user
      /**/
      //Calibrate another one of the pots
      //Calibrate the pots when used together
  }
}

double Pot::sampleValue(){
  delay(2000); //2 secs
  display.printText(0, 0, "Sample Start", 1, true, true, 0, 5);
  double sum = 0;
  for(int i = 0; i < 50; i++){
    sum += analogRead(pin);
  }
  display.printText(0, 0, "OK!", 1, true, true, 0, 5);
  return sum/50;
}

double Pot::getNormalizedRead(){
  return (analogRead(pin)-min)/(max-min);
}

int Pot::getLEDNumRead(){
  return 15*getNormalizedRead();
}

bool Pot::test(){
  display.printText(0, 0,
    "Run your finger all alone the pot and check that the led light up all alone the bottom row",
    1, true, true, 1, 5);
  while(/*time for this test*/ false){
    display.setLEDPWM(getLEDNumRead(), 1);
  }

  display.printText(0, 0,
    "Press the button if satisfied, don't do anything is not",
    1, true, true, 1, 4);

  if(digitalRead(pin)){
    return true;
  } else{
    return false;
  }
}
