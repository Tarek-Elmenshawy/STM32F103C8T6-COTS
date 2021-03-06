/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  EXTI_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  EXTI Handler			***********/
/**************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include EXTI driver header files */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit(u8 Copy_u8EXTILine, u8 Copy_u8EXTIMode)
{
	switch(Copy_u8EXTIMode)
	{
		case EXTI_RISING   :
			/* Set EXTIx line in rising edge trigger mode */
			SET_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			CLR_BIT(MEXTI->EXTI_FTSR, Copy_u8EXTILine);
			break;
	
		case EXTI_FALLING  :
			/* Set EXTIx line in falling edge trigger mode */
			SET_BIT(MEXTI->EXTI_FTSR, Copy_u8EXTILine);
			CLR_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			break;
	
		case EXTI_ON_CHANGE:
			/* Set EXTIx line in rising and falling edge trigger mode */
			SET_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			SET_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			break;
	}
}


void MEXTI_voidEnable(u8 Copy_u8EXTILine)
{	
	/* Set the corresponding bit in IMR to enable EXTIx line */
	SET_BIT(MEXTI->EXTI_IMR, Copy_u8EXTILine);
}


void MEXTI_voidDisable(u8 Copy_u8EXTILine)
{
	/* Clear the corresponding bit in IMR to disable EXTIx line */
	CLR_BIT(MEXTI->EXTI_IMR, Copy_u8EXTILine);
}


void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
	/* Set the corresponding bit in IMR to enable EXTIx line */
	SET_BIT(MEXTI->EXTI_SWIER, Copy_u8EXTILine);
}

void MEXTI_voidClearPendingFlag(u8 Copy_u8EXTILine)
{
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, Copy_u8EXTILine);
}


/************************* Function Callback ***************************/
#if EXTI_USE_CALLBACK == EXTI_ENABLE_CALLBACK
static void (*EXTI_Callback[16]) (void);		/* EXTIx callback function pointer  */

void MEXTI_voidSetCallback(u8 Copy_u8EXTILine, void (*Copy_ptrCallback)(void))
{
	/* Set the callback function corresponding to EXTIx line */
	EXTI_Callback[Copy_u8EXTILine] = Copy_ptrCallback;
}

void EXTI0_IRQHandler(void)
{
	/* Callback EXTI0 function handler */
	EXTI_Callback[0]();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 0);
}

void EXTI1_IRQHandler(void)
{
	/* Callback EXTI1 function handler */
	EXTI_Callback[1]();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 1);
}

void EXTI2_IRQHandler(void)
{
	/* Callback EXTI2 function handler */
	EXTI_Callback[2]();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 2);
}

void EXTI3_IRQHandler(void)
{
	/* Callback EXTI3 function handler */
	EXTI_Callback[3]();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 3);
}

void EXTI4_IRQHandler(void)
{
	/* Callback EXTI4 function handler */
	EXTI_Callback[4]();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 4);
}

void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(MEXTI->EXTI_PR, 5) != 0)
	{
		/* Callback EXTI5 function handler */
		EXTI_Callback[5]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 5);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 6) != 0)
	{
		/* Callback EXTI6 function handler */
		EXTI_Callback[6]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 6);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 7) != 0)
	{
		/* Callback EXTI7 function handler */
		EXTI_Callback[7]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 7);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 8) != 0)
	{
		/* Callback EXTI8 function handler */
		EXTI_Callback[8]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 8);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 9) != 0)
	{
		/* Callback EXTI9 function handler */
		EXTI_Callback[9]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 9);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(MEXTI->EXTI_PR, 10) != 0)
	{
		/* Callback EXTI10 function handler */
		EXTI_Callback[10]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 10);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 11) != 0)
	{
		/* Callback EXTI11 function handler */
		EXTI_Callback[11]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 11);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 12) != 0)
	{
		/* Callback EXTI12 function handler */
		EXTI_Callback[12]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 12);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 13) != 0)
	{
		/* Callback EXTI13 function handler */
		EXTI_Callback[13]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 13);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 14) != 0)
	{
		/* Callback EXTI14 function handler */
		EXTI_Callback[14]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 14);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 15) != 0)
	{
		/* Callback EXTI15 function handler */
		EXTI_Callback[15]();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 15);
	}
}

#endif

