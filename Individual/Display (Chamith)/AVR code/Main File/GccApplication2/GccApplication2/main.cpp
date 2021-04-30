/*
 * display.cpp
 * Created by Ranathunga R.A.C.D 190501V
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL			
#include <avr/io.h>			
#include <util/delay.h>			

#define LCD_Dir  DDRB			//LCD data port direction
#define LCD_Port PORTB			//LCD data port
#define RS PB0				   //register select pin
#define EN PB1 				  // Enable pin


void LCD_Command( unsigned char cmnd )     //function to initialize a command given as a hexadecimal number
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); 
	LCD_Port &= ~ (1<<RS);		
	LCD_Port |= (1<<EN);		
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); 
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}



void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); 
	LCD_Port |= (1<<RS);		//RS = 1
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}



void LCD_Init (void)			//Initialize the display
{
	LCD_Dir = 0xFF;			//LCD data direction is output
	_delay_ms(20);			
	
	LCD_Command(0x02);		
	LCD_Command(0x28);              
	LCD_Command(0x0c);              //Command - Display on Cursor off
	LCD_Command(0x06);              //Command - shift cursor to right
	LCD_Command(0x01);              //Command - Clear display
	_delay_ms(2);
}




void LCD_String (char *str)		//Writing a string on LCd display
{
	int i;
	for(i=0;str[i]!=0;i++)		
	{
		LCD_Char (str[i]);
	}
}



void LCD_Clear()             //Function to clear display and come back to home position
{
	LCD_Command (0x01);		
	_delay_ms(2);
	LCD_Command (0x80);		
}


void Time()             //Function to write time to display(Here I have used the test "Time". (I have to link RTC code here)
{
	LCD_Clear();
	LCD_String("Time...");
	_delay_ms(500);
}


void Select()            //What to do when the user press the select button
{
	LCD_Clear();
	LCD_String("Pressed Select");
	_delay_ms(500);
}

void Left()              //What to do when the user press the left arrow
{
	LCD_Clear();
	LCD_String("Pressed Left");
	_delay_ms(500);
}

void Right()              //What to do when the user press the right arrow
{
	
	LCD_Clear();
	LCD_String("Pressed Right");
	_delay_ms(500);
}

void Up()                  //What to do when the user press the up arrow
{
	LCD_Clear();
	LCD_String("Pressed Up");
	_delay_ms(500);
}

void Down()              //What to do when the user press the down arrow
{
	LCD_Clear();
	LCD_String("Pressed Down");
	_delay_ms(500);
}

void Back()             //What to do when the user press the back button
{
	LCD_Clear();
	LCD_String("Pressed Back");
	_delay_ms(500);
}

int main(void)           //main function continuously looks for a signal from the user
{
    DDRD = 0x00;
	LCD_Init();
	Time();
    while (1) 
    {
		if (PIND == 0x01){
			Select();
		}
		else if (PIND == 0x02){
			Left();
		}
		else if (PIND == 0x04){
			Down();
		}
		else if (PIND == 0x08){
			Up();
		}
		else if (PIND == 0x10){
			Right();
		}
		else if(PIND == 0x20){
			Back();
		}
	}
}
