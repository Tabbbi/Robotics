#define BUTTON_1 2
#define BUTTON_2 4

#define NUMLED 3 // number of LEDs
#define LED1 7
#define LED2 12
#define LED3 8

int pinLeds[NUMLED] = {LED1, LED2, LED3};

bool calibrated = false;

#define IR_SENSOR A0

#define IN1 9 // right motor
#define IN2 10 // right motor
#define IN3 6 // left motor
#define IN4 5 // left motor

int minValue = 1000;
int maxValue = -1;
int edgeValue;

bool running = false;

void setup() {
//  Serial.begin(115200);

  for (int i = 0 ; i < NUMLED; i++) {
    pinMode(pinLeds[i], OUTPUT);
  }

  pinMode(IR_SENSOR, INPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  initDRV8833();
  
  doLightAnimation();
}

void loop() {
  int sensorReading = analogRead(IR_SENSOR);
/*  
  Serial.print(sensorReading);
  Serial.print(" | ");
  Serial.print(edgeValue);
  Serial.println();
*/
  if (!calibrated && !digitalRead(BUTTON_1)) {
    delay(200);
    autoCalibration();
  }
  if (!digitalRead(BUTTON_2) && calibrated) {
    running = true;
  }

  if (running){
    setSpeeds(150, 150);
    if (sensorReading < edgeValue) {
      setSpeeds(-150, -200);
      delay(100);
    }
  }
//  Serial.println(sensorReading < edgeValue);
}