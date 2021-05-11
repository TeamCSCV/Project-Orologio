int R1=3,R2=4,R3=5,R4=6,C1=7,C2=8,C3=9;
int rows[]={R1,R2,R3,R4};
int columns[]={C1,C2,C3};
int keys[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
void setup() {
  // put your setup code here, to run once:
  pinMode (R1,OUTPUT);pinMode (R2,OUTPUT);pinMode (R3,OUTPUT);pinMode (R4,OUTPUT); // rows  
  pinMode (C1,INPUT);pinMode (C2,INPUT);pinMode (C3,INPUT); // columns
  pinMode(10,OUTPUT);pinMode(11,OUTPUT);pinMode(12,OUTPUT);pinMode(13,OUTPUT); //LEDs

}
void loop() {
  // put your main code here, to run repeatedly:
  led(); //calling the led function repeatedly 
}
int keyInput() {
    //Scanning the keypad repeatedly to check whether a key is pressed
    for (int r=0; r<=3; r++){ // set all row pins to HIGH
      digitalWrite(rows[r],HIGH);
    }
    for (int r=0; r<=3; r++){
       digitalWrite(rows[r],LOW); // set the current row pin to LOW
       
      for (int c=0; c<=2; c++){
        digitalWrite(columns[c],HIGH); // set the column pins to HIGH initially 
        if ((digitalRead(columns[c])==0) and (digitalRead(rows[r])==0)) { // while the current row pin is LOW check whether if any column pin is LOW
          int pressed=keys[r][c]; // obtain the pressed key
          if (pressed!=42 and pressed!=35){ // if a number is pressed
            return pressed;} // return the pressed key
          else{ // if '*' or '#' is pressed
            return 100;}
          } 
        }
      digitalWrite(rows[r],HIGH); // set the current pin again to HIGH
      }    
      return 100; // if a key is not pressed return 100 
}

void led(){
   int key= keyInput(); // obtaining the pressed key byt callig the keyInput function
   if (key==100){   // if a key is not pressed turn off all the LEDs
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
     } 
   else{          
    int binary[4]={0,0,0,0}; 
    for (int i=3; i>=0 ;i--){  // convert the pressed key from decimal to binary
      binary[i]=key%2;
      key=key/2; 
      for (int i=0; i<=3; i++){ // turn on or off the 4 LEDs according to the binary number
        if (binary[i]==0){
          digitalWrite(i+10,LOW);
          }
        else{
          digitalWrite(i+10,HIGH);
            }
           }
         }
      }    
   }
