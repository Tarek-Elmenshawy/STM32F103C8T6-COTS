/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  LED_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  19-10-2021				***********/
/***********	Function :  LED Handler				***********/
/**************************************************************/

/* Include Libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of lower layers*/
#include "RCC_interface.h"
#include "GPIO_interface.h"

/* Include LED driver header files*/
#include "LED_interface.h"
#include "LED_config.h"

void LED_voidInitLed(u8 Copy_u8PORT, u8 Copy_u8PIN)
{	
	/* Select PORT */
	switch(Copy_u8PORT)
	{
		case GPIOA:
			/* Enable Clock For GPIOA */
			MRCC_voidEnableClock(RCC_APB2_BUS, RCC_IOPA);
			
			/* Configure PIN as output push-pull*/
			MGPIO_voidSetPinDirection(GPIOA, Copy_u8PIN, GPIO_OUTPUT_10MHZ_PP);
			break;
		
		case GPIOB:
			/* Enable Clock For GPIOB */
			MRCC_voidEnableClock(RCC_APB2_BUS, RCC_IOPB);
			
			/* Configure PIN as output push-pull*/
			MGPIO_voidSetPinDirection(GPIOB, Copy_u8PIN, GPIO_OUTPUT_10MHZ_PP);
			break;
		
		case GPIOC:
			/* Enable Clock For GPIOC */
			MRCC_voidEnableClock(RCC_APB2_BUS, RCC_IOPC);
			
			/* Configure PIN as output push-pull*/
			MGPIO_voidSetPinDirection(GPIOC, Copy_u8PIN, GPIO_OUTPUT_10MHZ_PP);
			break;
	}
}


void LED_voidLedON(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	#if	  LED_CONNECTION_STATUS == LED_ACTIVE_HIGH
		/* Set PIN output HIGH */
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, GPIO_HIGH);
	#elif LED_CONNECTION_STATUS == LED_ACTIVE_LOW
		/* Set PIN output LOW */
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, GPIO_LOW);
	#else
		#error("Wrong LED connection configuration")
	#endif
}


void LED_voidLedOFF(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	#if	  LED_CONNECTION_STATUS == LED_ACTIVE_HIGH
		/* Set PIN output LOW */
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, GPIO_LOW);
	#elif LED_CONNECTION_STATUS == LED_ACTIVE_LOW
		/* Set PIN output HIGH */
		MGPIO_voidSetPinValue(Copy_u8PORT, Copy_u8PIN, GPIO_HIGH);
	#else
		#error("Wrong LED connection configuration")
	#endif
}

void LED_voidLedToggel(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	/* Toggle PIN output */
	MGPIO_voidTogglePinValue(Copy_u8PORT, Copy_u8PIN);
}

