#pragma once

class ErrorCodes{
private:
public:
  ErrorCodes();
  enum Codes {
    DISP_NOT_FOUND, /**< Error code 1: displayed if the display has not been found */
    SOFT_POT_NOT_FOUND /**< Error code 2: displayed if the pot has not been found */
  };
  void writeErrorCode(Codes code);
};
