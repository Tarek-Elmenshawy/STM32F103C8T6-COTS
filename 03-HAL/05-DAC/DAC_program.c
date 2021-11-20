/********************************************************************/
/***********	Author	 :  Tarek Elmenshawy			*************/
/***********	File Name:  DAC_progarm.c				*************/
/***********	Version	 :  V0.1						*************/
/***********	Date	 :  19-11-2021					*************/
/***********	Function :  DAC Handler					*************/
/********************************************************************/

/********************************************************************/
/******		 Guard of file will call one time in .c file	   ******/
/********************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of lower library */
#include "GPIO_interface.h"
#include "STK_interface.h"

/* Include Audio header file */
#include "song.h"

/* Include DAC driver header files */
#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"

void HDAC_voidInit(void)
{
	/* Local counter */
	u8 i;
	
	for(i = 0; i < DAC_RESOLUTION; i++)
	{
		/* Configure DAC pins as output push-pull */
		MGPIO_voidSetPinDirection(HDAC_Pin[i][0], HDAC_Pin[i][1], GPIO_OUTPUT_2MHZ_PP);
	}
	
}

void HDAC_voidPlay(void)
{
	/* Start periodic interval 125 uSec */
	MSTK_voidSetIntervalPeriodic(125, HDAC_Handler);
}

void HDAC_Handler(void)
{
	u8 i;					/* Local counter */
	u8 Local_u8Bit;			/* Local temporary variable */
	
	for(i = 0; i < DAC_RESOLUTION; i++)
	{
		/* Get bit value */
		Local_u8Bit = GET_BIT(song_raw[HDAC_u16Counter], i);
		/* set bit value */
		MGPIO_voidSetPinValue(HDAC_Pin[i][0], HDAC_Pin[i][1], Local_u8Bit);
	}
	
	/* Counter increment */
	HDAC_u16Counter++;
	/* If counter reach the end, reset it */
	if(HDAC_u16Counter > 38824) HDAC_u16Counter = 0;
}

