/*
 * main.c
 *
 * Created: 10/20/2023 11:49:57 AM
 *  Author: omnia
 */ 
#define F_CPU 8000000UL
#include "..\MCAL\DIO\DIO.h"
#include <util/delay.h>
#include "../HAL/LCD/LCD.h"

void game()
{
	LCD_instruction(0x40);
	_delay_ms(3);
	//Human Custom Char(Location =0)
	LCD_write_char(0x04);
	LCD_write_char(0x0A);
	LCD_write_char(0x04);
	LCD_write_char(0x0e);
	LCD_write_char(0b00010101);
	LCD_write_char(0b00000100);
	LCD_write_char(0b00000100);
	LCD_write_char(0b00000000);
	
	//stand cursor Custom Char(Location =1)
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b0001000);
	LCD_write_char(0b00000000);
	
	//Ball Custom Char(Location =2)
	LCD_write_char(0b0000000);
	LCD_write_char(0b0000100);
	LCD_write_char(0b0001010);
	LCD_write_char(0b0010001);
	LCD_write_char(0b0010001);
	LCD_write_char(0b0001010);
	LCD_write_char(0b0000100);
	LCD_write_char(0b00000000);
	
	LCD_MOVE_CURSOR(1,1);
	LCD_write_char(0);
	LCD_MOVE_CURSOR(1,20);
	LCD_write_char(0);
	
	LCD_MOVE_CURSOR(4,1);
	LCD_SEND_STRING("P1: ");
	LCD_MOVE_CURSOR(4,15);
	LCD_SEND_STRING("P2: ");
	
	unsigned char cursorCounter=0;
	unsigned char human1Row = 1;
	unsigned char human2Row = 1;
	unsigned char ballRow = 1;
	u8 swich1 = 1;
	u8 swich2 = 1;
	u8 swich3 = 1;
	u8 swich4 = 1;
	u8 player1Score = 0;
	u8 player2Score = 0;
	
	while(1)
	{
		
		
	for(cursorCounter=2; cursorCounter<20; cursorCounter++)
	{
		
		//Ball Location
		LCD_MOVE_CURSOR(ballRow,cursorCounter);
		LCD_write_char(2);
		_delay_ms(100);
		LCD_MOVE_CURSOR(ballRow,cursorCounter);
		LCD_write_char(' ');
		
		//Human Location
		LCD_MOVE_CURSOR(human1Row,20);
		LCD_write_char(0);
		
		//switch
		swich1 = DIO_ReadPinVal(PC, 0);
		if(swich1 == 0) 
			{
				LCD_MOVE_CURSOR(human1Row,20);
				LCD_write_char(' ');
				human1Row = 1; 
				swich1 = 1;
			}
				
		swich2 = DIO_ReadPinVal(PC, 1);
		if(swich2 == 0) 
			{ DIO_SetPinVal(PD, 1,1);
				LCD_MOVE_CURSOR(human1Row,20);
				LCD_write_char(' ');
				human1Row = 2; 
				swich2 = 1;}
		
		swich3 = DIO_ReadPinVal(PC, 2);
		if(swich3 == 0) 
			{
				 ballRow=1;
				swich3 = 1;
			}
				
		swich4 = DIO_ReadPinVal(PC, 3);
		if(swich4 == 0) 
			{ 
				 ballRow = 2;
				swich4 = 1;
			}
			_delay_ms(100);
		
	}
	if(human1Row == ballRow) { player1Score++; LCD_MOVE_CURSOR(4,4); LCD_write_char((player1Score%10)+48);}
	for(cursorCounter=19; cursorCounter>1; cursorCounter--)
	{
		
		//Ball Location
		LCD_MOVE_CURSOR(ballRow,cursorCounter);
		LCD_write_char(2);
		_delay_ms(100);
		LCD_MOVE_CURSOR(ballRow,cursorCounter);
		LCD_write_char(' ');
		
		//Human Location
		LCD_MOVE_CURSOR(human2Row,1);
		LCD_write_char(0);
		
		//switch
		swich3 = DIO_ReadPinVal(PC, 2);
		if(swich3 == 0) 
			{ 
				LCD_MOVE_CURSOR(human2Row,1);
				LCD_write_char(' ');
				human2Row = 1; 
				swich3 = 1;}
		swich4 = DIO_ReadPinVal(PC, 3);
		if(swich4 == 0) 
			{ 
				LCD_MOVE_CURSOR(human2Row,1);
				LCD_write_char(' ');
				human2Row = 2;
				swich4 = 1;}
		swich1 = DIO_ReadPinVal(PC, 0);
		if(swich1 == 0) 
			{
				 ballRow=1;
				swich1 = 1;
			}
				
		swich2 = DIO_ReadPinVal(PC, 1);
		if(swich2 == 0) 
			{ 
				 ballRow = 2;
				swich2 = 1;
			}
			_delay_ms(100);
	}
	
	if(human2Row == ballRow) { player2Score++; LCD_MOVE_CURSOR(4,18); LCD_write_char((player2Score%10)+48);}
		
}
	}

int main()
{
	DIO_init();
	LCD_INIT();
	_delay_ms(1000);
	game();
	
	/*
	while(1)
	{}
		*/
}
