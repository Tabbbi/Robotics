#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

Encoders encoders;
ButtonA buttonA;
Motors motors;
OLED display;

#define RADtoDEG 57.2957795131  // = 180/pi
#define DEGtoRAD 0.01745329252  // = pi/180
#define MMperTICK 0.2           // Auflösung der Radencoder
#define CPR 358.3               // Counts per revolution

void setup() {
  testBattery();
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}

void loop() {
  turn(90);
  display.clear();
  display.gotoXY(0, 1);
  display.print("Done");
  buttonA.waitForButton();

}