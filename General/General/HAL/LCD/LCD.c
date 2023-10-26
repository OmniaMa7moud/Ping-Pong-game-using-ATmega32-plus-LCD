/*
 * LCD.c
 *
 * Created: 10/20/2023 2:30:45 PM
 *  Author: omnia
 */ 	
#include <util/delay.h>
#include "LCD.h"

void LCD_INIT()
{
	
	_delay_ms(40);
	LCD_instruction(0x33);
	_delay_ms(1);
	LCD_instruction(0x32);
	_delay_ms(1);
	//function set
	LCD_instruction(FOUR_BIT_MODE);//0x28
	_delay_ms(1);
	LCD_instruction(0x0c);
	_delay_ms(1);
	LCD_instruction(CLEAR_DISPLAY);//0x01
	_delay_ms(1);
	LCD_instruction(RETURN_HOME); // 0x02
	_delay_ms(1);
	/*
	LCD_instruction(DISPLAY_ON_CURSOR_BLINK);//0x0f
	_delay_ms(1);
	LCD_instruction(CURSOR_MOVE_RIGHT);//0x06
	_delay_ms(2);
	*/
	/*
	 _delay_ms(100);                              //Wait for LCD to boot
	 LCD_instruction(0x30);                        //Init function set 1
	 _delay_ms(100);
	 LCD_instruction(0x30);                        //Init function set 2
	 _delay_us(100);
	 LCD_instruction(0x30);                        //Init function set 3
	 _delay_us(100);
	 LCD_instruction(0x20);                        //Function set (set 4 bit mode)
	 _delay_us(100);
	 LCD_instruction(0x28);                       //Funcion set I=1, N=0, F=0
	 //sendInitCommand(0x8);
	 _delay_us(60);
	 LCD_instruction(0x80);                        //On/off control D=0, C=0, B=0
	 //sendInitCommand(0x8);
	 _delay_us(60);
	 LCD_instruction(0x01);                           //Clear display
	 //sendInitCommand(0x1);
	 _delay_ms(60);
	 LCD_instruction(0x06);                           //Entry mode set I/D=1, S=0
	 //sendInitCommand(0x6);
	 _delay_us(60);
	 LCD_instruction(0x0C);                           //On/off control D=1, C=0, B=0
	 //sendInitCommand(0xC);
	 _delay_us(60);
	
	*/
}

void LCD_EN()
{
	DIO_SetPinVal(ENPORT, ENPIN, HIGH);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, LOW);
	_delay_ms(2);
}

void LCD_instruction(unsigned char cmnd)
{
	
	//4bit mode
	DIO_SetPinVal(RSPORT, RSPIN, 0);	
	//LCD_PORT = (LCD_PORT & 0x0F) | (cmnd & 0xF0);
		DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(cmnd,4));
		DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(cmnd,5));
		DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(cmnd,6));
		DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(cmnd,7));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);		
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);


	//LCD_PORT = (LCD_PORT & 0x0F) | (cmnd << 4);
	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(cmnd,0));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(cmnd,1));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(cmnd,2));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(cmnd,3));
	//LCD_PORT &= ~ (1<<RSPIN);	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);
	
}

void LCD_write_char(unsigned char data)
{
	
	//For 4-Bit Mode
	DIO_SetPinVal(RSPORT, RSPIN, 1);
	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(data,4));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(data,5));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(data,6));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(data,7));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);

	//LCD_PORT = (LCD_PORT & 0x0F) | (data << 4); 
	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(data,0));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(data,1));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(data,2));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(data,3));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);
	
}


void LCD_SEND_STRING(char *data)
{
	while((*data)!='\0')
	{
		LCD_write_char(*data);
		data++;
	}
}


void LCD_CLR_SCREEN(void)
{
	LCD_instruction(CLEAR_DISPLAY);
	_delay_ms(10);                    //At least 1.5 ms
}


void LCD_MOVE_CURSOR(unsigned char row , unsigned char column)
{
	//Rows Range (1,2)
	//Columns Range (1,16)
	//Function that updates Address Counter (AC)
	
	unsigned char data = 0x80;
	if(row>4||row<1||column>20||column<1)
	{
		data=0x80;                       //Upper Left Location on Screen
	}
	else if(row==1)
	{
		data=0x80+column-1 ;
	}
	else if (row==2)
	{
		data=0xc0+column-1;
	}
	else if(row==3)
	{
		data=0x94 +column-1 ;
	}
	else if (row==4)
	{
		data=0xD4 +column-1;
	}
	LCD_instruction(data);
	_delay_ms(1);
}
