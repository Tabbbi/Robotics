void testBattery() {
  int uMin = 4200;
  int uBat;
  while (!buttonA.isPressed()) {
    uBat = readBatteryMillivolts();
    lcd.gotoXY(0, 0); lcd.print(uBat); lcd.print(" mV");

    lcd.gotoXY(0, 1);
    if (uBat < uMin) {
      lcd.print("Too low!");
    }
    else {
      lcd.print("Ok -> A");
    }
    delay(100);
  }

  if (uBat < uMin) {
    lcd.clear();
    lcd.print("Change");
    lcd.gotoXY(0, 1);
    lcd.print("Battery");
    while (1);
  }
  else{
    lcd.clear();
  }
  delay(500);
}
