#include <Zumo32U4.h>

/*
* measured 1476
* calculated 1538
*/

Zumo32U4Encoders encoders;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
unsigned long lastDisplayTime = 0;

void setup() {
    testBattery();
}

void loop() {
    driveInMM(500);
    int difference = encoders.getCountsLeft() - encoders.getCountsRight();
    // lcd.clear();
    // lcd.print(difference);
    // lcd.gotoXY(0, 1);
    // lcd.print(encoders.getCountsLeft());
    buttonA.waitForButton();
}