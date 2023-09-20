#include <Bounce2.h>

#define Button 2
#define LedRed 8
#define LedYellow 12
#define LedGreen 7

const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;
int counter = 0;
int pwm = 150;

Bounce debouncer = Bounce();

void setup()
{
    debouncer.attach(Button, INPUT_PULLUP);
    debouncer.interval(25);

    pinMode(LedRed, OUTPUT);
    pinMode(LedYellow, OUTPUT);
    pinMode(LedGreen, OUTPUT);

    startAnimation();
}

void loop()
{
    debouncer.update();
    if (debouncer.fell() && (counter == 0))
    {
        delay(500);
        analogWrite(in1, pwm);
        digitalWrite(in2, LOW);
        analogWrite(in3, pwm);
        digitalWrite(in4, LOW);
        counter++;
    }
    else if (debouncer.fell() && (counter == 1))
    {
        digitalWrite(in1, 0);
        digitalWrite(in2, 0);
        digitalWrite(in3, 0);
        digitalWrite(in4, 0);
        counter--;
    }
}

void startAnimation()
{
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedYellow, HIGH);
    digitalWrite(LedGreen, HIGH);
    delay(1500);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedYellow, LOW);
    digitalWrite(LedGreen, LOW);
}