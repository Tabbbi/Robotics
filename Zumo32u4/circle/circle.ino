#include <Zumo32U4.h>

Zumo32U4Motors bothMotors;
Zumo32U4ButtonA buttonA;

void setup() {

}

void loop() {
buttonA.waitForButton();
bothMotors.setSpeeds(300, 175);
delay(5500);
bothMotors.setSpeeds(0, 0);
}
