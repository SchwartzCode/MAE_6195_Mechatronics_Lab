void setup() {
  pinMode(7, OUTPUT);

}

void loop() {
  for(int i=0;i<256;i++){
    analogWrite(7, i);
    delay(8);
  }
  for(int i=255;i>-1;i--){
    analogWrite(7,i);
    delay(8);
  }
}
