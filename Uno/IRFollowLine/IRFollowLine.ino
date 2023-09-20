#define BUTTON_1 2
#define BUTTON_2 4

#define NUMLED 3 // number of LEDs
#define LED1 7   // green
#define LED2 12  // yellow
#define LED3 8   // red

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
bool following = false;

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

  if (!calibrated && !digitalRead(BUTTON_1)) {
    delay(200);
    autoCalibration();
  }

  if (calibrated && !digitalRead(BUTTON_2)) {
    running = true;
  }

  if (running){
    if (sensorReading < (edgeValue - 50)) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      setSpeeds(175, 20);
    } else if (sensorReading > (edgeValue + 50)) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      setSpeeds(20, 175);
    } else {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      setSpeeds(170, 170);
    }
  }
}