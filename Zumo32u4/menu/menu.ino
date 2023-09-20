#include <Zumo32U4.h>    // 

Zumo32U4LCD lcd;          // Display (8x2)
Zumo32U4ButtonA buttonA;  // Taster A
Zumo32U4ButtonB buttonB;  // Taster B
Zumo32U4ButtonC buttonC;  // Taster C
Zumo32U4Motors motors;    // Motoren

void setup() {
  batteryTest();
  lcd.clear();             
  lcd.print("A  B  C");
}

void loop() {
  if ( buttonA.isPressed() ) {   
    ledYellow(1);    
    lcd.clear();    
    lcd.print("straight");
    delay(500);
    motors.setSpeeds(200, 200);
    delay(2000);
    motors.setSpeeds(0, 0);
    ledYellow(0);
    lcd.clear();
    lcd.print("A  B  C");
  }
  else if (buttonB.isPressed()) {
    ledGreen(1);
    lcd.clear();
    lcd.print("speed");
    delay(500);
    motors.setSpeeds(90, 90);
    delay(200);
    motors.setSpeeds(120, 120);
    delay(200);
    motors.setSpeeds(200, 200);
    delay(200);
    motors.setSpeeds(280, 280);
    delay(200);
    motors.setSpeeds(360, 360);
    delay(200);
    motors.setSpeeds(280, 280);
    delay(200);
    motors.setSpeeds(200, 200);
    delay(200);
    motors.setSpeeds(120, 120);
    delay(200);
    motors.setSpeeds(90, 90);
    delay(200);
    motors.setSpeeds(0, 0);
    lcd.clear();
    lcd.print("A  B  C");
  }
  else if (buttonC.isPressed()) {
    ledRed(1);
    lcd.clear();
    lcd.print("square");
    delay(500);
    motors.setSpeeds(200, 200);
    delay(2000);
    motors.setSpeeds(0, 0);
    motors.setSpeeds(0, 200);
    delay(1000);
    motors.setSpeeds(200, 200);
    delay(2000);
    motors.setSpeeds(0, 0);
    motors.setSpeeds(0, 200);
    delay(1000);
    motors.setSpeeds(200, 200);
    delay(2000);
    motors.setSpeeds(0, 0);
    motors.setSpeeds(0, 200);
    delay(1000);
    motors.setSpeeds(200, 200);
    delay(2000);
    motors.setSpeeds(0, 0);
    motors.setSpeeds(0, 200);
    delay(1000);
    ledRed(0);
    lcd.clear();
    lcd.print("A  B  C");
    // - turn on red LED , display shows "rectangle" 
    // - wait 0.5 seconds
    // - drive the robot a rectangle of 20cm x 20cm
    // - start and end point should be indentical 
    // - turn off red LED, show menu "A  B  C"
  }
}
