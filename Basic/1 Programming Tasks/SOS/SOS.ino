/* Die angeschlossene LED wird abwechselnd an- und ausgeschaltet.
Durch den Befehl delay() ergibt sich eine blinkende LED.*/

#define PIN_LED 2   // im Programm wird PIN_LED immer durch 2 ersetzt
                    // #define definiert einen Platzhalter, keine Variable

// setup() wird nur einmal durchlaufen und konfiguriert das Board
void setup() {
  pinMode(PIN_LED,OUTPUT); // Setzt den Pin (2) der roten LED als Ausgang
}

// loop() läuft als Endlosschleife. Hier kommt das Hauptprogramm rein. 
void loop() {
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(1000);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(1000);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(1000);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
  digitalWrite(PIN_LED,HIGH);  // Ausgang HIGH (5V), LED an
  delay(500);                 // Programmverzögerung um 1s = 1000ms
  digitalWrite(PIN_LED,LOW);   // Ausgang LOW (0V), LED aus
  delay(500);
}
