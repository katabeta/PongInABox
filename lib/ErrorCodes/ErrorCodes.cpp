#include <ErrorCodes.h>
#include <Arduino.h>

ErrorCodes::ErrorCodes(){}


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
