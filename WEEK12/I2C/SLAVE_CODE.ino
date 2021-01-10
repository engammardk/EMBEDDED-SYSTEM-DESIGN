// i2c escravo
#include <Wire.h>
void setup() {
// Endereço é 5
  Wire.begin(5);
  Wire.onReceive(react);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
}

void react(int n) {
  while (Wire.available()) {
    char c = Wire.read();
    if (c=='H') {
      digitalWrite(13,HIGH);
    } else {
      digitalWrite(13,LOW);
    }
  }
}
