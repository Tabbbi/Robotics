#include <Pololu3piPlus32U4.h>
using namespace Pololu3piPlus32U4;

LineSensors sensors;
ButtonA buttonA;
ButtonB buttonB;
ButtonC buttonC;
Motors motors;
OLED lcd;

// Kp = 0.75, Kd = 1.5

#define sensorCount 5
unsigned int sensorValues[sensorCount];
unsigned int middleSensor;
int edgeValue = 500;
int avSpeed = 400;
int deltaSpeed;
int leftSpeed;
int rightSpeed;
float diff;
float kp = 1.4;
float kd = 0.7;
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
        kpMenu();
    }    
    if (buttonB.getSingleDebouncedPress()) {
        kdMenu();
    } 
    if (buttonC.getSingleDebouncedPress()) {
        speedMenu();
    }
    lcd.clear();
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