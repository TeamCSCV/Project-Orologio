// include the library LiquidCrystal
#include <LiquidCrystal.h>

// initialize the pins

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int select_button = 6;
int back_button = 7;
int down_button = 8;
int up_button = 9;  //declare my buttons

String initial_state = "Digital Clock";
String state = "Initial";

void setup() {
  pinMode(select_button,INPUT);
  pinMode(back_button,INPUT);
  pinMode(down_button,INPUT);
  pinMode(up_button,INPUT);    // pinmodes for the main 4 buttons
  lcd.begin(16, 2);     // number of columns and rows in the display
  lcd.print(initial_state);   //print a message in the display
 
}  

void loop() {
  int select_state = digitalRead(select_button);
  if (select_state == HIGH){      //user press the select button
    select();
   }
   
  int back_state = digitalRead(back_button);
  if (back_state == HIGH){       //user press the back button
    back();
  }
  
  int down_state = digitalRead(down_button);
  if (down_state == HIGH){      //user press the down button
    down();
  }

  int up_state = digitalRead(up_button);
  if (up_state == HIGH){       //user press the up button
    up();
  }
}

void select(){   //what to do when the user press the select button
  if (state == "Initial") {
    state = "Menu_1";
    lcd.clear();
    lcd.print("1)Set Alarms");
    lcd.setCursor(0,1);
    lcd.print("2)Set Time");
  }
}

void back(){  //what to do when the user press the back button
  if (state == "Menu_1" or state == "Menu_2" or state == "Menu_3"){
    state = "Initial";
    lcd.clear();
    lcd.print(initial_state);
  }
}

void down(){   //what to do when the user press the down button
  if (state == "Menu_1"){
    state = "Menu_2";
    lcd.clear();
    lcd.print("3)Existing Alarms");
    lcd.setCursor(0,1);
    lcd.print("4)Change alarms");
    delay(500);
  }
  else if (state == "Menu_2") {
    state = "Menu_3";
    lcd.clear();
    lcd.print("5)Factory Reset");
    delay(500);
  }
}

void up(){   //what to do when the user press the up button
  if (state == "Menu_2"){
    state = "Menu_1";
    lcd.clear();
    lcd.print("1)Set Alarms");
    lcd.setCursor(0,1);
    lcd.print("2)Set Time");
    delay(500);
  }
  else if (state == "Menu_3"){
    state = "Menu_2";
    lcd.clear();
    lcd.print("3)Existing Alarms");
    lcd.setCursor(0,1);
    lcd.print("4)Change alarms");
    delay(500);
  }
}
