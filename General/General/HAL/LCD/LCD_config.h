/*
 * LCD_config.h
 *
 * Created: 10/20/2023 2:34:18 PM
 *  Author: omnia
 */ 
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/std_macros.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define RSPORT PA
#define RSPIN PIN3

#define ENPORT PA
#define ENPIN PIN2

#define LCD_PORT PB

#define LCD_D4 PIN0
#define LCD_D5 PIN1
#define LCD_D6 PIN2
#define LCD_D7 PIN4

//NOTE: set pin directions in DIO_config.h
#endif /* LCD_CONFIG_H_ */