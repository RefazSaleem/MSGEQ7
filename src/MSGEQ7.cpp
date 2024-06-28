#include "MSGEQ7.h"

MSGEQ7::MSGEQ7(int resetPin, int strobePin, int analogPin)
: _resetPin(resetPin), _strobePin(strobePin), _analogPin(analogPin) {}

void MSGEQ7::begin() {
  pinMode(_resetPin, OUTPUT);
  pinMode(_strobePin, OUTPUT);
  pinMode(_analogPin, INPUT);
}

void MSGEQ7::strobeRead() {
  int frequencyValues[7];

  // Pull reset pin low for 100ns
  digitalWrite(_resetPin, LOW);
  delayMicroseconds(1);

  for (int i = 0; i < 7; i++) {
    // Pull strobe pin low for 18us (with 36us settle time)
    digitalWrite(_strobePin, LOW);
    delayMicroseconds(18);
    delayMicroseconds(36); // Wait for settle time

    // Pull strobe pin high for 18us
    digitalWrite(_strobePin, HIGH);
    delayMicroseconds(18);

    // Read analog pin and store the value in the provided array
    frequencyValues[i] = analogRead(_analogPin);
  }

  // Print the frequency values
  for (int i = 0; i < 7; i++) {
    Serial.print("Frequency ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(frequencyValues[i]);
  }
}
