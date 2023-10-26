/*
 * DIO.c
 *
 * Created: 10/17/2023 12:44:02 PM
 *  Author: omnia
 */ 

#include "DIO_reg.h"
#include "../../LIB/std_macros.h"
#include "DIO_config.h"


void DIO_init()
{
	DDRA = conc_Bits(DDRAPIN7 , DDRAPIN6, DDRAPIN5, DDRAPIN4, DDRAPIN3, DDRAPIN2,DDRAPIN1,DDRAPIN0);
	DDRB = conc_Bits(DDRBPIN7 , DDRBPIN6, DDRBPIN5, DDRBPIN4, DDRBPIN3, DDRBPIN2,DDRBPIN1,DDRBPIN0);
	DDRC = conc_Bits(DDRCPIN7 , DDRCPIN6, DDRCPIN5, DDRCPIN4, DDRCPIN3, DDRCPIN2,DDRCPIN1,DDRCPIN0);
	DDRD = conc_Bits(DDRDPIN7 , DDRDPIN6, DDRDPIN5, DDRDPIN4, DDRDPIN3, DDRDPIN2,DDRDPIN1,DDRDPIN0);
}


void DIO_SetPinVal(u8 portName, u8 pinNum, u8 val)
{
	switch(portName)
	{
		case PA:
				if(val == 1) {SET_BIT(PORTA, pinNum);}
				else         {CLR_BIT(PORTA, pinNum);}	
				break;
		case PB:
				if(val == 1) {SET_BIT(PORTB, pinNum);}
				else         {CLR_BIT(PORTB, pinNum);}	
				break;
		case PC:
				if(val == 1) {SET_BIT(PORTC, pinNum);}
				else         {CLR_BIT(PORTC, pinNum);}	
				break;
		case PD:
				if(val == 1) {SET_BIT(PORTD, pinNum);}
				else         {CLR_BIT(PORTD, pinNum);}	
				break;
		default:
		break;
	}
}


void DIO_SetPortVal(u8 portName, u8 val)
{
	switch(portName)
	{
		case PA:
				PORTA = val;
		case PB:
				PORTB = val;
		case PC:
				PORTC = val;
		case PD:
				PORTD = val;
		default:
		break;
	}
}



u8 DIO_ReadPinVal(u8 portName, u8 pinNum)
{
	u8 returnValue = 0;
	switch(portName)
	{
		case PA:
				returnValue = READ_BIT(PINA, pinNum);
				break;
		case PB:
				returnValue = READ_BIT(PINB, pinNum);
				break;
		case PC:
				returnValue = READ_BIT(PINC, pinNum);
				break;
		case PD:
				returnValue = READ_BIT(PIND, pinNum);
				break;
		default:
		break;
	}
	return returnValue;
}



u8 DIO_ReadPortVal(u8 portName)
{
	u8 returnValue = 0;
	switch(portName)
	{
		case PA:
				returnValue = PINA;
				break;
		case PB:
				returnValue = PINB;
				break;
		case PC:
				returnValue = PINC;
				break;
		case PD:
				returnValue = PIND;
				break;
		default:
		break;
	}
	return returnValue;
}




void DIO_TogglePin(u8 portName, u8 pinNum)
{
	switch(portName)
	{
		case PA:
				TOG_BIT(PORTA, pinNum);	
				break;
		case PB:
				TOG_BIT(PORTB, pinNum);	
				break;
		case PC:
				TOG_BIT(PORTC, pinNum);		
				break;
		case PD:
				TOG_BIT(PORTD, pinNum);	
				break;
		default:
		break;
	}
}
