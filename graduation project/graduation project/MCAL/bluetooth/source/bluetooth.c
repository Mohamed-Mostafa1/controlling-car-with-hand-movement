
/*
 * bluetooth.c
 *
 * Created: 2/17/2024 3:12:37 PM
 *  Author: mohamed mostafa
 */ 


 
 /* UTILES_LIB */


 #include "../../../MCAL/DIO/Include/REGESTERS_INTRFACING.h"
 #include "../Include/bluetooth.h"
 #include "../../../MCAL/DIO/Include/DIO.h"
 #include "../../../Libarary/clock.h"
#include "../../../Libarary/BIT_MATH.h"





 void UART_voidInit(void)
 {
	 // Set Buad Rate = 9600
	 CLR_BIT(UCSRA,U2X);
	 UBRRL = 103;
	 
	 // writing the UCSRC
	 // select UART MODE = Asynchronous
	 // configure no parity
	 // configure stop bits = 1
	 // configure data bits = 8
	 // configure no polarity
	 UCSRC = 0X86; //0b10000110;
	 CLR_BIT(UCSRB,UCSZ2);
	 
	 //Enable Tx
	 SET_BIT(UCSRB,TXEN);
	 
	 //Enable Rx
	 SET_BIT(UCSRB,RXEN);
 }


 void UART_voidTxChar(u8 copy_u8TxData)
 {
	 UDR = copy_u8TxData;
	 
	 // Busy Wait on Data Register empty flag
	 while(0 == GET_BIT(UCSRA,UDRE));
 }


 u8 UART_u8RxChar(u8* copy_pu8RxData)
 {
	 u8 Local_u8ErrorState = PASS;
	 if(copy_pu8RxData!=NULL)
	 {
		 // Busy Wait on Receive Complete flag
		 while(0 == GET_BIT(UCSRA,RXC));
		 
		 *copy_pu8RxData = UDR;
	 }
	 else
	 {
		 Local_u8ErrorState = FAIL;
	 }
	 return Local_u8ErrorState;
 }


 void UART_voidTxString(u8* copy_pu8TxString)
 {
	 u8 Local_u8Counter=0;
	 while(copy_pu8TxString[Local_u8Counter]!='\0')
	 {
		 UART_voidTxChar(copy_pu8TxString[Local_u8Counter]);
		 Local_u8Counter++;
	 }
 }


 void UART_voidRxString(u8* copy_pu8RxString);