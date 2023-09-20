#include <Bounce2.h>

#define taster1 2
#define taster2 4

const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;

#define greenLed 7 // Green LED
#define redLed 8 // Red LED 
#define yellowLed 12 // Yellow LED

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();

void setup(){
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(taster1, INPUT_PULLUP);
    pinMode(taster2, INPUT_PULLUP);

    debouncer1.attach(taster1, INPUT_PULLUP);
    debouncer1.interval(25);

    debouncer2.attach(taster2, INPUT_PULLUP);
    debouncer2.interval(25);
}

void loop(){
    debouncer1.update();
    debouncer2.update();

    if (debouncer1.fell()) {
        digitalWrite(yellowLed, HIGH);
        delay(500);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, HIGH);
        setSpeed(255, 255);
    } 
    if (debouncer2.fell()){
        setSpeed(0, 0);
        digitalWrite(greenLed, LOW);
    }
}

void setSpeed(int speedLeft, int speedRight){
    speedLeft = speedLeft * 1.2225;
    analogWrite(in1, 0);
    analogWrite(in2, speedLeft);
    analogWrite(in3, speedRight);
    analogWrite(in4, 0);
}

int pToPwm(int percentage){
    int pwm = 255 * percentage / 100;
    return pwm;
}