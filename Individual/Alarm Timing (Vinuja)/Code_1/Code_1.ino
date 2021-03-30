#include <Wire.h> 
#include "RTClib.h"
RTC_DS1307 rtc;
//************Buttons*********//
int mode_btn=5;
int hour_btn=6;
int min_btn=7;
int set_btn=8;

//***********Variables*******//
int mode=0;
int AlarmHours;
int AlarmMin;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  pinMode(mode_btn,INPUT);
  pinMode(hour_btn,INPUT);
  pinMode(min_btn,INPUT);
  pinMode(set_btn,INPUT);
  pinMode(13,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  if((now.hour()==AlarmHours) and (now.minute()==AlarmMin)){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  if(digitalRead(mode_btn)){
    if(mode==3){
      mode=0;
    }
    else{
      mode=mode+1;
    }
    
  }
  if(mode==0){
    Serial.println("Display Time");
    DisplayTime();
    Serial.println();
  }
  if(mode==1){
    Serial.println();
    Serial.println("Setting Alarm Hours");
    SetAlarmHours();
    Serial.print(AlarmHours);
    Serial.println();
  }
  if(mode==2){
    Serial.println();
    Serial.println("Setting Alarm minutes");
    SetAlarmMin();
    Serial.print(AlarmMin);
    Serial.println();
  }
  if(mode==3){
    Serial.print("Alarm time is set to : ");
    Serial.print(AlarmHours);
    Serial.print(':');
    digitPrint(AlarmMin);
    Serial.println();
    
  }
  delay(200);
}
void digitPrint(int num){
  if(num<10){
    Serial.print('0');
  }
  Serial.print(num);
}

void DisplayTime(){
  DateTime now = rtc.now();
  Serial.print(now.hour());
  Serial.print(':');
  digitPrint(now.minute());
  Serial.print(':');
  digitPrint(now.second());
  Serial.println();
  
}

void SetAlarmHours(){
  if(digitalRead(hour_btn)){
    if(AlarmHours==23){
      AlarmHours=0;
    }
    else{
      AlarmHours=AlarmHours+1;
    }
  }
  delay(350);
}
void SetAlarmMin(){
  if(digitalRead(min_btn)){
    if(AlarmMin==59){
      AlarmMin=0;
    }
    else{
      AlarmMin=AlarmMin+1;
    }
  }
  delay(200);
}
