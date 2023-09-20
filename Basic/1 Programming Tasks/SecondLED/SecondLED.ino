#define LED2 3
#define PIN_LED 2   // im Programm wird PIN_LED immer durch 2 ersetzt
                    // #define definiert einen Platzhalter, keine Variable

// setup() wird nur einmal durchlaufen und konfiguriert das Board
void setup() {
  pinMode(PIN_LED,OUTPUT);
  pinMode(LED2,OUTPUT);  // Setzt den Pin (2) der roten LED als Ausgang
}

// loop() läuft als Endlosschleife. Hier kommt das Hauptprogramm rein. 
void loop() {
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(200);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(1800);
  digitalWrite(LED2,HIGH);  // Ausgang HIGH (5V), LED an
  delay(200);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(LED2,LOW);   // Ausgang LOW (0V), LED aus
  delay(1800);
}
