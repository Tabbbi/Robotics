void batteryTest() {
    int spannung = readBatteryMillivolts();
    while (!buttonA.isPressed()) {
        if (!batteryCurrent()) {
            lcd.print(spannung);
            lcd.print("mV");
            lcd.gotoXY(0, 1);
            lcd.print("Bat. LOW");
            lcd.gotoXY(0, 0);
            delay(100);
        } else if (batteryCurrent()) {
            lcd.print(spannung);
            lcd.print("mV");
            lcd.gotoXY(0, 1);
            lcd.print("Bat. OK");
            lcd.gotoXY(0, 0);
        }
        delay(100);
    }
    lcd.clear();
}

bool batteryCurrent() {
    int spannung = readBatteryMillivolts();
    while (spannung < 4200) {
        return false;
    }
        return true;
}