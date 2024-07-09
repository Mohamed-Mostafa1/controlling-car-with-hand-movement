/*
 * CLCD.h
 *
 * Created: 10/1/2023 8:42:58 PM
 *  Author: mohamed mostafa
 */ 

#include "../../../Libarary/STD_TYPES.h"

#ifndef CLCD_H_
#define CLCD_H_

#define line0pos  0
#define line1pos  64

#define line0     0
#define line1     1

#define Pit7code  128

#define Char0  0
#define Char1  1
#define Char2  2
#define Char3  3
#define Char4  4
#define Char5  5
#define Char6  6
#define Char7  7
#define Char8  8
#define Char9  9
#define Char10 10
#define Char11 11
#define Char12 12
#define Char13 13
#define Char14 14
#define Char15 15






#define CLCD_RS   1
#define CLCD_RW   2
#define CLCD_E    3

#define Return_Home 0b00000010


void CLCD_voidSendCommand(char cmd);
void CLCD_voidSendchar(char data);
void CLCS_voidinit();
void CLCD_SetDDRAM_ADD(u8 li ,u8 po);
void CLCD_SetCGRAM_ADD(u8 *ptr,u8 block,u8 li,u8 po);

void CLCD_voidSendString(char *str);


#endif /* CLCD_H_ */