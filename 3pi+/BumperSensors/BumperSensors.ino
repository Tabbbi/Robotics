#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

BumpSensors bumpSensors;
ButtonA buttonA;
Buzzer buzzer;
Motors motors;
OLED display;

double speed = 75;
long time;

void setup() {
  bumpSensors.calibrate();
  display.setLayout21x8();
  display.clear();
  display.gotoXY(0, 1);
  display.print("Press A to start.");
  buttonA.waitForPress();

}

void loop() {
  bumpSensors.read();
  motors.setSpeeds(speed, speed);

  if (bumpSensors.leftChanged()) {
    if (bumpSensors.leftIsPressed()) {
      buzzer.play("c32");
      display.gotoXY(5, 4);
      display.print('L');
      motors.setSpeeds(-speed, -speed);
      delay(300);
      motors.setSpeeds(speed * 1.5, 0);
      delay(300);
    } else {
      buzzer.play("b32");
      display.gotoXY(5, 4);
      display.print(' ');
    }
  }

  if (bumpSensors.rightChanged()) {
    if (bumpSensors.rightIsPressed()) {
      buzzer.play("e32");
      display.gotoXY(15, 4);
      display.print('R');
      motors.setSpeeds(-speed, -speed);
      delay(300);
      motors.setSpeeds(0, speed * 1.5);
      delay(300);
    } else {
      buzzer.play("f32");
      display.gotoXY(15, 4);
      display.print(' ');
    }
  }
}
