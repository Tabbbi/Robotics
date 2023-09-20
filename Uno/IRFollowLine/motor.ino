const int pinDRV8833[4] = {IN1, IN2, IN3, IN4}; 

void initDRV8833() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pinDRV8833[i], LOW);
    pinMode(pinDRV8833[i], OUTPUT);
  }
}

void setSpeeds(int pSpeedLeft, int pSpeedRight) {

  static const float speedCalibration = 1.2;

  int speedLeft = int(speedCalibration * pSpeedLeft);
  int speedRight = pSpeedRight;

  // right motor
  if (speedRight < 0) // Rückwärts
  {
    speedRight = abs(speedRight);
    digitalWrite(pinDRV8833[0], LOW);
    analogWrite(pinDRV8833[1], speedRight); // 
  }
  else if (speedRight > 0)  // 
  {
    analogWrite(pinDRV8833[0], speedRight); // 
    digitalWrite(pinDRV8833[1], LOW);
  }
  else { // Stoppen mit Motorbremse
    digitalWrite(pinDRV8833[0], HIGH);
    digitalWrite(pinDRV8833[1], HIGH);
  }

  // left motor
  if (speedLeft < 0) // 
  {
    speedLeft = abs(speedLeft);
    digitalWrite(pinDRV8833[2], LOW);
    analogWrite(pinDRV8833[3], speedLeft);
  }
  else if (speedLeft > 0)  // 
  {
    analogWrite(pinDRV8833[2], speedLeft);
    digitalWrite(pinDRV8833[3], LOW);
  }
  else { // Stoppen mit Motorbremse
    digitalWrite(pinDRV8833[2], HIGH);
    digitalWrite(pinDRV8833[3], HIGH);
  }
}
