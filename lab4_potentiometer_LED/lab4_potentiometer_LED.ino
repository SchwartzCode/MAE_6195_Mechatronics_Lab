void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int val = analogRead(A0);
  analogWrite(2, val / 4);
}
