#pragma once
#include <Arduino.h>



class Reference{
public:
  Reference(void); 
  const uint8_t dPin74 = 2; /**< pin number for the button associated with the display with the 74 address */
  const uint8_t dPin75 = 3; /**< pin number for the button associated with the display with the 75 address */
  const uint8_t dPin0 = 4; /**< pin number for the confirmation button */

  const uint8_t aPin74 = 0; /**< pin number for the pot associated with the display with the 74 address */
  const uint8_t aPin75 = 1; /**< pin number for the pot associated with the display with the 75 address */

  const uint8_t address74 = 0x74; /**< the address of the 74 display */
  const uint8_t address75 = 0x75; /**< the address of the 75 display */

  const uint16_t potMin = 375; /**< established raw minimum output from the pots with a degree of margin, may be different for different projects */
  const uint16_t potMax = 710; /**< established raw minimum output from the pots with a degree of margin, may be different for different projects */
};
