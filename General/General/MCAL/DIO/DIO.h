/*
 * DIO.h
 *
 * Created: 10/17/2023 12:45:59 PM
 *  Author: omnia
 */ 

#include "DIO_config.h"
#include "DIO_reg.h"
#include "../../LIB/std_macros.h"

#ifndef DIO_H_
#define DIO_H_

void DIO_init();
void DIO_SetPinVal(u8 portName, u8 pinNum, u8 val);
void DIO_SetPortVal(u8 portName, u8 val);
u8 DIO_ReadPinVal(u8 portName, u8 pinNum);
u8 DIO_ReadPortVal(u8 portName);
void DIO_TogglePin(u8 portName, u8 pinNum);



#endif /* DIO_H_ */