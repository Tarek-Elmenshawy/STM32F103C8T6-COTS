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
			break;
	
		case EXTI_FALLING  :
			/* Set EXTIx line in falling edge trigger mode */
			SET_BIT(MEXTI->EXTI_FTSR, Copy_u8EXTILine);
			break;
	
		case EXTI_ON_CHANGE:
			/* Set EXTIx line in rising and falling edge trigger mode */
			SET_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			SET_BIT(MEXTI->EXTI_RTSR, Copy_u8EXTILine);
			break;
	}
	
	/* Clear the corresponding bit in IMR to disable EXTIx line */
	//CLR_BIT(MEXTI->EXTI_IMR, Copy_u8EXTILine);
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
void (*EXTI0_Callback) (void);		/* EXTI0 callback function pointer  */
void (*EXTI1_Callback) (void);		/* EXTI1 callback function pointer  */
void (*EXTI2_Callback) (void);		/* EXTI2 callback function pointer  */
void (*EXTI3_Callback) (void);		/* EXTI3 callback function pointer  */
void (*EXTI4_Callback) (void);		/* EXTI4 callback function pointer  */
void (*EXTI5_Callback) (void);		/* EXTI5 callback function pointer  */
void (*EXTI6_Callback) (void);		/* EXTI6 callback function pointer  */
void (*EXTI7_Callback) (void);		/* EXTI7 callback function pointer  */
void (*EXTI8_Callback) (void);		/* EXTI8 callback function pointer  */
void (*EXTI9_Callback) (void);		/* EXTI9 callback function pointer  */
void (*EXTI10_Callback)(void);		/* EXTI10 callback function pointer */
void (*EXTI11_Callback)(void);		/* EXTI11 callback function pointer */
void (*EXTI12_Callback)(void);		/* EXTI12 callback function pointer */
void (*EXTI13_Callback)(void);		/* EXTI13 callback function pointer */
void (*EXTI14_Callback)(void);		/* EXTI14 callback function pointer */
void (*EXTI15_Callback)(void);		/* EXTI15 callback function pointer */

void MEXTI_voidSetCallback(u8 Copy_u8EXTILine, void (*ptrCallback)(void))
{
	/* Set the callback function corresponding to EXTIx line */
	switch(Copy_u8EXTILine)
	{
		case EXTI_LINE0 :	EXTI0_Callback  = ptrCallback;	break;
		case EXTI_LINE1 :	EXTI1_Callback  = ptrCallback;	break;
		case EXTI_LINE2 :	EXTI2_Callback  = ptrCallback;	break;
		case EXTI_LINE3 :	EXTI3_Callback  = ptrCallback;	break;
		case EXTI_LINE4 :	EXTI4_Callback  = ptrCallback;	break;
		case EXTI_LINE5 :	EXTI5_Callback  = ptrCallback;	break;
		case EXTI_LINE6 :	EXTI6_Callback  = ptrCallback;	break;
		case EXTI_LINE7 :	EXTI7_Callback  = ptrCallback;	break;
		case EXTI_LINE8 :	EXTI8_Callback  = ptrCallback;	break;
		case EXTI_LINE9 :	EXTI9_Callback  = ptrCallback;	break;
		case EXTI_LINE10:	EXTI10_Callback = ptrCallback;	break;
		case EXTI_LINE11:	EXTI11_Callback = ptrCallback;	break;
		case EXTI_LINE12:	EXTI12_Callback = ptrCallback;	break;
		case EXTI_LINE13:	EXTI13_Callback = ptrCallback;	break;
		case EXTI_LINE14:	EXTI14_Callback = ptrCallback;	break;
		case EXTI_LINE15:	EXTI15_Callback = ptrCallback;	break;
	}
}

void EXTI0_IRQHandler(void)
{
	/* Callback EXTI0 function handler */
	EXTI0_Callback();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 0);
}

void EXTI1_IRQHandler(void)
{
	/* Callback EXTI1 function handler */
	EXTI1_Callback();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 1);
}

void EXTI2_IRQHandler(void)
{
	/* Callback EXTI2 function handler */
	EXTI2_Callback();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 2);
}

void EXTI3_IRQHandler(void)
{
	/* Callback EXTI3 function handler */
	EXTI3_Callback();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 3);
}

void EXTI4_IRQHandler(void)
{
	/* Callback EXTI4 function handler */
	EXTI4_Callback();
	
	/* Clear pending flag by writing 1 on the corresponding bit*/
	SET_BIT(MEXTI->EXTI_PR, 4);
}

void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(MEXTI->EXTI_PR, 5) != 0)
	{
		/* Callback EXTI5 function handler */
		EXTI5_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 5);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 6) != 0)
	{
		/* Callback EXTI6 function handler */
		EXTI6_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 6);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 7) != 0)
	{
		/* Callback EXTI7 function handler */
		EXTI7_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 7);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 8) != 0)
	{
		/* Callback EXTI8 function handler */
		EXTI8_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 8);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 9) != 0)
	{
		/* Callback EXTI9 function handler */
		EXTI9_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 9);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(MEXTI->EXTI_PR, 10) != 0)
	{
		/* Callback EXTI10 function handler */
		EXTI10_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 10);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 11) != 0)
	{
		/* Callback EXTI11 function handler */
		EXTI11_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 11);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 12) != 0)
	{
		/* Callback EXTI12 function handler */
		EXTI12_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 12);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 13) != 0)
	{
		/* Callback EXTI13 function handler */
		EXTI13_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 13);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 14) != 0)
	{
		/* Callback EXTI14 function handler */
		EXTI14_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 14);
	}
	
	if(GET_BIT(MEXTI->EXTI_PR, 15) != 0)
	{
		/* Callback EXTI15 function handler */
		EXTI15_Callback();

		/* Clear pending flag by writing 1 on the corresponding bit*/
		SET_BIT(MEXTI->EXTI_PR, 15);
	}
}

#endif

