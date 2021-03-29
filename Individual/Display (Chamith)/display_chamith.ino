// include the library LiquidCrystal
#include <LiquidCrystal.h>

// initialize the pins

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);     // number of columns and rows in the display
  lcd.print("Digital Clock");   //print a message in the display
}  

void loop() {
}
