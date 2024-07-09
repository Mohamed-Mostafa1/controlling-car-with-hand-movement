/*
 * DIO.h
 *
 * Created: 9/28/2023 6:41:05 PM
 *  Author: mohamed mostafa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../../Libarary/STD_TYPES.h"


#define DIO_Port_INPUT      0b00000000
#define DIO_Port_OUTPUT     0b11111111


#define DIO_Port_LOW		0b00000000
#define DIO_Port_HIGH	    0b11111111


#define DIO_Pin_INPUT  0
#define DIO_Pin_OUTPUT 1
			 
			 
#define DIO_Pin_LOW		0
#define DIO_Pin_HIGH	1

#define DIO_pin0     0
#define DIO_pin1     1
#define DIO_pin2     2
#define DIO_pin3     3
#define DIO_pin4     4
#define DIO_pin5     5
#define DIO_pin6     6
#define DIO_pin7     7

#define DIO_GROUPA	0
#define DIO_GROUPB	1
#define DIO_GROUPC	2
#define DIO_GROUPD	3

u8	DIO_u8SetPinDirection(u8 GroupName,u8 PinNumber,u8 Action);
u8	DIO_u8SetPinValue(u8 GroupName,u8 PinNumber,u8 Action);
u8	DIO_u8GetPinValue(u8 GroupName,u8 PinNumber,u8 *PCopy_var);
u8	DIO_u8SetPortDirection(u8 GroupName,u8 Action);
u8	DIO_u8SetPortValue(u8 GroupName,u8 Action);

#endif /* DIO_H_ */