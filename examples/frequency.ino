#include <MSGEQ7.h>
MSGEQ7 eq7(8,9,10);

void setup() {
  Serial.begin(115200);
  eq7.begin();
}

void loop() {
  eq7.strobeRead();
  delay(1000);
}
