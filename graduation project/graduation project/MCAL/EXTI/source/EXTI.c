/*
 * EXTI.c
 *
 * Created: 10/13/2023 4:11:23 PM
 *  Author: mohamed mostafa
 */ 


#include "../../../Libarary/STDMACROS.h"
#include "../Include/EXTI.h"
#include "../Include/EXTIRegisters.h"

void (*INT0_ptr)(void);
void (*INT1_ptr)(void);
void (*INT2_ptr)(void);



void EXTI_voidSetCallBack(u8 INT_Number, void (*Copy_Func_Address)(void))
{
	switch(INT_Number)
	{
		case EXTI_INT0: INT0_ptr=Copy_Func_Address;
		break;
		
		case EXTI_INT1: INT1_ptr=Copy_Func_Address;
		break;
		
		case EXTI_INT2: INT2_ptr=Copy_Func_Address;
		break;
	}
}




void EXTI_voidEnableInterrupt(u8 INT_Number)
{
	switch(INT_Number)
	{
		case EXTI_INT0: set_bit(EXTI_GICR,EXTI_GICR_INT0);
		break;
		
		case EXTI_INT1:	set_bit(EXTI_GICR,EXTI_GICR_INT1);
		break;
		
		case EXTI_INT2:	set_bit(EXTI_GICR,EXTI_GICR_INT2);
		break;
	}
}


void EXTI_voidDisableInterrupt(u8 INT_Number)
{
	switch(INT_Number)
	{
		case EXTI_INT0: clear_bit(EXTI_GICR,EXTI_GICR_INT0);
		break;
		
		case EXTI_INT1:	clear_bit(EXTI_GICR,EXTI_GICR_INT1);
		break;
		
		case EXTI_INT2:	clear_bit(EXTI_GICR,EXTI_GICR_INT2);
		break;
	}
}

void EXTI_voidSenseControl(u8 INT_Number,u8 change)
{
	switch(INT_Number)
	{
		case EXTI_INT0:
		switch(change)
		{
			case LOW_LEVEL:
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
			break;
			case ANY_LOGICAL_CHANGE:
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
			break;
			case FALLING_EDGE:
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
			break;
			case RISING_EDGE:
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC00);
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC01);
			break;
		}
		break;
		
		case EXTI_INT1:
		switch(change)
		{
			case LOW_LEVEL:
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
			break;
			case ANY_LOGICAL_CHANGE:
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
			break;
			case FALLING_EDGE:
			clear_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
			break;
			case RISING_EDGE:
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC10);
			set_bit(EXTI_MCUCR,EXTI_MCUCR_ISC11);
			break;
		}
		break;
		
		case EXTI_INT2:
		switch(change)
		{
			case FALLING_EDGE:
			clear_bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
			break;
			
			case RISING_EDGE:
			set_bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
			break;
		}
		break;
	}
}


/*ISR of INT0 */
void __vector_1 (void) __attribute__((signal));

void __vector_1 (void)
{
	/*ISR of INT0 body*/
	INT0_ptr();
}


/*ISR of INT1 */
void __vector_2 (void) __attribute__((signal));

void __vector_2 (void)
{
	/*ISR of INT1 body*/
	INT1_ptr();
}


/*ISR of INT2 */
void __vector_3 (void) __attribute__((signal));

void __vector_3 (void)
{
	/*ISR of INT2 body*/
	INT2_ptr();
}