/*
 * CLCD.c
 *
 * Created: 10/1/2023 8:42:44 PM
 *  Author: mohamed mostafa
 */ 


#include "../../../MCAL/DIO/Include/REGESTERS_INTRFACING.h"
#include "../Include/CLCD.h"
#include "../../../MCAL/DIO/Include/DIO.h"
#include "../../../Libarary/clock.h"


void CLCD_voidSendCommand(char cmd)
{
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_RS,DIO_Pin_LOW);
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_RW,DIO_Pin_LOW);
	DIO_PORTA_REG = (DIO_PORTA_REG & 0x0F)|(cmd & 0xF0);
	
	/*Enable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_HIGH);
	
	_delay_ms(2);
	
	/*disable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_LOW);
	DIO_PORTA_REG = (DIO_PORTA_REG & 0x0F)|(cmd <<4 ) ;
	
	/*Enable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_HIGH);
	
	_delay_ms(2);
	
	/*disable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_LOW);
}

void CLCD_voidSendchar(char data)
{
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_RS,DIO_Pin_HIGH);
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_RW,DIO_Pin_LOW);
	DIO_PORTA_REG = (DIO_PORTA_REG & 0x0F)|(data & 0xF0) ;
	
	/*Enable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_HIGH);
	
	_delay_ms(5);
	
	/*disable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_LOW);
	
	DIO_PORTA_REG = (DIO_PORTA_REG & 0x0F)|(data <<4 ) ;
	
	/*Enable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_HIGH);
	
	_delay_ms(5);
	
	/*disable CLCD*/
	DIO_u8SetPinValue(DIO_GROUPB,CLCD_E,DIO_Pin_LOW);
}

void CLCS_voidinit()
{
	DIO_u8SetPinDirection(DIO_GROUPB,CLCD_RS,DIO_Pin_OUTPUT);
	DIO_u8SetPinDirection(DIO_GROUPB,CLCD_RW,DIO_Pin_OUTPUT);
	DIO_u8SetPinDirection(DIO_GROUPB,CLCD_E,DIO_Pin_OUTPUT);
	
	
	DIO_u8SetPinDirection(DIO_GROUPA,DIO_pin4,DIO_Pin_OUTPUT);
	DIO_u8SetPinDirection(DIO_GROUPA,DIO_pin5,DIO_Pin_OUTPUT);
	DIO_u8SetPinDirection(DIO_GROUPA,DIO_pin6,DIO_Pin_OUTPUT);
	DIO_u8SetPinDirection(DIO_GROUPA,DIO_pin7,DIO_Pin_OUTPUT);
	
	
	/*to return home*/
	CLCD_voidSendCommand(Return_Home);

	/*to active right cursor increment*/
	CLCD_voidSendCommand(0b00000110);

	/*display on and cursor off and blinking off*/
	CLCD_voidSendCommand(0b00001100);

	/*4 bit mode -2 line disblay -5*8 dots*/
	CLCD_voidSendCommand(0b00101000);

	/*clear lcd*/
	CLCD_voidSendCommand(0b00000001);
	
	_delay_ms(10);
	
}

void CLCD_voidSendString(char *str)
{
	u8 i=0;
	while (str[i] !='\0' )
	{
		CLCD_voidSendchar(str[i]);
		i++;
	}
	
}


void CLCD_SetDDRAM_ADD(u8 li ,u8 po)
{
	u8 DDRAM_ADDRESS=0;
	if(li ==line0)
	{
		DDRAM_ADDRESS=po;
	}
	else if (li ==line1)
	{
		DDRAM_ADDRESS= po+line1pos;
	}
	else
	{
		;
	}
	CLCD_voidSendCommand(DDRAM_ADDRESS + Pit7code);
}




void CLCD_SetCGRAM_ADD(u8 *ptr,u8 block,u8 li,u8 po)
{
	u8 count=0;
	CLCD_voidSendCommand(block*8+64);
	for (count=0;count<8;count++)
	{
		CLCD_voidSendchar(ptr[count]);
	}
	CLCD_SetDDRAM_ADD(li,po);
	CLCD_voidSendchar(block);
}


void CLCD_voidClearDisplay()
{
	/* to clear LCD */
	CLCD_voidSendCommand(0b00000001);
}