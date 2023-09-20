#include <Zumo32U4.h>

Zumo32U4LineSensors sensors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

// Kp = 0.75, Kd = 1.5

#define sensorCount 5
unsigned int sensorValues[sensorCount];
unsigned int middleSensor;
int edgeValue = 500;
int avSpeed = 150;
int deltaSpeed;
int leftSpeed;
int rightSpeed;
float diff;
float kp = 0.8;
float kd = 0;
int newE;

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
    followEdge(sensorValues[2]);
}

void followEdge(int sensor) {
    if (buttonA.getSingleDebouncedPress()) {
        menu();
    }
    // lcd.clear();
    lcd.print("Kp->");
    lcd.print(kp);
    lcd.gotoXY(0, 1);
    lcd.print("Kd->");
    lcd.print(kd);    

    static int oldE;
    newE = edgeValue - sensor;
    diff = newE - oldE;
    deltaSpeed = (kp * newE) + (kd * diff);
    oldE = newE;
    leftSpeed = avSpeed - deltaSpeed;
    rightSpeed = avSpeed + deltaSpeed;
    motors.setSpeeds(leftSpeed, rightSpeed);
}