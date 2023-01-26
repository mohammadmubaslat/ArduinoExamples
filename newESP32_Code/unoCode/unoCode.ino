#include <Servo.h>

char c = '2';
Servo myservo;

int pos = 0;

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  myservo.attach(11);
}

void loop() {
  if (Serial.available()) { // check if there is data available to read
    char c = Serial.read(); // read a single character
    Serial.println(c);

    if (c == '0') {
      digitalWrite(13, LOW);
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
      delay(500);
    } else if (c == '1') {
      digitalWrite(13, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
      delay(500);
    } else if (c == '2') {
      digitalWrite(3, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(7, LOW);
      delay(500);
    } else if (c == '3') {
      digitalWrite(13, LOW);
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
    for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    delay(15);                       
  }
 
      delay(500);
    } else if (c == '4') {
      digitalWrite(13, LOW);
      digitalWrite(3, LOW);
      digitalWrite(7, HIGH);
      delay(500);
    }

  }



}
