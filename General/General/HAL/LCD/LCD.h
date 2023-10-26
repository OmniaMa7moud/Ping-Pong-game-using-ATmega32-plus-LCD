/*
 * LCD.h
 *
 * Created: 10/20/2023 3:43:59 PM
 *  Author: omnia
 */ 


#include "LCD_config.h"
#include "LCD_pri.h"

#ifndef LCD_H_
#define LCD_H_

void LCD_INIT();
void LCD_EN();
void LCD_instruction(unsigned char cmd);
void LCD_write_char(unsigned char data);
void LCD_SEND_STRING(char *data);
void LCD_MOVE_CURSOR(unsigned char row , unsigned char column);
void LCD_CLR_SCREEN(void);




#endif /* LCD_H_ */