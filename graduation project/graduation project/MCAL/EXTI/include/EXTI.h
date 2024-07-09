/*
 * EXTI.h
 *
 * Created: 10/13/2023 4:09:48 PM
 *  Author: mohamed mostafa
 */ 


#ifndef EXTI_H_
#define EXTI_H_


#include "../../../Libarary/STD_TYPES.h"

void EXTI_voidEnableInterrupt(u8 INT_Number);
void EXTI_voidDisableInterrupt(u8 INT_Number);
void EXTI_voidSenseControl(u8 INT_Number,u8 change);
void EXTI_voidSetCallBack(u8 INT_Number, void (*Copy_Func_Address)(void));



#define  EXTI_INT0			0
#define  EXTI_INT1			1
#define  EXTI_INT2			2

#define LOW_LEVEL			0
#define ANY_LOGICAL_CHANGE	1
#define FALLING_EDGE        2
#define RISING_EDGE			3




#endif /* EXTI_H_ */