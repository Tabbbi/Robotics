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

void setup() {
  debouncer.attach(Button, INPUT_PULLUP);
  debouncer.interval(25);

  pinMode(LedRed, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);

  startAnimation();
}

void loop() {
  debouncer.update();
  if (debouncer.fell() && (counter == 0)) {
    delay(500);
    setSpeed(200, 200);
    counter++;
  } else if (debouncer.fell() && (counter == 1)) {
    setSpeed(0, 0);
    counter--;
  }
}

void setSpeed(int speedLeft, int speedRight){
  speedLeft = speedLeft * 1.2225;
  analogWrite(in1, 0);
  analogWrite(in2, speedLeft);
  analogWrite(in3, speedRight);
  analogWrite(in4, 0);
}

void startAnimation() {
  digitalWrite(LedRed, HIGH);
  digitalWrite(LedYellow, HIGH);
  digitalWrite(LedGreen, HIGH);
  delay(1500);
  digitalWrite(LedRed, LOW);
  digitalWrite(LedYellow, LOW);
  digitalWrite(LedGreen, LOW);
}