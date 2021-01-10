// I2C master
#include <Wire.h>
void setup() {
  Wire.begin();
  pinMode(12, INPUT_PULLUP);
}
void loop() {
  
    // Endereço do Escravo é 5
    if (digitalRead(12) == LOW) {
      Wire.beginTransmission(5);
      Wire.write('H');
      Wire.endTransmission();
            delay(100);
    } else {
      Wire.beginTransmission(5);
      Wire.write('L');
      Wire.endTransmission();
            delay(100);
    }
}
