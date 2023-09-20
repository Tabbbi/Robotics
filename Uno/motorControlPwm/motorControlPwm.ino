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
const int in1 = 5;
const int in2 = 6;
//const int in3 = 9;
//const int in4 = 10;
const int interval = 25;
int currentSpeed = constrain(currentSpeed, -255, 255);

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
//  pinMode(in3, OUTPUT);
//  pinMode(in4, OUTPUT);
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
}

void loop() {
  int stateButton1 = digitalRead(pinButton1);
  int stateButton2 = digitalRead(pinButton2);
  
  
}
