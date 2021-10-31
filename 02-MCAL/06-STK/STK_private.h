/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  STK_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  30-10-2021				***********/
/***********	Function :  STK Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_ENABLE_BIT			0						/* Counter Enable bit in CTRL Register	*/
#define STK_TICK_INT_BIT		1						/* Tick Interrupt bit in CTRL Register	*/
#define STK_CLK_SOURCE_BIT		2						/* Clock Source bit in CTRL Register	*/
#define STK_COUNT_FLAG_BIT		16						/* Counter Flag bit in CTRL Register	*/

typedef struct{
	
	volatile u32 STK_CTRL;								/* SysTick Control and Status Register	*/
	volatile u32 STK_LOAD;								/* SysTick Reload Value  Register		*/
	volatile u32 STK_VAL;								/* SysTick Current Value  Register		*/
	volatile u32 STK_CALIB;								/* SysTick Calibration Value  Register	*/
	
}STK_TypeDef;

#define MSTK	((volatile STK_TypeDef *)0xE000E010)	/* Base address of SysTick				*/

#define STK_AHB_CLOCK			1
#define STK_AHB_CLOCK_BY_8		2

#define STK_SINGLE_INTERVAL		1
#define STK_PERIODIC_INTERVAL	2

#endif /* STK_PRIVATE_H */
