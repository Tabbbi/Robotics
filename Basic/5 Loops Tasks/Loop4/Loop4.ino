void setup() {
  Serial.begin(115200);
  Serial.println("Warten (1 sec) ....");
  delay(1000);
  int i,j;
  for (i = 0; i < 10; i++) {
    Serial.println();
    Serial.print("Zeile: "); Serial.print(i);
    for(j = 10; j > i; j--) {
      Serial.print("*");
      delay(100);
    }
  }
}

void loop() {
  // bleibt leer
}
