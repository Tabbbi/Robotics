#define TASTER 3
#define LED 13

int statusTasterLetzter;

void setup(){
    pinMode(TASTER, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
} 

void loop(){
  if (statusTasterLetzter == HIGH && digitalRead(TASTER) == LOW) {
    digitalWrite(LED, LOW);
    statusTasterLetzter = LOW;
    delay(500);
  }
  if (statusTasterLetzter == LOW && digitalRead(TASTER) == LOW) {
    digitalWrite(LED, HIGH);
    statusTasterLetzter = HIGH;
    delay(500);
  }
}