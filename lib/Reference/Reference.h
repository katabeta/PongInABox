#pragma once
#include <Arduino.h>



class Reference{
public:
  Reference(void);
  const uint8_t dPin74R = 2; /**< pin number for the right button associated with the display with the 74 address */
  const uint8_t dPin75R = 4; /**< pin number for the right button associated with the display with the 75 address */
  const uint8_t dPin0 = 5; /**< pin number for the confirmation button */
  const uint8_t dPin74L = 5; /**< pin number for the left button associated with the display with the 74 address */
  const uint8_t dPin75L = 6; /**< pin number for the left button associated with the display with the 75 address */

  const uint8_t aPin74 = 0; /**< pin number for the pot associated with the display with the 74 address */
  const uint8_t aPin75 = 1; /**< pin number for the pot associated with the display with the 75 address */

  const uint8_t address74 = 0x74; /**< the address of the 74 display */
  const uint8_t address75 = 0x75; /**< the address of the 75 display */

  const uint16_t potMin = 370; /**< established raw minimum output from the pots with a degree of margin, may be different for different projects */
  const uint16_t potMax = 705; /**< established raw minimum output from the pots with a degree of margin, may be different for different projects */

  const uint8_t minBright = 1;
  const uint16_t qBright = 50;
  const uint16_t hBright = qBright * 2;
  const uint16_t qhBright = qBright * 3;
  const uint16_t maxBright = qBright * 4;
};
