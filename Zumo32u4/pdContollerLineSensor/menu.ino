void menu() {
    motors.setSpeeds(0, 0);
    lcd.clear();
    lcd.print("<-B  C->");
    lcd.gotoXY(0, 1);
    lcd.print("Kp: ");
    lcd.print(kp);
    while (!buttonA.getSingleDebouncedPress()) {
        if (buttonB.getSingleDebouncedPress()) {

        }
    }
}
