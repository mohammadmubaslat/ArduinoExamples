
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

int Relay = 9;
#define pump1 10
#define ONE_WIRE_BUS 11
#define servo_1_pin 22
#define servo_2_pin 24
#define servo_3_pin 26



int servo1_Postion = 0;    
int servo2_Postion = 0;
int servo3_Postion = 0;

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


void setup(){

  // start serial port
  Serial.begin(115200);

  
  lcd.init();
  lcd.backlight();
  
  inputString.reserve(1);
  
  lcd.setCursor(0,0);  
  lcd.print("0#Normal/1#Dark");
  lcd.setCursor(0,1);
  lcd.print("2#Sugar+/3#NoSug");
}



void loop(){

  
  char key = keypad.getKey();
   //delay(10);

  if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } 
  else if(key == '#') {
    
     if(inputString == "0") {
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
   
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Choose from 0->3");
    lcd.setCursor(0,1);
    lcd.print("Then press #"); 
    inputString = "";
  }
}

}
