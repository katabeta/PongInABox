#include <Arduino.h>
#include <SoftPot.h>

/* Constructor */
SoftPot::SoftPot(int analogpin){
  pin = analogpin;
}

double SoftPot::getPercentPressed(){
  double percent = analogRead(pin)/1023 * 100;
  return percent;
}

double SoftPot::getUsablePercentage(){
  double actualPercent = getPercentPressed();
  double percent = 0;
  if(actualPercent >= WORK_MIN && actualPercent <= WORK_MAX){
    percent = percent * ((WORK_MAX - WORK_MIN) / 100); //TODO don't know if this math actually works
  }
  return percent;
}
