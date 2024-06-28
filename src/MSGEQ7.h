#pragma once
#include <Arduino.h>

class MSGEQ7 {
public:
  MSGEQ7(int resetPin, int strobePin, int analogPin);
  void begin();
  void strobeRead();

private:
  int _resetPin;
  int _strobePin;
  int _analogPin;
};
