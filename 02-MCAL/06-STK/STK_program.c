/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  STK_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  30-10-2021				***********/
/***********	Function :  STK PHandler			***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
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
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (* Copy_ptr)(void))
{
	MSTK->STK_LOAD = Copy_u32Ticks;								/* Set ticks in SysTick reload value register */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
	SET_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Set SysTick interrupt bit */
	MSTK_Callback = Copy_ptr;									/* Set SysTick callback function pointer */
	STK_u8IntervalState = STK_SINGLE_INTERVAL;					/* Set interval state as single */
	SET_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Set SysTick enable bit */
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (* Copy_ptr)(void))
{
	MSTK->STK_LOAD = Copy_u32Ticks;								/* Set ticks in SysTick reload value register */
	MSTK->STK_VAL  = 0;											/* Clear SysTick current value register */
	SET_BIT(MSTK->STK_CTRL, STK_TICK_INT_BIT);					/* Set SysTick interrupt bit */
	MSTK_Callback = Copy_ptr;									/* Set SysTick callback function pointer */
	STK_u8IntervalState = STK_PERIODIC_INTERVAL;				/* Set interval state as periodic */
	SET_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Set SysTick enable bit */
}

void MSTC_voidStopInterval(void)
{
	CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);					/* Clear SysTick enable bit */
}

u32  MSTK_u32GetElapsedTime(void)
{
	return (MSTK->STK_LOAD - MSTK->STK_VAL);					/* Return elapsed time calculated by [start_ticks - current_ticks] */
}

u32  MSTK_u32GetRemainingTime(void)
{
	return MSTK->STK_VAL;										/* Return current ticks */
}


void SysTick_Handler(void)
{
	MSTK_Callback();											/* Callback sysTick function handler */
	if(STK_u8IntervalState == STK_SINGLE_INTERVAL)
	{
		CLR_BIT(MSTK->STK_CTRL, STK_ENABLE_BIT);				/* Clear SysTick enable bit */
	}
}
