int R1=3,R2=4,R3=5,R4=6,C1=7,C2=8,C3=9;
int rows[]={R1,R2,R3,R4};
int columns[]={C1,C2,C3};
int keys[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
void setup() {
  // put your setup code here, to run once:
  pinMode (R1,OUTPUT);pinMode (R2,OUTPUT);pinMode (R3,OUTPUT);pinMode (R4,OUTPUT);pinMode (C1,INPUT);pinMode (C2,INPUT);pinMode (C3,INPUT);pinMode(10,OUTPUT);pinMode(11,OUTPUT);pinMode(12,OUTPUT);pinMode(13,OUTPUT);
   Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
      led();    
}
int keyInput() {
    
    for (int r=0; r<=3; r++){
      digitalWrite(rows[r],HIGH);
    }
    for (int r=0; r<=3; r++){
       digitalWrite(rows[r],LOW);
       
      for (int c=0; c<=2; c++){
        digitalWrite(columns[c],HIGH);
        if ((digitalRead(columns[c])==0) and (digitalRead(rows[r])==0)) {
          int pressed=keys[r][c];
    Serial.println(pressed);
          return pressed;}
        }
     digitalWrite(rows[r],HIGH);
     }    
     return 70;
}

void led(){
   int key= keyInput();
   if (key==70){ 
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
     } 
   else{
    int binary[4]={0,0,0,0};
  for (int i=3; i>=0 ;i--){
    binary[i]=key%2;
    key=key/2;
    
    for (int i=0; i<=3; i++){
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
