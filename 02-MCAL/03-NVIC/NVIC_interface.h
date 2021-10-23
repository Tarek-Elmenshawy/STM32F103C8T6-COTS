/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  NVIC_inteface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  23-10-2021				***********/
/***********	Function :  NVIC Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Function Prototypes */
void MNVIC_voidEnableInterrupt	(u8 Copy_u8InterruptID);
void MNVIC_voidDisableInterrupt	(u8 Copy_u8InterruptID);
void MNVIC_voidSetPendingFlag	(u8 Copy_u8InterruptID);
void MNVIC_voidClearPendingFlag	(u8 Copy_u8InterruptID);
u8	 MNVIC_u8GetActiveFlag		(u8 Copy_u8InterruptID);

#endif	/* NVIC_INTERFACE_H */