

#define RXp2 16
#define TXp2 17
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200);
  //Serial2.begin(9600, SERIAL_8N1, RXp2 , TXp2);
}
void loop() {
    //Serial.println("Message Received: ");
    //Serial.println(Serial2.readString());

    Serial2.write("1");
    Serial2.println();
    delay(1500);
        Serial2.write("2");
        //Serial.println("2");
        Serial2.println();
        delay(1500);

}
