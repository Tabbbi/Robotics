void autoCalibration() {
    for (int i = 0; i < 120; i++) {
        if (i > 30 && i <= 90) {
        motors.setSpeeds(-200, 200);
        } else {
        motors.setSpeeds(200, -200);
        }
        sensors.calibrate();
    }
    motors.setSpeeds(0, 0);
}