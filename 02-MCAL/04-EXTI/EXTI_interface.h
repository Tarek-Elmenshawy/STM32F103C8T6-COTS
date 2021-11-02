/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  EXTI_inteface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  EXTI Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_LINE0		0		/* EXTI Line 0  			*/
#define EXTI_LINE1		1		/* EXTI Line 1  			*/
#define EXTI_LINE2		2		/* EXTI Line 2  			*/
#define EXTI_LINE3		3		/* EXTI Line 3  			*/
#define EXTI_LINE4		4		/* EXTI Line 4  			*/
#define EXTI_LINE5		5		/* EXTI Line 5  			*/
#define EXTI_LINE6		6		/* EXTI Line 6  			*/
#define EXTI_LINE7		7		/* EXTI Line 7  			*/
#define EXTI_LINE8		8		/* EXTI Line 8  			*/
#define EXTI_LINE9		9		/* EXTI Line 9  			*/
#define EXTI_LINE10		10		/* EXTI Line 10 			*/
#define EXTI_LINE11		11		/* EXTI Line 11 			*/
#define EXTI_LINE12		12		/* EXTI Line 12 			*/
#define EXTI_LINE13		13		/* EXTI Line 13 			*/
#define EXTI_LINE14		14		/* EXTI Line 14 			*/
#define EXTI_LINE15		15		/* EXTI Line 15 			*/

#define EXTI_RISING  	0		/* EXTI Rising Edge Mode 	*/
#define EXTI_FALLING 	1		/* EXTI Falling Edge Mode 	*/
#define EXTI_ON_CHANGE  2		/* EXTI On Change Edge Mode	*/


/* Function Prototypes */
void MEXTI_voidInit				(u8 Copy_u8EXTILine, u8 Copy_u8EXTIMode);
void MEXTI_voidEnable			(u8 Copy_u8EXTILine);
void MEXTI_voidDisable			(u8 Copy_u8EXTILine);
void MEXTI_voidSoftwareTrigger	(u8 Copy_u8EXTILine);
void MEXTI_voidClearPendingFlag (u8 Copy_u8EXTILine);
void MEXTI_voidSetCallback		(u8 Copy_u8EXTILine, void (*Copy_ptrCallback)(void));


#endif	/* EXTI_INTERFACE_H */
