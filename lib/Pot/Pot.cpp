#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <string.h>
#include <Pot.h>


Pot::Pot(int pin){
  this->pin = pin;
  printer = Printer();

  isFirstCalDone = false;
  isSecondCalDone = false;
  isTwoCalDone = false;
}

void Pot::calibrate(Adafruit_IS31FL3731 displays[], uint8_t totalNumOfPots, int calButtonPin){
  printer.printText(5, 0, "Calibration ", 1, 1, displays, 1000, 5);

  for(int i = 0; i < totalNumOfPots; i++){
      //Calibrate one of the pots
      //Touch top of the pot and record the value. Make sure to sample for a little bit to get an accurate value.
      //Draw instructions for the user
      printer.printText(5, 0, "Press and hold the top of one pot", 1, 1, displays, 1000, 1);
      this->max = sampleValue(displays);
      printer.printText(5, 0, "Press and hold the bottom of one pot", 1, 1, displays, 1000, 1);
      this->min = sampleValue(displays);
      //Touch bottom of the pot and record the value. Make sure to sample for a little bit to get an accurate value.
      //Draw instructions for the user
      /**/
      //Calibrate another one of the pots
      //Calibrate the pots when used together
  }
}

double Pot::sampleValue(Adafruit_IS31FL3731 displays[]){
  delay(2000); //2 secs
  printer.printText(5, 0, "Sample start", 1, 1, displays, 0, 1);
  double sum = 0;
  for(int i = 0; i < 50; i++){
    sum += analogRead(pin);
  }
  printer.printText(5, 0, "OK!", 1, 1, displays, 0, 1);
  return sum/50;
}

double Pot::getNormalizedRead(){
  return (analogRead(pin)-min)/(max-min);
}

int Pot::getLEDNumRead(){
  return 15*getNormalizedRead();
}
