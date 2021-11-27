/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  TIM_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-11-2021				***********/
/***********	Function :  TIM Handler				***********/
/**************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include TIM driver header files */
#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Timer 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MTIM1_voidInit(u16 Copy_u16PSCValue)
{
	MTIM1->TIM_SR  = 0;									/* Reset status register */
	MTIM1->TIM_PSC = Copy_u16PSCValue - 1;				/* Set prescaler value [CLK_CNT = CLK_PSC / (PSC + 1)]*/
}

void MTIM1_voidSetBusyWait(u16 Copy_u16Ticks)
{
	CLR_BIT(MTIM1->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM1->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	CLR_BIT(MTIM1->TIM_DIER, TIM_DIER_UIE);				/* Disable update event interrupt */
	SET_BIT(MTIM1->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
	while(GET_BIT(MTIM1->TIM_SR, TIM_SR_UIF) == 0);		/* Loop until the update event flag is set */
	CLR_BIT(MTIM1->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

void MTIM1_voidSetIntervalSingle(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM1->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM1->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM1->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[1] = Copy_ptr;							/* Set timer1 callback function pointer */
	SET_BIT(MTIM1->TIM_CR1, TIM_CR1_OPM);				/* Set once pulse mode */
	SET_BIT(MTIM1->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM1_voidSetIntervalPeriodic(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM1->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM1->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM1->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[1] = Copy_ptr;							/* Set timer1 callback function pointer */
	SET_BIT(MTIM1->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM1_voidStopInterval(void)
{
	CLR_BIT(MTIM1->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

u16  MTIM1_u16GetElapsedTime(void)
{
	u16 Local_u16ElapsedTime;
	Local_u16ElapsedTime = MTIM1->TIM_CNT;				/* Load current ticks */
	return Local_u16ElapsedTime;						/* Return elapsed time */
}

u16  MTIM1_u16GetRemainingTime(void)
{
	u16 Local_u16RemainingTime;
	Local_u16RemainingTime = MTIM1->TIM_ARR - MTIM1->TIM_CNT;	/* Calculate remaining time */
	return Local_u16RemainingTime;						/* Return elapsed time */
}

void TIM1_UP_IRQHandler(void)
{
	TIM_Callback[1]();									/* Call timer 1 function handler */
	CLR_BIT(MTIM1->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// End Timer 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Timer 2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MTIM2_voidInit(u16 Copy_u16PSCValue)
{
	MTIM2->TIM_SR  = 0;									/* Reset status register */
	MTIM2->TIM_PSC = Copy_u16PSCValue - 1;				/* Set prescaler value [CLK_CNT = CLK_PSC / (PSC + 1)]*/
}

void MTIM2_voidSetBusyWait(u16 Copy_u16Ticks)
{
	CLR_BIT(MTIM2->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM2->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	CLR_BIT(MTIM2->TIM_DIER, TIM_DIER_UIE);				/* Disable update event interrupt */
	SET_BIT(MTIM2->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
	while(GET_BIT(MTIM2->TIM_SR, TIM_SR_UIF) == 0);		/* Loop until the update event flag is set */
	CLR_BIT(MTIM2->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

void MTIM2_voidSetIntervalSingle(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM2->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM2->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM2->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[2] = Copy_ptr;							/* Set timer2 callback function pointer */
	SET_BIT(MTIM2->TIM_CR1, TIM_CR1_OPM);				/* Set once pulse mode */
	SET_BIT(MTIM2->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM2_voidSetIntervalPeriodic(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM2->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM2->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM2->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[2] = Copy_ptr;							/* Set timer2 callback function pointer */
	SET_BIT(MTIM2->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM2_voidStopInterval(void)
{
	CLR_BIT(MTIM2->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

u16  MTIM2_u16GetElapsedTime(void)
{
	u16 Local_u16ElapsedTime;
	Local_u16ElapsedTime = MTIM2->TIM_CNT;				/* Load current ticks */
	return Local_u16ElapsedTime;						/* Return elapsed time */
}

u16  MTIM2_u16GetRemainingTime(void)
{
	u16 Local_u16RemainingTime;
	Local_u16RemainingTime = MTIM2->TIM_ARR - MTIM2->TIM_CNT;	/* Calculate remaining time */
	return Local_u16RemainingTime;						/* Return elapsed time */
}

void TIM2_IRQHandler(void)
{
	TIM_Callback[2]();									/* Call timer 2 function handler */
	CLR_BIT(MTIM2->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// End Timer 2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Timer 3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MTIM3_voidInit(u16 Copy_u16PSCValue)
{
	MTIM3->TIM_SR  = 0;									/* Reset status register */
	MTIM3->TIM_PSC = Copy_u16PSCValue - 1;				/* Set prescaler value [CLK_CNT = CLK_PSC / (PSC + 1)]*/
}

void MTIM3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	CLR_BIT(MTIM3->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM3->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	CLR_BIT(MTIM3->TIM_DIER, TIM_DIER_UIE);				/* Disable update event interrupt */
	SET_BIT(MTIM3->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
	while(GET_BIT(MTIM3->TIM_SR, TIM_SR_UIF) == 0);		/* Loop until the update event flag is set */
	CLR_BIT(MTIM3->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

void MTIM3_voidSetIntervalSingle(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM3->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM3->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM3->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[3] = Copy_ptr;							/* Set timer3 callback function pointer */
	SET_BIT(MTIM3->TIM_CR1, TIM_CR1_OPM);				/* Set once pulse mode */
	SET_BIT(MTIM3->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM3_voidSetIntervalPeriodic(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM3->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM3->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM3->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[3] = Copy_ptr;							/* Set timer3 callback function pointer */
	SET_BIT(MTIM3->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM3_voidStopInterval(void)
{
	CLR_BIT(MTIM3->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

u16  MTIM3_u16GetElapsedTime(void)
{
	u16 Local_u16ElapsedTime;
	Local_u16ElapsedTime = MTIM3->TIM_CNT;				/* Load current ticks */
	return Local_u16ElapsedTime;						/* Return elapsed time */
}

u16  MTIM3_u16GetRemainingTime(void)
{
	u16 Local_u16RemainingTime;
	Local_u16RemainingTime = MTIM3->TIM_ARR - MTIM3->TIM_CNT;	/* Calculate remaining time */
	return Local_u16RemainingTime;						/* Return elapsed time */
}

void TIM3_IRQHandler(void)
{
	TIM_Callback[3]();									/* Call timer 3 function handler */
	CLR_BIT(MTIM3->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// End Timer 3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Timer 4
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MTIM4_voidInit(u16 Copy_u16PSCValue)
{
	MTIM4->TIM_SR  = 0;									/* Reset status register */
	MTIM4->TIM_PSC = Copy_u16PSCValue - 1;				/* Set prescaler value [CLK_CNT = CLK_PSC / (PSC + 1)]*/
}

void MTIM4_voidSetBusyWait(u16 Copy_u16Ticks)
{
	CLR_BIT(MTIM4->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM4->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	CLR_BIT(MTIM4->TIM_DIER, TIM_DIER_UIE);				/* Disable update event interrupt */
	SET_BIT(MTIM4->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
	while(GET_BIT(MTIM4->TIM_SR, TIM_SR_UIF) == 0);		/* Loop until the update event flag is set */
	CLR_BIT(MTIM4->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

void MTIM4_voidSetIntervalSingle(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM4->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM4->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM4->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[4] = Copy_ptr;							/* Set timer4 callback function pointer */
	SET_BIT(MTIM4->TIM_CR1, TIM_CR1_OPM);				/* Set once pulse mode */
	SET_BIT(MTIM4->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM4_voidSetIntervalPeriodic(u16 Copy_u16Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MTIM4->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
	MTIM4->TIM_ARR = Copy_u16Ticks - 1;					/* Set auro-reload register value */
	SET_BIT(MTIM4->TIM_DIER, TIM_DIER_UIE);				/* Enable update event interrupt */
	TIM_Callback[4] = Copy_ptr;							/* Set timer4 callback function pointer */
	SET_BIT(MTIM4->TIM_CR1, TIM_CR1_CEN);				/* Enable timer counter */
}

void MTIM4_voidStopInterval(void)
{
	CLR_BIT(MTIM4->TIM_CR1, TIM_CR1_CEN);				/* Disable timer counter */
}

u16  MTIM4_u16GetElapsedTime(void)
{
	u16 Local_u16ElapsedTime;
	Local_u16ElapsedTime = MTIM4->TIM_CNT;				/* Load current ticks */
	return Local_u16ElapsedTime;						/* Return elapsed time */
}

u16  MTIM4_u16GetRemainingTime(void)
{
	u16 Local_u16RemainingTime;
	Local_u16RemainingTime = MTIM4->TIM_ARR - MTIM4->TIM_CNT;	/* Calculate remaining time */
	return Local_u16RemainingTime;						/* Return elapsed time */
}

void TIM4_IRQHandler(void)
{
	TIM_Callback[4]();									/* Call timer 4 function handler */
	CLR_BIT(MTIM4->TIM_SR, TIM_SR_UIF);					/* Clear the update event flag */
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// End Timer 4
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
