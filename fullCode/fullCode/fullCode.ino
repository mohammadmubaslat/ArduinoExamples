
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>  
#include <Servo.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
String inputString = "";

Servo servo1;                          
Servo servo2;
Servo servo3;

#define ONE_WIRE_BUS 9
#define Relay 10
#define pump1 11
#define servo_1_pin 22
#define servo_2_pin 24
#define servo_3_pin 26
#define IR1 23
#define IR2 25
#define trig1 30
#define echo1 31
#define trig2 32
#define echo2 33
#define trig3 34
#define echo3 35

int servo1_Postion = 0;    
int servo2_Postion = 0;
int servo3_Postion = 0;

int distance=0, t=0;
int ultraSonic1 = 0, ultraSonic2 = 0, ultraSonic3 = 0;

float myTemp;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;


char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8,7,6,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27, 16, 2);

int small = 40;
int medium = 50;
int large = 60;


 bool IR1_flag;
 bool IR2_flag;


  void lcd_screen_init() {
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("0#Normal/1#Dark");
  lcd.setCursor(0,1);
  lcd.print("2#Sugar+/3#NoSug");
 
  }
void setup(){

  // start serial port
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  inputString.reserve(1);
  lcd_screen_init();
  

  Serial.println("Dallas Temperature IC Control Library Demo");

  Serial.print("Locating devices...");
  sensors.begin();
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
 
  Serial.print("Device 0 Address: ");
  printAddress(insideThermometer);
  Serial.println();

  sensors.setResolution(insideThermometer, 9);
 
  Serial.print("Device 0 Resolution: ");
  Serial.print(sensors.getResolution(insideThermometer), DEC); 
  Serial.println();


  pinMode(Relay, OUTPUT);
  digitalWrite(Relay,LOW);

  servo1.attach (servo_1_pin); // shuger      
  servo2.attach(servo_2_pin); // niskafae
  servo3.attach(servo_3_pin); // coffee mate

  pinMode(pump1,OUTPUT);
  digitalWrite(pump1,HIGH);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

   IR1_flag = true;
   IR2_flag = true;

  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
 
}

  void printTemperature(DeviceAddress deviceAddress)
{
 
  myTemp = sensors.getTempC(deviceAddress);
  if(myTemp == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temp C: ");
  Serial.print(myTemp);
  Serial.print(" Temp F: ");
  Serial.println(DallasTemperature::toFahrenheit(myTemp)); // Converts tempC to Fahrenheit
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

void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

void loop(){

 char key = keypad.getKey();
   

 Serial.println("key is ");
 Serial.println(key);
 
// ultraSonic1 = ultraSonicFunction(trig1, echo1);
// ultraSonic2 = ultraSonicFunction(trig2, echo2);
// ultraSonic3 = ultraSonicFunction(trig3, echo3);
 
 Serial.println("ultrasonic value -->");
  Serial.println(ultraSonic1);
  Serial.println(ultraSonic2);
  Serial.println(ultraSonic3);


  
int IR1Value = digitalRead(IR1);
int IR2Value = digitalRead(IR2);

        
//       servo1.write (18);         
//       servo2.write (27);
//       servo3.write (20); 

  
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  printTemperature(insideThermometer); // Use a simple function to print out the data
  Serial.println(myTemp);


  if(myTemp < 50) {
        digitalWrite(Relay,HIGH);          
  }
  if(myTemp >= 50) {
        digitalWrite(Relay,LOW);          
  }

  else{    
 

//      else if(!IR2Value && IR2_flag){
//        while(medium){
//        servo1.write(0);
//        servo2.write(0);
//        servo3.write(0);
//        delay(90);
//        medium--;
//          }
//          digitalWrite(pump1, HIGH);
//          delay(3000);
//          digitalWrite(pump1, LOW); 
//          IR2_flag = false;
//
//          servo1.write (18);         
//          servo2.write (27);
//          servo3.write (20); 
//        }
    }
  
    

 

  if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } 
  else if(key == '#') {
    
     if(inputString == "0") { //small
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println(inputString);
    lcd.print("0#");
    lcd.setCursor(1,0);
    Serial.println(key);
    lcd.write(key);

    lcd.setCursor(0,1);
    Serial.println("Normal");
    lcd.print("Normal");

    inputString = "";

   if(IR1Value == 0 && IR1_flag == true){
      while(small){
        servo1.write(0);
        servo2.write(0);
        servo3.write(0);
        delay(90);
        small--;  
        }
         Serial.println("pump started ************* ");
          digitalWrite(pump1, HIGH);
          delay(2000);
          Serial.println("before end************* ");
          digitalWrite(pump1, LOW);
          Serial.println("pump finished ************* ");
          IR1_flag = false;
          
          servo1.write (18);         
          servo2.write (27);
          servo3.write (20); 
      }

      lcd_screen_init();

     } 

   
    else if(inputString == "1") {  
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println(inputString);
    lcd.print("1#");
    lcd.setCursor(1,0);
    Serial.println(key);
    lcd.print(key);

    lcd.setCursor(0,1);
    Serial.println("Dark");
    lcd.print("Dark");

    inputString = "";




   lcd_screen_init();
  }
 else if(inputString == "2") {
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println(inputString);
    lcd.print("2#");
    Serial.println(key);
    lcd.setCursor(0,1);
    Serial.println("Sugar plus plus");
    lcd.print("Sugar plus plus");

    inputString = "";


    lcd_screen_init();

  }
 else if(inputString == "3") {
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println(inputString);
    lcd.print("3#");
    Serial.println(key);
    lcd.setCursor(0,1);
    Serial.println("No Sugar");
    lcd.print("No Sugar");

    inputString = "";
    


  lcd_screen_init();
  }

  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Choose from 0->3");
    lcd.setCursor(0,1);
    lcd.print("Then press #"); 
    inputString = "";
    key = '/';
    delay(1500);
    lcd_screen_init();
  }
}

}
