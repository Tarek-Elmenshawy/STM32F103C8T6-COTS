/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  EXTI_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  EXTI Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	
	volatile u32 EXTI_IMR;		/* Interrupt Mask Register 				*/
	volatile u32 EXTI_EMR;		/* Event Mask Register 					*/
	volatile u32 EXTI_RTSR;		/* Rising Trigger Select Register 		*/
	volatile u32 EXTI_FTSR;		/* Falling Trigger Select Register 		*/
	volatile u32 EXTI_SWIER;	/* Software Interrupt Event Register	*/
	volatile u32 EXTI_PR; 		/* Pending Register						*/
	
}EXTI_TypeDef;

#define MEXTI ((volatile EXTI_TypeDef *)0x40010400)

#define EXTI_DISABLE_CALLBACK 	0
#define EXTI_ENABLE_CALLBACK	1


#endif	/* EXTI_PRIVATE_H */
