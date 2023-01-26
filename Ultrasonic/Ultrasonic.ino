#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5
#define trig3 6
#define echo3 7

int ultraSonic1 = 0, ultraSonic2 = 0, ultraSonic3 = 0;
int distance=0,t=0;

void setup() 
{
  Serial.begin(115200);
    pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
 
}

int ultraSonicFunction(int trig, int echo) {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t=pulseIn(echo,HIGH);
  distance=t/57;//Distance = (Speed of Sound * Time/2) = t/(1/((350*0.0001)/2))

  return distance;
}

void loop() 
{
   ultraSonic1 = ultraSonicFunction(trig1, echo1);
 ultraSonic2 = ultraSonicFunction(trig2, echo2);
 ultraSonic3 = ultraSonicFunction(trig3, echo3);
 
 Serial.println("ultrasonic value -->");
  Serial.println(ultraSonic1);
  Serial.println(ultraSonic2);
  Serial.println(ultraSonic3);

  delay(1500);
  
}
