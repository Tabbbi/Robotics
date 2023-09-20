void turnMotorForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(pinLed1, HIGH);
}

void turnMotorBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(pinLed2, HIGH);
}

void stopFreeWheeling() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(pinLed3, HIGH);
}

void stopMotorBrake() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, HIGH);
}