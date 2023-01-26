int Relay = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);

  digitalWrite(Relay,HIGH);

  delay(9000);

  digitalWrite(Relay,LOW);

}\
