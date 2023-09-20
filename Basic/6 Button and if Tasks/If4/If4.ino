#define ledone 2
#define ledtwo 3
#define tasterone 4
#define tastertwo 4

void setup() {
  pinMode (ledone, OUTPUT);
  pinMode (ledtwo, OUTPUT);
  pinMode (tasterone, INPUT_PULLUP);
  pinMode (tastertwo, INPUT_PULLUP);
}
void loop() {
  boolean tasterstateOne = digitalRead(tasterone);
  boolean tasterstateTwo = digitalRead(tastertwo);
  if (tasterstateOne) {
    digitalWrite(ledone, HIGH);
  } else if (tasterstateTwo) {
    digitalWrite(ledtwo, HIGH);
  } else if (tasterstateOne && tasterstateTwo) {
    digitalWrite(ledone, HIGH);
    digitalWrite(ledtwo, HIGH);
  }
}
