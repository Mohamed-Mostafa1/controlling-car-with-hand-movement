/*
 * APP.c
 *
 * Created: 10/13/2023 4:05:04 PM
 *  Author: mohamed mostafa
 */ 



#include "../../MCAL/EXTI/Include/EXTI.h"
#include "../Include/APP.h"
#include "../../MCAL/DIO/Include/DIO.h"
#include "../../Libarary/clock.h"
#include "../../MCAL/bluetooth/Include/bluetooth.h"
#include "../../HAL/dc_motors/Include/dc_motor.h"

void APP()
{
	u8 data;
	CLCS_voidinit();

	UART_voidInit();
	
	 while (1)
	 
	 {
		 UART_u8RxChar(&data);
		 switch(data)
		 {
			 case '1' :
			 {
				 DC_forward();
				 break;
			 }
			 
			  case '2' :
			  {
				  DC_backward();
				  break;
			  }
			  
			   case '3' :
			   {
				   DC_right();
				   break;
			   }
			   
			    case '4' :
			    {
				    DC_left();
				    break;
			    }
				
				 case '5' :
				 {
					 DC_stop();
					 break;
				 }
			 
		 }
	 }
	
}
