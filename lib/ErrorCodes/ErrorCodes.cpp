#include <ErrorCodes.h>
#include <Arduino.h>

/**
@class ErrorCodes
    an enum with error code numbers to make printing easier.
*/
ErrorCodes::ErrorCodes(){}

/**
prints the error that corresponds to the passed code

@param code
    the ErrorCode enum that corresponds to your error

@todo add more codes (buttons, players, etc)
*/
void ErrorCodes::writeErrorCode(Codes code){
  switch (code) {
    case DISP_NOT_FOUND:
      Serial.println("ERROR: Display not found!");
      break;
    case SOFT_POT_NOT_FOUND:
      Serial.println("ERROR: Soft potentiometer not found!");
      break;
    default:
      Serial.println("ERROR UNDEF: Unknown error!");
  }
}
