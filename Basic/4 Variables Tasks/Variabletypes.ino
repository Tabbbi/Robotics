void setup() {
  Serial.begin(9600);
}

void loop() {
  int zahl1 = 1;
  Serial.print("int(1): ");
  Serial.println(zahl1);

  float zahl2 = 2.0;
  Serial.print("float(2.0): ");
  Serial.println(zahl2);

  double zahl3 = 14.35;
  Serial.print("double(14.35): ");
  Serial.println(zahl3);

  int zahl4 = -2365;
  Serial.print("int(-2365): ");
  Serial.println(zahl4);

  long zahl5 = 67542;
  Serial.print("int(67542): ");
  Serial.println(zahl5);

  long zahl6 = -34543;
  Serial.print("int(-34543): ");
  Serial.println(zahl6);
}
