/*
 * LCD_pri.h
 *
 * Created: 10/20/2023 3:41:57 PM
 *  Author: omnia
 */ 


#ifndef LCD_PRI_H_
#define LCD_PRI_H_
//LCD Instructions
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02

//intiallized once
#define CURSOR_MOVE_RIGHT 0x06
#define CURSOR_MOVE_LEFT 0x04
#define DISPLAY_SHIFT_LEFT 0x07
#define DISPLAY_SHIFT_RIGHT 0x05

#define DISPLAY_ON_CURSOR_ON 0x0e 
#define DISPLAY_ON_CURSOR_OFF 0x0c  
#define DISPLAY_ON_CURSOR_BLINK 0x0f  
#define DISPLAY_OFF_CURSOR_OFF 0x08  
#define DISPLAY_OFF_CURSOR_ON 0x0a


#define SHIFT_CURSOR_POSITION_LEFT 0x10
#define SHIFT_CURSOR_POSITION_RIGHT 0x14
#define SHIFT_ENTIRE_DISPLAY_LEFT 0x18
#define SHIFT_ENTIRE_DISPLAY_RIGHT 0x1c

//Function Set(2 Lines and small font always)
#define FOUR_BIT_MODE 0x28
#define EIGHT_BIT_MODE 0x38



#endif /* LCD_PRI_H_ */