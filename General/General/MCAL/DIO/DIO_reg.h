/*
 * DIO_reg.h
 *
 * Created: 10/17/2023 1:11:22 PM
 *  Author: omnia
 */ 


#include "../../LIB/std_macros.h"

#ifndef DIO_REG_H_
#define DIO_REG_H_

//////portA//////////
#define PORTA *((volatile u8*) 0x3B)
#define DDRA *((volatile u8*) 0x3A)
#define PINA *((volatile u8*) 0x39)


//////portB//////////
#define PORTB *((volatile u8*) 0x38)
#define DDRB *((volatile u8*) 0x37)
#define PINB *((volatile u8*) 0x36)



//////portc//////////
#define PORTC *((volatile u8*) 0x35)
#define DDRC *((volatile u8*) 0x34)
#define PINC *((volatile u8*) 0x33)




//////portD//////////
#define PORTD *((volatile u8*) 0x32)
#define DDRD *((volatile u8*) 0x31)
#define PIND *((volatile u8*) 0x30)






#endif /* DIO_REG_H_ */