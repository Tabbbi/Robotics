void setup() {
  Serial.begin(9600);
}
void loop() {
  for (int i=1; i <= 100; i++) {
    if((i%3 == 0) && (i%5 == 0)) {
      Serial.println("FizzBuzz");
    } else if (i%5 == 0){
      Serial.println("Buzz");
    } else if (1%3 == 0){
      Serial.println("Fizz");
    } else {
      Serial.println(i);
    }
  }
}
