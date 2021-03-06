/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  STK_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  30-10-2021				***********/
/***********	Function :  STK PHandler			***********/
/**************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include STK driver header files */
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void MSTK_voidInit(void)
{
	#if STK_CLOCK_SOURCE == STCK_AHB_CLOCK
		/*	Set Clock 		: AHB	-> processor clock
		 *	    Enable		: 0		-> counter disable
		 *	    Interrupt	: 0		-> disable interrupt IRQ
		 */
		MSTK->STK_CTRL = 0x00000004;
	#elif STK_CLOCK_SOURCE == STK_AHB_CLOCK_BY_8
		/*	Set Clock		: AHB/8	-> processor clock/8
		 *	    Enable		: 0		-> counter disable
		 *	    Interrupt	: 0		-> disable interrupt IRQ
		 */
		MSTK->STK_CTRL = 0x00000000;
	#else
		#error("Wrong SysTick clock source configuration")
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	MSTK->STK_LOAD = Copy_u32Ticks;								/* Set ticks in SysTick reload value register */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
	CLR_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Clear SysTick interrupt bit */
	SET_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Set SysTick enable bit */
	while(GET_BIT(MSTK->STK_CTRL, STK_COUNT_FLAG_BIT) == 0);	/* Wait flag polling */
	CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Clear SysTick enable bit */
	MSTK->STK_LOAD = 0;											/* Clear SysTick reload value register */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Clear SysTick enable bit */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
	MSTK->STK_LOAD = Copy_u32Ticks;								/* Set ticks in SysTick reload value register */
	SET_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Set SysTick interrupt bit */
	MSTK_Callback = Copy_ptr;									/* Set SysTick callback function pointer */
	STK_u8IntervalState = STK_SINGLE_INTERVAL;					/* Set interval state as single */
	SET_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Set SysTick enable bit */
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (* Copy_ptr)(void))
{
	CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Clear SysTick enable bit */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
	MSTK->STK_LOAD = Copy_u32Ticks;								/* Set ticks in SysTick reload value register */
	SET_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Set SysTick interrupt bit */
	MSTK_Callback = Copy_ptr;									/* Set SysTick callback function pointer */
	STK_u8IntervalState = STK_PERIODIC_INTERVAL;				/* Set interval state as periodic */
	SET_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Set SysTick enable bit */
}

void MSTC_voidStopInterval(void)
{
	CLR_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Clear SysTick interrupt bit */
	CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Clear SysTick enable bit */
	MSTK->STK_LOAD = 0;											/* Clear SysTick reload value register */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = MSTK->STK_LOAD - MSTK->STK_VAL;		/* Calculate elapsed time by [start_ticks - current_ticks] */
	return Local_u32ElapsedTime;								/* Return elapsed time */
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime;
	Local_u32RemainingTime = MSTK->STK_VAL;						/* Load current ticks */
	return Local_u32RemainingTime;								/* Return remaining time */
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if(STK_u8IntervalState == STK_SINGLE_INTERVAL)
	{
		CLR_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);				/* Clear SysTick interrupt bit */
		CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);				/* Clear SysTick enable bit */
		MSTK->STK_LOAD = 0;										/* Clear SysTick reload value register */
		MSTK->STK_VAL  = 0;										/* Clear SysTick current value register */
	}
	
	MSTK_Callback();											/* Callback sysTick function handler */
	Local_u8Temporary = GET_BIT(MSTK->STK_CTRL, 16);			/* Clear pending interrupt flag */
}
