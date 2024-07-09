/*
 * dio.c
 *
 * Created: 9/28/2023 6:41:26 PM
 *  Author: mohamed mostafa
 */ 




#include "../../../Libarary/STDMACROS.h"
#include "../Include/DIO_ErrorState.h"

#include "../Include/REGESTERS_INTRFACING.h"
#include "../Include/DIO.h"

u8	DIO_u8SetPinDirection(u8 GroupName,u8 PinNumber,u8 Action)
{
	u8 u8_ErrorState = Right ;
	
	if(GroupName<=DIO_GROUPD)
	{
		if(PinNumber<=DIO_pin7)
		{
			if(Action==DIO_Pin_OUTPUT)
			{
				switch(GroupName)
				{
					case DIO_GROUPA: set_bit(DIO_DDRA_REG,PinNumber);  break;
					case DIO_GROUPB: set_bit(DIO_DDRB_REG,PinNumber);  break;
					case DIO_GROUPC: set_bit(DIO_DDRC_REG,PinNumber);  break;
					case DIO_GROUPD: set_bit(DIO_DDRD_REG,PinNumber);  break;
					default:u8_ErrorState=Wrong;                       break;
				}
			}
			else if(Action==DIO_Pin_INPUT)
			{
				switch(GroupName)
				{
					case DIO_GROUPA: clear_bit(DIO_DDRA_REG,PinNumber);  break;
					case DIO_GROUPB: clear_bit(DIO_DDRB_REG,PinNumber);  break;
					case DIO_GROUPC: clear_bit(DIO_DDRC_REG,PinNumber);  break;
					case DIO_GROUPD: clear_bit(DIO_DDRD_REG,PinNumber);  break;
					default:u8_ErrorState=Wrong;                         break;
				}
			}
			else
			{
				u8_ErrorState = Wrong ;
			}
		}
		else
		{
			u8_ErrorState = Wrong ;
		}
	}
	else
	{
		u8_ErrorState = Wrong ;
	}
	
	return u8_ErrorState;
}



u8	DIO_u8SetPinValue(u8 GroupName,u8 PinNumber,u8 Action)
{
	u8 u8_ErrorState = Right ;
	
	if(GroupName<=DIO_GROUPD)
	{
		if(PinNumber<=DIO_pin7)
		{
			if(Action==DIO_Pin_HIGH)
			{
				switch(GroupName)
				{
					case DIO_GROUPA: set_bit(DIO_PORTA_REG,PinNumber);  break;
					case DIO_GROUPB: set_bit(DIO_PORTB_REG,PinNumber);  break;
					case DIO_GROUPC: set_bit(DIO_PORTC_REG,PinNumber);  break;
					case DIO_GROUPD: set_bit(DIO_PORTD_REG,PinNumber);  break;
					default:u8_ErrorState=Wrong;                       break;
				}
			}
			else if(Action==DIO_Pin_LOW)
			{
				switch(GroupName)
				{
					case DIO_GROUPA: clear_bit(DIO_PORTA_REG,PinNumber);  break;
					case DIO_GROUPB: clear_bit(DIO_PORTB_REG,PinNumber);  break;
					case DIO_GROUPC: clear_bit(DIO_PORTC_REG,PinNumber);  break;
					case DIO_GROUPD: clear_bit(DIO_PORTD_REG,PinNumber);  break;
					default:u8_ErrorState=Wrong;                         break;
				}
			}
			else
			{
				u8_ErrorState = Wrong ;
			}
		}
		else
		{
			u8_ErrorState = Wrong ;
		}
	}
	else
	{
		u8_ErrorState = Wrong ;
	}
	
	return u8_ErrorState;

	
}



