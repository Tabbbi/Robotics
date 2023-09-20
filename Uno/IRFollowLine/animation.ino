void doLightAnimation() {
  for (int i = 0; i < NUMLED; i++) {
    for (int i = 0 ; i < NUMLED; i++) {
      digitalWrite(pinLeds[i], HIGH);
      delay(100);
    }
    for (int i = 0 ; i < NUMLED; i++) {
      digitalWrite(pinLeds[i], LOW);
      delay(100);
    }
  }
}
