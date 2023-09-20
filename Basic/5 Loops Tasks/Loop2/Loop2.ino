#define LED1 2 

void setup() {
  pinMode(LED1, OUTPUT);
}

void loop() {
  int ms = 1000;
  int ms2 = 100;
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED1,HIGH);
    delay(ms);
    digitalWrite(LED1,LOW);
    delay(ms);
    ms = ms - 100;
  }
  for (int j = 0; j < 10; j++) {
    digitalWrite(LED1,HIGH);
    delay(ms2);
    digitalWrite(LED1,LOW);
    delay(ms2);
    ms2 = ms2 + 100;
  }
}
