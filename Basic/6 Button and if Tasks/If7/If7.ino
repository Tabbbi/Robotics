#define TASTER 3
#define LED 13

int statusLED = LOW;
int statusTaster = HIGH;
int statusTasterLetzter = HIGH;
int counter;

void setup(){
    Serial.begin(115200);
    pinMode(TASTER, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
} 

void loop() {
    if (statusTasterLetzter == HIGH && digitalRead(TASTER) == LOW) {
    digitalWrite(LED, LOW);
    statusTasterLetzter = LOW;
    delay(500);
    Serial.println(counter++);
    counter = counter++;
  } else if (statusTasterLetzter == LOW && digitalRead(TASTER) == LOW) {
    digitalWrite(LED, HIGH);
    statusTasterLetzter = HIGH;
    delay(500);
    Serial.println(counter++);
    counter = counter++;
  }
}