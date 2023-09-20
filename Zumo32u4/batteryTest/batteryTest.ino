#include <Zumo32U4.h>

Zumo32U4LCD lcd;

void setup() {
    batteryTest();
}

void loop() {
    lcd.print("A  B  C");
}