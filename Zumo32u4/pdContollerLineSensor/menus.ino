void kpMenu() {
    lcd.clear();
    lcd.print("Kp is: ");
    motors.setSpeeds(0, 0);
    delay(500);
    while (!buttonA.getSingleDebouncedPress()) {
        if (buttonB.getSingleDebouncedPress()) {
            kp = kp - 0.05;
        }
        else if (buttonC.getSingleDebouncedPress()) {
            kp = kp + 0.05;
        }
        lcd.gotoXY(0, 1);
        lcd.print(kp);
        lcd.gotoXY(0, 0);
    }
}

void kdMenu() {
    lcd.clear();
    lcd.print("Kd is: ");
    motors.setSpeeds(0, 0);
    while (!buttonA.getSingleDebouncedPress()) {
        if (buttonB.getSingleDebouncedPress()) {
            kd = kd - 0.1;
        }
        else if (buttonC.getSingleDebouncedPress()) {
            kd = kd + 0.1;
        }
        lcd.gotoXY(0, 1);
        lcd.print(kd);
        lcd.gotoXY(0, 0);
    }
}

void speedMenu() {
    lcd.clear();
    lcd.print("Speed is");
    motors.setSpeeds(0, 0);
    while (!buttonA.getSingleDebouncedPress()) {
        if (buttonB.getSingleDebouncedPress()) {
            avSpeed = avSpeed - 50;
        }
        else if (buttonC.getSingleDebouncedPress()) {
            avSpeed = avSpeed + 50;
        }
        lcd.gotoXY(0, 1);
        lcd.print(avSpeed);
        lcd.gotoXY(0, 0);
    }
}
