/*
 * GLOI.c
 *
 * Created: 10/13/2023 8:12:33 AM
 *  Author: mohamed mostafa
 */ 



#include "../Include/GLOI.h"
#include "../Include/GLOI_Registers.h"


void GLOI_voidEnableGlobalInt()
{
	__asm("SEI");
	/*
	set_bit(GLOI_SREG,GLOI_SREG_I);
	*/
}


void GLOI_voidDisableGlobalInt()
{
	__asm("CLI");
	/*
	clear_bit(GLOI_SREG,GLOI_SREG_I);
	*/
}
