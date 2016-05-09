#pragma once
#include <Arduino.h>



class Hardware{
public:
  Hardware(void);
  uint8_t dPin74 = 2;
  uint8_t dPin75 = 3;
  uint8_t dPin0 = 4;

  uint8_t aPin74 = 0;
  uint8_t aPin75 = 1;

  uint8_t address74 = 0x74;
  uint8_t address75 = 0x75;

  uint16_t potMin = 375;
  uint16_t potMax = 710;
};
