#define red 1
#define yellow 2
#define green 3
#define blue 4
#define white 5
int dTime = 200;

void setup(){
  for (int i = 0; i <= 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
    delay(dTime);
  }
  for ( int i = 5; i <= 5; i--) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    delay(dTime);
  }
}

void loop(){
  
}
