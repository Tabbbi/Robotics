#include <Zumo32U4.h>

Zumo32U4LineSensors sensors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

#define sensorCount 5
unsigned int sensorValues[sensorCount];
unsigned int middleSensor;
int edgeValue = 500;
int avSpeed = 350;
int leftSpeed;
int rightSpeed;
float kp = 1;
int e;
int deltaSpeed;

void setup() {
  testBattery();
  sensors.initFiveSensors();
  lcd.print("Calib...");
  autoCalibration();
  lcd.gotoXY(0, 1);
  lcd.print("Go -> A");
  buttonA.waitForPress();
  lcd.clear();
}

void loop() {
  sensors.readCalibrated(sensorValues);
  followEdge();
}

void followEdge() {
  lcd.print("Kp is: ");
  lcd.gotoXY(0, 1);
  lcd.print(kp);
  lcd.gotoXY(0, 0);
  if (buttonB.getSingleDebouncedPress()) {
    kp = kp + 0.05;
  }
  if (buttonC.getSingleDebouncedPress()) {
    kp = kp - 0.05;
  }
  middleSensor = sensorValues[2];
  e = edgeValue - middleSensor;
  deltaSpeed = kp * e;
  leftSpeed = avSpeed - deltaSpeed;
  rightSpeed = avSpeed + deltaSpeed;
  motors.setSpeeds(leftSpeed, rightSpeed);
}

void autoCalibration() {
  for (int i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-200, 200);
    } else {
      motors.setSpeeds(200, -200);
    }
    sensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}
