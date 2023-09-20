void autoCalibration() {
  setSpeeds(200, 150);
  calibration();
  setSpeeds(-150, -250);
  calibration();
  setSpeeds(0, 0);
  edgeValue = (minValue + maxValue) / 2;
  calibrated = true;
}

void calibration() {
  int value;
  for (int i = 0; i < 5000; i++) {
    value = analogRead(IR_SENSOR);
    if (value < minValue) {
      minValue = value;
    }
    if (value > maxValue) {
      maxValue = value;
    }
  }
}