#define PIN_TASTER 5

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TASTER, INPUT_PULLUP);
}
void loop() {

}
