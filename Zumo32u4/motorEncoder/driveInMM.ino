double linear = 1.05;
double kp = 1.2;
double dSpeed;
double e;

int driveInMM(int pDistance) {
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetRight();
    long avgTicks = (encoders.getCountsLeft() + encoders.getCountsRight()) / 2;
    while (avgTicks <= getTicks(pDistance) - 90) {
        e = encoders.getCountsLeft() - (encoders.getCountsRight() * linear);
        dSpeed = kp * e;
        avgTicks = (encoders.getCountsLeft() + encoders.getCountsRight()) / 2;
        motors.setSpeeds(400 - dSpeed, 400 + dSpeed);
    } 
    while (avgTicks < getTicks(pDistance)) {
        e = encoders.getCountsLeft() - (encoders.getCountsRight() * linear);
        dSpeed = kp * e;
        avgTicks = (encoders.getCountsLeft() + encoders.getCountsRight()) / 2;
        motors.setSpeeds(200 - dSpeed, 200 + dSpeed);
    }
    motors.setSpeeds(0, 0);
}

int getTicks(int pDistance) {
    return (pDistance / 10) / (11.9 / 909.7);
}
    