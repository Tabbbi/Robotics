void setup() {
  // put your setup code here, to run once:
  Serial.begin(6900);
}
int x = 0;

void loop() {
  // put your main code here, to run repeatedly:
  x = x + 8;
  Serial.println(x);
}
