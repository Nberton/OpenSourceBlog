#include <LiquidCrystal.h>

/******************************************************************************************************************/
/***********     LCD Initialization Code - Don't change unless you want stuff to stop working! ********************/
/******************************************************************************************************************/
/*
 *      void init_LCD();     Call this function to set up the LCD screen for use
 *      void LCD_off();      Call this function to turn off the backlight of the screen. Note that this leaves the LCD still on, but not visible
 *      void LCD_on();       Call this function to turn the backlight back on. The LCD starts on by default
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */





                      
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28);
int __counter = 0; //Global counter variable for contrast PWM
void init_LCD(){__init_LCD();}

void __init_LCD(){
  pinMode(24, OUTPUT); //K
  pinMode(26, OUTPUT); //A
  pinMode(54, OUTPUT); //VSS
  pinMode(52, OUTPUT); //VDD
  pinMode(50, OUTPUT); //Contrasty pin
  digitalWrite(24, LOW); //Backlight
  digitalWrite(26, HIGH); //Backlight
  digitalWrite(54, LOW); //GND
  digitalWrite(52, HIGH); //VDD
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); 
  // Timer0 is used for millis() - we'll just interrupt
  // in the middle and call the compA
  OCR0A = 0x01;
  TIMSK0 |= _BV(OCIE0A);
}
SIGNAL(TIMER0_COMPA_vect) 
{
   __counter++;
   if (__counter > 14){
      digitalWrite(50,HIGH);
      __counter = 0;
   }
   else if (__counter > 3){
      digitalWrite(50, LOW);
   }
}


//turn lcd backlight off
void lcd_off(){
  digitalWrite(26, LOW); //Backlight
}

//turn lcd backlight on
void lcd_on(){
  digitalWrite(26, HIGH); //Backlight
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/
/*******************************************************************************************************************/


bool count = false;
int time = 0;

void setup() { 
  // initialize the serial communications:
  Serial.begin(9600);
  init_LCD();


}

void loop() {

  lcd.home();
  String message = Serial.readString();
  
  if(message.length() > 0){
           lcd.clear();
      /* Command Structure
         \t is set
         \s is start
         \p is stop
       
      */ 
      //set behavior
      if (message.charAt(0) == '\\' && message.charAt(1) == 't'){
         //
        time = message.substring(2).toInt();
        lcd.print(time);
      }

      //start behavior  
      if (message.charAt(0) == '\\' && message.charAt(1) == 's'){
        lcd.print("starting");
        count = true;
      }
       
      //stop behavior
      if (message.charAt(0) == '\\' && message.charAt(1) == 'p'){
        lcd.print("pausing");
        count = false;
      }
      int i = 0;
//      lcd.clear();
//      while(i < (message.length()-1)){
//        if(message.charAt(i) == '\\' && message.charAt(i+1) == 'n'){
//          lcd.setCursor(0,2);
//          i++;
//        } else{
//          lcd.print(message.charAt(i));
//
//        }
//        i++;
//        if(i == (message.length() - 1)){
//            lcd.print(message.charAt(i));
//        }        
//      }
  }
  //countdown
  Serial.print(time);
  Serial.print(count);
  if (count == true && time != 0){
    time = time -1;
    lcd.clear();
    lcd.print(time);
  }
  lcd.setCursor(0, 1);
}

