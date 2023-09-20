#include <Zumo32U4.h>

Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;

void setup() {

}

void loop() {
  if (buttonA.isPressed()) {
    ledRed(1);
  } else {
    ledRed(0);
  }
  if (buttonB.isPressed()) {
    ledGreen(1);
  } else {
    ledGreen(0);
  }
  if (buttonC.isPressed()) {
    ledYellow(1);
  } else {
    ledYellow(0);
  }
}