u8	DIO_u8GetPinValue(u8 GroupName,u8 PinNumber,u8 *PCopy_var)
{
	u8 u8_ErrorState = Right ;
	
	if(GroupName<=DIO_GROUPD)
	{
		if(PinNumber<=DIO_pin7)
		{
			switch(GroupName)
			{
				case DIO_GROUPA: *PCopy_var=read_bit(DIO_PINA_REG,PinNumber);  break;
				case DIO_GROUPB: *PCopy_var=read_bit(DIO_PINB_REG,PinNumber);  break;
				case DIO_GROUPC: *PCopy_var=read_bit(DIO_PINC_REG,PinNumber);  break;
				case DIO_GROUPD: *PCopy_var=read_bit(DIO_PIND_REG,PinNumber);  break;
				default:u8_ErrorState=Wrong;                         break;
			}
		}
		else
		{
			u8_ErrorState = Wrong ;
		}
	}
	else
	{
		u8_ErrorState = Wrong ;
	}
	
	return u8_ErrorState;
}




u8	DIO_u8SetPortDirection(u8 GroupName,u8 Action)
{
	u8 u8_ErrorState = Right ;
	
	if(GroupName<=DIO_GROUPD)
	{
		if(Action == DIO_Port_OUTPUT)
		{
			switch(GroupName)
			{
				case DIO_GROUPA: DIO_DDRA_REG = DIO_Port_OUTPUT;	 break;
				case DIO_GROUPB: DIO_DDRB_REG = DIO_Port_OUTPUT;	 break;
				case DIO_GROUPC: DIO_DDRC_REG = DIO_Port_OUTPUT;	 break;
				case DIO_GROUPD: DIO_DDRD_REG = DIO_Port_OUTPUT;	 break;
				default:u8_ErrorState=Wrong;                         break;
				
			}
		}
		else if(Action == DIO_Port_INPUT)
		{
			switch(GroupName)
			{
				case DIO_GROUPA: DIO_DDRA_REG = DIO_Port_INPUT;		break;
				case DIO_GROUPB: DIO_DDRB_REG = DIO_Port_INPUT;		break;
				case DIO_GROUPC: DIO_DDRC_REG = DIO_Port_INPUT;		break;
				case DIO_GROUPD: DIO_DDRD_REG = DIO_Port_INPUT;		break;
				default:u8_ErrorState=Wrong;                        break;
				
			}
		}
		else
		{
			u8_ErrorState = Wrong ;
		}
		
	}
	else
	{
		u8_ErrorState = Wrong ;
	}
	
	return u8_ErrorState;
}

u8	DIO_u8SetPortValue(u8 GroupName,u8 Action)
{
	u8 u8_ErrorState = Right ;
	
	if(GroupName<=DIO_GROUPD)
	{
		if(Action == DIO_Port_HIGH)
		{
			switch(GroupName)
			{
				case DIO_GROUPA: DIO_DDRA_REG = DIO_Port_HIGH;	 break;
				case DIO_GROUPB: DIO_DDRB_REG = DIO_Port_HIGH;	 break;
				case DIO_GROUPC: DIO_DDRC_REG = DIO_Port_HIGH;	 break;
				case DIO_GROUPD: DIO_DDRD_REG = DIO_Port_HIGH;	 break;
				default:u8_ErrorState=Wrong;                         break;
				
			}
		}
		else if(Action == DIO_Port_LOW)
		{
			switch(GroupName)
			{
				case DIO_GROUPA: DIO_DDRA_REG = DIO_Port_LOW;		break;
				case DIO_GROUPB: DIO_DDRB_REG = DIO_Port_LOW;		break;
				case DIO_GROUPC: DIO_DDRC_REG = DIO_Port_LOW;		break;
				case DIO_GROUPD: DIO_DDRD_REG = DIO_Port_LOW;		break;
				default:u8_ErrorState=Wrong;                        break;
				
			}
		}
		else
		{
			u8_ErrorState = Wrong ;
		}
		
	}
	else
	{
		u8_ErrorState = Wrong ;
	}
	
	return u8_ErrorState;
}

