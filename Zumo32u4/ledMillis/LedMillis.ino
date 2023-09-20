#include <Zumo32U4.h>

unsigned long currentTime = 0;
unsigned long lastChange = 0;
unsigned long blinkTime = 1000;
bool stateLed = LOW;

void setup() {

}

void loop() {
  currentTime = millis();
  if ((currentTime - lastChange) >= blinkTime) {
    if (stateLed == LOW) {
    stateLed = HIGH;
    } else {
    stateLed = LOW;
    }
    ledRed(stateLed);
    lastChange = currentTime;
  }
}
