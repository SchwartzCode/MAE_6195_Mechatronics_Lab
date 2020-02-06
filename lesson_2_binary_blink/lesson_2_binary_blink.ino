
void setup() {
  DDRA = 0b11111111; //setting all pins to output
}

void loop() {
  PORTA = 0b10101010;
  delay(500);
  PORTA = 0b01010101;
  delay(500);

}
