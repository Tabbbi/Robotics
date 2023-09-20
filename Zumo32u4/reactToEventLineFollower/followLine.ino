void followLine(int pPosition) {    
    static int oldE;
    int newE = line - pPosition;
    float diff = newE - oldE;
    int deltaSpeed = (kp * newE) + (kd * diff);
    oldE = newE;
    motors.setSpeeds(avSpeed - deltaSpeed, avSpeed + deltaSpeed);
}