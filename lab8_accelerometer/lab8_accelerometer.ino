/**
 * Author:  Jonathan Schwartz
 * GWID:    G20740593
 * Class:   MAE 4195 (Mechatronics Design Lab)
 * 
 * This program reads in data from an ADXL337 accelerometer
 * and manipulates the data, returning it in a useful form. (converts from
 * 8 bit voltage readings to accerlerations in m/s^2)
 * 
 * Analog 0: x reading
 * Analog 1: y reading
 * Analog 2: z reading
 */

 
int x[] = {0, 0, 0, 0, 0, 0};
int y[] = {0, 0, 0, 0, 0, 0};
int z[] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  while(!Serial) {
    ;           //wait for connection to begin broadcasting data
  }
}

void loop() {
  
  int counter = 0;

  if(counter == 0) {
    for(int i=0;i<6; i++){
      x[i] = analogRead(A0);
      y[i] = analogRead(A1);
      z[i] = analogRead(A2);
    }
  }
    
  int j = counter % 6;

  int means[] = {0, 0, 0};

  for(int i=0;i<6;i++){
    means[0] += x[i];
    means[1] += y[i];
    means[2] += z[i];
  }

  means[0] /= 6;
  means[1] /= 6;
  means[2] /= 6;

  int diffs[] = {0, 0, 0};

  diffs[0] = analogRead(A1) - means[0];
  diffs[1] = analogRead(A2) - means[1];
  diffs[2] = analogRead(A3) - means[2];
  
  
  //The accel variable is the acceleration in Newtons, output is initially in volts
  //with 5000 milli-volts split over 1024 bits. 300 mV of output equates to one g of acceleration,
  //Which is the equivalent of 9.81 m/sec^2
  double accel = sqrt(diffs[0]*diffs[0] + diffs[1]*diffs[1] + diffs[2]*diffs[2]) * 5000 / 1023 * 9.81 / 300; 
  Serial.println(accel);
  
  
  
  x[j] = analogRead(A1);  // read the input pin
  y[j] = analogRead(A2);
  z[j] = analogRead(A3);

}
