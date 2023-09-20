#include <Zumo32U4.h>

Zumo32U4LineSensors sensors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

#define sensorCount 5
unsigned int sensorValues[sensorCount];
int line = 2000;
int avSpeed = 150;
int edge = 500;         //black = 950
float kp = 1.0;
float kd = 2.5;
int count = 1;
int event = 0;


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
    int position = sensors.readLine(sensorValues);
    if (!isEvent()) {
        followLine(position);
    } else {
        event++;
        if (event < 12) {
            reactToEvent(event);
        } else {
            motors.setSpeeds(0, 0); 
            lcd.clear();  
            lcd.print(" -ENDE- ");
        }
    }
}