// Einfaches Beispiel zum Ansteuern des DRV8833
//      _________________________
//      in1   in2   Motorfunktion
//      -------------------------
//      1     0     Vorwärts
//      0     1     Rückwärts 
//      1     1     Bremse
//      0     0     Freilauf
//      _________________________   

#define pinButton1 2
#define pinButton2 4
#define pinLed1 7   //green
#define pinLed2 8   //red
#define pinLed3 12  //yellow
const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
}

void loop() {
  int stateButton1 = digitalRead(pinButton1);
  int stateButton2 = digitalRead(pinButton2);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);

  if (!stateButton1 && !stateButton2) {
    stopMotorBrake();
  } else if (stateButton1 && !stateButton2) {
    turnMotorBackward();
  } else if (!stateButton1 && stateButton2) {
    turnMotorForward();
  } else {
    stopFreeWheeling();
  }
}

