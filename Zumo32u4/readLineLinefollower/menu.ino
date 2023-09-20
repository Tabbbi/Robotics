void menu() {
    int state = 1;
    motors.setSpeeds(0, 0);
    lcd.clear();
    switch (state) {
        case 1:
            lcd.println("<-B  C->");
            lcd.gotoXY(0, 1);
            lcd.println("   kp");
            if (buttonA.getSingleDebouncedPress()) {
                lcd.clear();
                lcd.println(kp);
                if (buttonB.getSingleDebouncedPress()) {
                    kp = kp - 0.1;
                } else if (buttonC.getSingleDebouncedPress()) {
                    kp = kp + 0.1;
                }
            }
        break;

        case 2:
            lcd.println("<-B  C->");
            lcd.gotoXY(0, 1);
            lcd.println("   kd");
            if (buttonA.getSingleDebouncedPress()) {
                lcd.clear();
                lcd.println(avSpeed);
                if (buttonB.getSingleDebouncedPress()) {
                    kd = kd - 0.1;
                } else if (buttonC.getSingleDebouncedPress()) {
                    kd = kd + 0.1;
                }
            }
        break;

        case 3:
            lcd.println("<-B  C->");
            lcd.gotoXY(0, 1);
            lcd.println(" speedy");
            if (buttonA.getSingleDebouncedPress()) {
                lcd.clear();
                lcd.println(avSpeed);
                if (buttonB.getSingleDebouncedPress()) {
                    avSpeed = avSpeed - 0.1;
                } else if (buttonC.getSingleDebouncedPress()) {
                    avSpeed = avSpeed + 0.1;
                }
            }
        break;

        case 4:
        break;
    }
}
