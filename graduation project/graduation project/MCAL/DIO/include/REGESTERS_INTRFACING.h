/*
 * REGESTERS_INTRFACING.h
 *
 * Created: 9/28/2023 6:53:29 PM
 *  Author: mohamed mostafa
 */ 


#ifndef REGESTERS_INTRFACING_H_
#define REGESTERS_INTRFACING_H_

#define	DIO_PORTA_REG	(*((volatile u8*)0x3B))
#define	DIO_DDRA_REG	(*((volatile u8*)0x3A))
#define	DIO_PINA_REG	(*((volatile u8*)0x39))

#define	DIO_PORTB_REG	(*((volatile u8*)0x38))
#define	DIO_DDRB_REG	(*((volatile u8*)0x37))
#define	DIO_PINB_REG	(*((volatile u8*)0x36))

#define	DIO_PORTC_REG	(*((volatile u8*)0x35))
#define	DIO_DDRC_REG	(*((volatile u8*)0x34))
#define	DIO_PINC_REG	(*((volatile u8*)0x33))

#define	DIO_PORTD_REG	(*((volatile u8*)0x32))
#define	DIO_DDRD_REG	(*((volatile u8*)0x31))
#define	DIO_PIND_REG	(*((volatile u8*)0x30))

#endif /* REGESTERS_INTRFACING_H_ */