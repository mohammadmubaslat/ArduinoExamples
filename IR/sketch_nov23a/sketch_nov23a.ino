int IRSensor = 8; // connect ir sensor to arduino pin 2
int IRSensor2 = 9; // connect ir sensor to arduino pin 2

float reading, reading1, reading2;

void setup() 
{
Serial.begin(115200);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
 pinMode (IRSensor2, INPUT);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor); 
  int statusSensor2 = digitalRead (IRSensor2); 

   Serial.println("IR 1 ");
  Serial.println( statusSensor);
  Serial.println("IR 2 ");
  Serial.println( statusSensor2);

  Serial.println();
   Serial.println();

  delay(1000);  
}
