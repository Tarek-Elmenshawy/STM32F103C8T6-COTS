/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  STK_interface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  30-10-2021				***********/
/***********	Function :  STK Public Contents		***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#define STK_COUNT_EN 		1
#define STK_COUNT_DIS		0

#define STK_INTERRUPT_EN	1
#define STK_INTERRUPT_DIS	1

/* Function prototypes */
void MSTK_voidInit				 (void);
void MSTK_voidSetBusyWait		 (u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle	 (u32 Copy_u32Ticks, void (* Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (* Copy_ptr)(void));
void MSTC_voidStopInterval		 (void);
u32	 MSTK_u32GetElapsedTime		 (void);
u32  MSTK_u32GetRemainingTime	 (void);

#endif /* STK_INTERFACE_H */
