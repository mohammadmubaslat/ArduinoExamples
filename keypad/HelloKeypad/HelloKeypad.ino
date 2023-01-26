
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
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
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

    
  lcd.print("Hello, From");
  lcd.setCursor(0,1);
  lcd.print("Arduino_uno_guy");
}
  
void loop(){
  char key = keypad.getKey();
   //delay(10);
  


  if (key){
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println(key);
    lcd.write(key);
    //delay(1000);

  }
}
