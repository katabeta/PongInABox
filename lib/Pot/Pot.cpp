#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>
#include <Pot.h>

//#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


Pot::Pot(int pin, Adafruit_IS31FL3731* display){
  this->display = display;
  this->pin = pin;
}

/*public*/
// void Pot::calibrate(uint8_t totalNumOfPots){
//   for(int i = 0; i < totalNumOfPots; i++){
//       do{
//         display->printText(0, 0, "Press and hold the top of your control surface", 1, true, true, 1, 5);
//         this->max = sampleValue();
//         display->printText(0, 0, "Press and hold the bottom of your control surface", 1, true, true, 1, 5);
//         this->min = sampleValue();
//       } while(calTest());
//   }
// }

int Pot::getLEDNumRead(){
  int ledNum = 15 * getNormalizedRead();
  return ledNum > 15 ? -1 : ledNum;
}
int Pot::getLEDNumRead(double min, double max){
  int ledNum = 15 * getNormalizedRead(min, max);
  return ledNum > 15 ? -1 : ledNum;
}



/*private*/
// bool Pot::syncCal(Pot *pots){
//
// }

// double Pot::sampleValue(){
//   delay(2000); //2 secs
//   display->printText(5, 0, "3", 1, true, false, 0, 5);
//   delay(500);
//   display->printText(5, 0, "2", 1, true, false, 0, 5);
//   delay(500);
//   display->printText(5, 0, "1", 1, true, false, 0, 5);
//   delay(500);
//   display->printText(5, 0, "0", 1, true, false, 0, 5);
//   delay(500);
//   display->printText(0, 0, "Queing", 1, true, false, 0, 5);
//   double sum = 0;
//   for(int i = 0; i < 50; i++){
//     sum += analogRead(pin);
//   }
//   display->printText(5, 0, "OK!", 1, true, false, 0, 5);
//   return sum/50;
// }

double Pot::getNormalizedRead(){
  return (analogRead(pin)-hardware.potMin)/(hardware.potMax-hardware.potMin);
}
double Pot::getNormalizedRead(double min, double max){
  double asd=(analogRead(pin)-min)/(max-min);
  return asd;
}

// bool Pot::calTest(){
//   bool doneTesting = false;
//   display->printText(0, 0,
//     "Run your finger all along the pot and check the LEDs the light up match your movement",
//     1, true, true, 1, 1);
//
//     //TODO may want to display this message at the same time as testing
//   display->printText(0, 5,
//     "Press the button when you are done",
//     1, true, true, 1, 5);
//   while(!doneTesting){
//     display->setLEDPWM(getLEDNumRead(), 1);
//     doneTesting = digitalRead(pin);
//   }
//
//   display->printText(0, 0,
//     "Press the button if disatisfied, else nothing",
//     1, true, true, 1, 5);
//
//   return digitalRead(pin) ? true : false;
// }
