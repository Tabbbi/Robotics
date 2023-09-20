#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

Encoders encoders;
ButtonA buttonA;
Motors motors;
OLED display;

#define RADtoDEG 180 / PI       // = 180/pi
#define DEGtoRAD PI / 180       // = pi/180
// #define MMperTICK 0.2           // Auflösung der Radencoder
#define CPR 358.3               // Counts per revolution

float kp = 1;
float kd = 1;

float wheelCircumference = 16.11 * 2 * PI;
float ticksPerMM = CPR / wheelCircumference;

void setup() {
  testBattery();
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}

void loop() {
  driveHouse(50);
  buttonA.waitForButton();
  delay(500);
}