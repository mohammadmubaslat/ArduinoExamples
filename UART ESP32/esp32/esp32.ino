/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-serial-monitor
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("esp32io.com");
  delay(1000);
}
