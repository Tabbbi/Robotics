void setup() {
  Serial.begin(115200);
  Serial.println("Warten (1 sec) ....");
  delay(1000);
  int i,j; // Deklaration der Zählvariablen kann auch außerhalb der Schleife stattfinden
  for (i = 0 ; i<10; i++) // Zeilen (äußere Schleife)
  {
    Serial.println();
    Serial.print("Zeile: "); Serial.print(i);
    for(j=-1; j<i; j++)  // Spalten (innere Schleife)
    {
      Serial.print("*");
      delay(100);
    }
  }
}

void loop() {
  // bleibt leer
}
