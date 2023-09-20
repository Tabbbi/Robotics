void driveDistance(float pDistanceInMM, int pSpeed) {
  float pStraigthFaktor = 1;
  long distanceInTicks = pDistanceInMM * ticksPerMM;
  long averageEncoderTicks = 0;
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
  long ticksLeft;
  long ticksRight;
  int error = 0;
  int differential = 0;
  int dSpeed = 0;
  int error_old = 0;
  int MSPEED = pSpeed;
  while (averageEncoderTicks <= distanceInTicks) {
    ticksLeft = encoders.getCountsLeft();
    ticksRight = encoders.getCountsRight();
    averageEncoderTicks = (ticksLeft + ticksRight) / 2;
    error = ticksLeft - pStraigthFaktor * ticksRight;
    differential = error - error_old;
    error_old = error;
    dSpeed = (error * kp) + (differential * kd);
    if (averageEncoderTicks > (distanceInTicks - 95)) {
      motors.setSpeeds(10, 10);
    }
    motors.setSpeeds(MSPEED - dSpeed, MSPEED + dSpeed);
  }
  motors.setSpeeds(0, 0);
}