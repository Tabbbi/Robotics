/*
  If button A is pressed LED 1 is on.
  If button B is pressed LED 2 is on.
  If buttons A and B are pressed LEDs 1 and 2 are on.
  If no button is pressed both LEDs are off
*/

#define pinLed1 2
#define pinLed2 3
#define pinButtonA 4
#define pinButtonB 5

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinButtonA, INPUT_PULLUP);
  pinMode(pinButtonB, INPUT_PULLUP);
}

void loop() {
  int stateButtonA = digitalRead(pinButtonA);
  int stateButtonB = digitalRead(pinButtonB);

  if (stateTasterA == LOW) && (stateTasterB == HIGH)) {
    digitalWrite(pinLed1, HIGH);
  } else if ((stateTasterA == HIGH) && (stateTasterB == LOW)) {
    digitalWrite(pinLed2, HIGH);
  } else if ((stateTasterA && stateTasterB) == LOW) {
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
  } else {
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
  }
}