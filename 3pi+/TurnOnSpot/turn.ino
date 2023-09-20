void turn(float pDeg) {
  int speed = 40;
  int countsLeft = 0;
  int countsRight = 0;

  float alpha = abs(pDeg) * DEGtoRAD;
  float distance = alpha * 43;
  float wheelCircumference = 36 * PI;
  float ticksPerMM = CPR / wheelCircumference;

  int impulses = ticksPerMM * distance;
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();

  if (pDeg >= 0) {
    motors.setSpeeds(40, -40);
  } else {
    motors.setSpeeds(-40, 40);
  }

  while ((abs(countsLeft) + abs(countsRight)) / 2 < impulses) {
    countsLeft = encoders.getCountsLeft();
    countsRight = encoders.getCountsRight();
  }
  motors.setSpeeds(0, 0);
}