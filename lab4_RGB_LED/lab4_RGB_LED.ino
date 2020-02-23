const int red_light_pin = 4;
const int green_light_pin = 3;
const int blue_light_pin = 2;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  RGB_color(255,0,0); //red
  delay(500);
  RGB_color(0,255,0); //green
  delay(500);
  RGB_color(0,0,255); //blue
  delay(500);

  // RAINBOW TIME BABY
  RGB_color(255,0,0); //red
  delay(1500);
  RGB_color(255,165,0); //orange
  delay(1500);
  RGB_color(255,255,0); //yellow
  delay(1500);
  RGB_color(0, 128, 0); //green
  delay(1500);
  RGB_color(0,0,255); //blue
  delay(1500);
  RGB_color(111,0,255); //indigo
  delay(1500);
  RGB_color(128, 0, 128); //purple
  delay(1500);

  
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
