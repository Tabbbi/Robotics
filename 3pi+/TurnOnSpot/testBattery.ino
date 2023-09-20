void testBattery() {
  int uMin = 4300;
  int uBat;
  while (!buttonA.isPressed()) {
    uBat = readBatteryMillivolts();
    display.setLayout11x4();
    display.gotoXY(0, 0); 
    display.print(uBat); 
    display.print(" mV");
    display.gotoXY(0, 1);
    if (uBat < uMin) {
      display.print("Too low!");
    }
    else {
      display.print("Ok -> A");
    }
    delay(300);
  }

  if (uBat < uMin) {
    display.clear();
    display.print("Change");
    display.gotoXY(0, 1);
    display.print("Battery");
    while (1);
  }
  else{
    display.clear();
  }
  delay(500);
}
