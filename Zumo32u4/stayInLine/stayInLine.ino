// white ~ 200
// black ~ 1000

#include <Zumo32U4.h>

Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4LineSensors sensors;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

#define sensorCount 5
unsigned int sensorValues[sensorCount];
int minValue = 1000;
int maxValue = 0;
int edgeValue;
bool calibrated = false;
bool clean = false;

void setup() {
    Serial.begin(5900);
    sensors.initFiveSensors();
    batteryTest();
    buttonA.waitForPress();
    autoCalibration();
}

void loop() {
    sensors.readCalibrated(sensorValues);
    // unsigned int leftSensor = sensorValues[0];
    unsigned int middleSensor = sensorValues[2];
    // unsigned int rightSensor = sensorValues[4];
    // if (!calibrated && buttonA.isPressed()) {
    //     lcd.clear();
    //     lcd.println("Calib...");
    //     autoCalibration();
    //     calibrated = true;
    // }
    // if (calibrated && buttonA.isPressed()) {
    //     clean = true;
    //     lcd.clear();
    //     lcd.println("Cleaning");
    // }
    // while (clean) {
        // Serial.println(middleSensor);
        if (middleSensor > edgeValue) {
            motors.setSpeeds(-200, -150);
            delay(200);
        } else {
            motors.setSpeeds(200, 200);
        }
    // }
}

void autoCalibration() {
    for (int i = 0; i < 120; i++)
    {
        if (i > 30 && i <= 90)
        {
            motors.setSpeeds(-200, 200);
        }
        else
        {
            motors.setSpeeds(200, -200);
        }
        sensors.calibrate();
    }
    motors.setSpeeds(0, 0);
}