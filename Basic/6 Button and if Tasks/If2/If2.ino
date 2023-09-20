
# define PIN_LED 8
# define PIN_TASTER 3

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TASTER, INPUT_PULLUP);
}

void loop() {
  int zustandTaster = digitalRead(PIN_TASTER);

  if (zustandTaster == LOW) {
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
  }
  else {
    digitalWrite(PIN_LED, LOW);
  }
}
