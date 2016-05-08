#pragma once

class ErrorCodes{
private:
public:
  ErrorCodes();
  enum Codes {DISP_NOT_FOUND, SOFT_POT_NOT_FOUND};
  void writeErrorCode(Codes code);
};
