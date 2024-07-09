/*
 * EXTIRegisters.h
 *
 * Created: 10/13/2023 4:10:22 PM
 *  Author: mohamed mostafa
 */ 


#ifndef EXTIREGISTERS_H_
#define EXTIREGISTERS_H_


#define EXTI_MCUCSR (*((volatile u8*) 0x54))
#define EXTI_MCUCR	(*((volatile u8*) 0x55))
#define EXTI_GICR	(*((volatile u8*) 0x5B))

#define EXTI_MCUCSR_ISC2		6

#define EXTI_MCUCR_ISC00		0
#define EXTI_MCUCR_ISC01		1
#define EXTI_MCUCR_ISC10		2
#define EXTI_MCUCR_ISC11		3


#define EXTI_GICR_INT2			5
#define EXTI_GICR_INT0			6
#define EXTI_GICR_INT1			7




#endif /* EXTIREGISTERS_H_ */