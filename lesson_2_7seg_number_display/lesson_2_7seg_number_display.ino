// PIN MAP (register A, pins 22-29)
//   ** This is designed for the SMA42056 Single Digit LED Display **
//
//  PIN  |  POSITION
//======================
//   22  |  Middle
//   23  |  Top Left
//   24  |  Bottom Left
//   25  |  Bottom Middle
//   26  |  Bottom Right
//   27  |  Top Right
//   28  |  Top Middle
//   29  |  - n/a -

//bytes lighting LEDS to represent digits in order (i.e. 0,1,2,3,...9)
byte nums[] = {0b01111110, 0b00110000, 0b01101101, 0b01111001, 0b00110011, 0b01011011, 0b01011111, 0b01110000, 0b01111111, 0b01111011};

void setup() {
  DDRA = 0b01111111; //setting all used pins to output (pin29 is the only one not used)
  Serial.begin(9600);
}

void loop() {

  bool newData = false;
  
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if(isDigit(receivedChar)) {
      int readInt = receivedChar - '0';
      PORTA = nums[readInt];
      newData = false;
    }
  }

}
