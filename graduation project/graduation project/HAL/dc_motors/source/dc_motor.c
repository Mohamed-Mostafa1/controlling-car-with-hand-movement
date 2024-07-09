/*
 * dc_motor.c
 *
 * Created: 2/21/2024 1:38:14 AM
 *  Author: mohamed mostafa
 */ 



#include "../../../MCAL/DIO/Include/REGESTERS_INTRFACING.h"
#include "../../../MCAL/DIO/Include/DIO.h"
#include "../../../Libarary/clock.h"
#include "../Include/dc_motor.h"
#include "../../../HAL/LCD/Include/CLCD.h"

#include "../../../Libarary/STDMACROS.h"
#include "../../../MCAL/DIO/Include/DIO_ErrorState.h"
#include "../../../Libarary/STD_TYPES.h"


		
		
		void DC_forward()
		{
			CLCD_voidSendCommand(0b00000001);
			DIO_u8SetPinValue(2,3,0);   //IN1
			DIO_u8SetPinValue(2,4,1);   //IN2
			DIO_u8SetPinValue(2,5,0);   //IN3
			DIO_u8SetPinValue(2,6,1);   //IN4
			DIO_u8SetPinValue(1,5,1);   //EN1
			DIO_u8SetPinValue(1,6,1);   //EN2
			CLCS_voidinit();
			
			CLCD_voidSendchar('f');
			CLCD_voidSendchar('o');
			CLCD_voidSendchar('r');
			CLCD_voidSendchar('w');
			CLCD_voidSendchar('a');
			CLCD_voidSendchar('r');
			CLCD_voidSendchar('d');
			
		}
		void DC_left()
		{
			CLCD_voidSendCommand(0b00000001);
			DIO_u8SetPinValue(2,3,0);
			DIO_u8SetPinValue(2,4,1);
			DIO_u8SetPinValue(2,5,0);
			DIO_u8SetPinValue(2,6,0);
			DIO_u8SetPinValue(1,5,1);
			DIO_u8SetPinValue(1,6,0);
			CLCS_voidinit();
			
			CLCD_voidSendchar('l');
			CLCD_voidSendchar('e');
			CLCD_voidSendchar('f');
			CLCD_voidSendchar('t');
			
		}
		void DC_right()
		{
			CLCD_voidSendCommand(0b00000001);
			DIO_u8SetPinValue(2,3,0);
			DIO_u8SetPinValue(2,4,0);
			DIO_u8SetPinValue(2,5,0);
			DIO_u8SetPinValue(2,6,1);
			DIO_u8SetPinValue(1,5,0);
			DIO_u8SetPinValue(1,6,1);
			CLCS_voidinit();
			
			CLCD_voidSendchar('r');
			CLCD_voidSendchar('i');
			CLCD_voidSendchar('g');
			CLCD_voidSendchar('h');
			CLCD_voidSendchar('t');
			
		}
		void DC_stop()
		{
			CLCD_voidSendCommand(0b00000001);
			DIO_u8SetPinValue(2,3,0);
			DIO_u8SetPinValue(2,4,0);
			DIO_u8SetPinValue(2,5,0);
			DIO_u8SetPinValue(2,6,0);
			DIO_u8SetPinValue(1,5,0);
			DIO_u8SetPinValue(1,6,0);
			CLCS_voidinit();
			
			CLCD_voidSendchar('s');
			CLCD_voidSendchar('t');
			CLCD_voidSendchar('o');
			CLCD_voidSendchar('p');

		}
		void DC_backward()
		{
			CLCD_voidSendCommand(0b00000001);
			DIO_u8SetPinValue(2,3,1);
			DIO_u8SetPinValue(2,4,0);
			DIO_u8SetPinValue(2,5,1);
			DIO_u8SetPinValue(2,6,0);
			DIO_u8SetPinValue(1,5,1);
			DIO_u8SetPinValue(1,6,1);
			CLCS_voidinit();
			
			CLCD_voidSendchar('b');
			CLCD_voidSendchar('a');
			CLCD_voidSendchar('c');
			CLCD_voidSendchar('k');
			CLCD_voidSendchar('w');
			CLCD_voidSendchar('a');
			CLCD_voidSendchar('r');
			CLCD_voidSendchar('d');
		}
		