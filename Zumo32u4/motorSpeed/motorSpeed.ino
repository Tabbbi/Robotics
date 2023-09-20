#include <Zumo32U4.h>

Zumo32U4Encoders encoders;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

void setup() {
    Serial.begin(115200);
    testBattery();
}

void loop() {
    unsigned long dZeit = 5000;       // Zeitintervall für die Geschwindigkeitsmessung (5000 Mikrosekunden)
    unsigned long fahrzeit = 500000;  // 500000
    unsigned long jetzt = micros();
    unsigned long startzeit;      // Startzeitpunkt der Messreihe
    unsigned long letzteMessung = jetzt;  // Zeitpunkt der letzten durchgeführten Messung
    int speed = 200;

    jetzt = micros();  // vergangene Zeit in Microsekunden
    startzeit = jetzt;
    while (jetzt - startzeit < fahrzeit) {   // Roboter soll `fahrzeit` fahren
        motors.setSpeeds(speed, speed);
        jetzt = micros();                      // vergangene Zeit in Microsekunden
        if (jetzt - letzteMessung >= dZeit) {  // Zeitintervall zur Geschwindigkeitsmessung
            letzteMessung = jetzt;
            int impulseRechts = encoders.getCountsAndResetRight();  // Impulse auslesen und zurücksetzen
            int impulseLinks = encoders.getCountsAndResetLeft();
            long vRoboter = (((impulseLinks + impulseRechts) / 2) * 1e6 /dZeit);
            Serial.print((jetzt - startzeit) / 1000),
            Serial.print("\t"),
            Serial.println(vRoboter);
        }
    }
    motors.setSpeeds(0, 0);
    buttonA.waitForButton();
}
