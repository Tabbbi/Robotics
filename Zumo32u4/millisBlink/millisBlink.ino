#include <Zumo32U4.h>

Zumo32U4ButtonA buttonA;
long lastTime = 0;
bool stateLed = 0;
int count = 0;

void setup() {
  buttonA.waitForButton();
}

void loop() {
  if(((millis() - lastTime) > 500 ) && count < 6){
    stateLed = !stateLed;
    lastTime = millis();
    ledRed(stateLed);
    count++;
  } else if (count == 6) {
    count = 0;
    buttonA.waitForButton();
  }
}
