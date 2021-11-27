/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  TIM_interface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-11-2021				***********/
/***********	Function :  TIM Public Contents		***********/
/**************************************************************/

/**************************************************************/
/*****    Guard of file will call one time in .c file	  *****/
/**************************************************************/

#ifndef TIM_INETFACE_H
#define TIM_INETFACE_H

/**************				Timer 1				***************/
void MTIM1_voidInit					(u16 Copy_u16PSCValue);
void MTIM1_voidSetBusyWait			(u16 Copy_u16Ticks);
void MTIM1_voidSetIntervalSingle	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM1_voidSetIntervalPeriodic	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM1_voidStopInterval			(void);
u16  MTIM1_u16GetElapsedTime		(void);
u16  MTIM1_u16GetRemainingTime		(void);

/**************				Timer 2				***************/
void MTIM2_voidInit					(u16 Copy_u16PSCValue);
void MTIM2_voidSetBusyWait			(u16 Copy_u16Ticks);
void MTIM2_voidSetIntervalSingle	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM2_voidSetIntervalPeriodic	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM2_voidStopInterval			(void);
u16  MTIM2_u16GetElapsedTime		(void);
u16  MTIM2_u16GetCurrentTime		(void);

/**************				Timer 3				***************/
void MTIM3_voidInit					(u16 Copy_u16PSCValue);
void MTIM3_voidSetBusyWait			(u16 Copy_u16Ticks);
void MTIM3_voidSetIntervalSingle	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM3_voidSetIntervalPeriodic	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM3_voidStopInterval			(void);
u16  MTIM3_u16GetElapsedTime		(void);
u16  MTIM3_u16GetCurrentTime		(void);

/**************				Timer 4				***************/
void MTIM4_voidInit					(u16 Copy_u16PSCValue);
void MTIM4_voidSetBusyWait			(u16 Copy_u16Ticks);
void MTIM4_voidSetIntervalSingle	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM4_voidSetIntervalPeriodic	(u16 Copy_u16Ticks, void (* Copy_ptr)(void));
void MTIM4_voidStopInterval			(void);
u16  MTIM4_u16GetElapsedTime		(void);
u16  MTIM4_u16GetCurrentTime		(void);



#endif	/* TIM_INETFACE_H */
