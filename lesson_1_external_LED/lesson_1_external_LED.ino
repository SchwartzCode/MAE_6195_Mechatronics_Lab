int PIN = 8;

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  for(int i=0;i<5;i++){
    for(int i=0;i<7;i++){  
      digitalWrite(PIN, HIGH);
      delay(75);
      digitalWrite(PIN, LOW);
      delay(75);
    }
    delay(150);
  }
}
