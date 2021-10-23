/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  NVIC_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  23-10-2021				***********/
/***********	Function :  NVIC Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct{
	
	volatile u32 NVIC_ISER[32];						/* Interrupt Set Enable Registers 					*/
	volatile u32 NVIC_ICER[32];						/* Interrupt Clear Enable Registers 				*/
	volatile u32 NVIC_ISPR[32];						/* Interrupt Set Pending Registers 					*/
	volatile u32 NVIC_ICPR[32];						/* Interrupt Clear Pending Registers				*/
	volatile u32 NVIC_IABR[32];						/* Interrupt Active Bit Registers 					*/
	volatile u32 RESERVED [32];
	volatile u8  NVIC_IPR[128];						/* Interrupt Priority Registers 					*/
	
}NVIC;

#define MNVIC		((volatile NVIC *)0xE000E100)	/* Base Address of NVIC				 				*/
#define MNVIC_STIR 	((volatile u32  *)0xE000EF00)	/* Address of Software trigger Interrupt Register	*/

#endif	/* NVIC_PRIVATE_H */