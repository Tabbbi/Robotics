#define LED 2
#define LED2 3
int x = 0;
int pause = 0;
int wannpause = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(LED2,OUTPUT);
}

void loop() {
  digitalWrite(LED,HIGH); 
  delay(1000);
  digitalWrite(LED,LOW);
  if (wannpause == 8) {
    pause = 4;
  } 
  if (wannpause != 8) {
    pause = 1;
  }
  for(int i = 0; i<pause; i++){
    delay(1000); 
    if (wannpause == 8) {
      wannpause = 0;
    } 
  }
  pause = 0;
  x++;
  wannpause++;

  if(x == 4){
    digitalWrite(LED2,LOW);
    x = 0;
  }
  if(x == 2){
    digitalWrite(LED2,HIGH);
  } 
}