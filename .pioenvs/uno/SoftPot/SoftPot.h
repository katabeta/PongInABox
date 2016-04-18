#ifndef _SOFTPOT_H_
#define _SOFTPOT_H_
#endif

#include <Arduino.h>

#define MIN 0
#define MAX 100
#define WORK_MIN 20
#define WORK_MAX 80

class SoftPot{

  public:
    SoftPot(int analogport);
    double getPercentPressed(void);
    double getUsablePercentage(void);
  private:
    uint8_t pin;

};
