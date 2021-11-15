/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  IR_NEC_program.c		***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  15-11-2021				***********/
/***********	Function :  IR_NEC Handler			***********/
/**************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of lower layers */
#include "STK_interface.h"
#include "GPIO_interface.h"

/* Include IR_NEC driver header files */
#include "IR_NEC_interface.h"
#include "IR_NEC_private.h"
#include "IR_NEC_config.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

void HIR_NEC_voidInit(void (*Copy_ptr)(u8 Copy_u8IRAddress, u8 Copy_u8IRCommand))
{
	/* Configure EXTI line */
	#if IR_NEC_RECEIVER_PORT == GPIOA
		MAFIO_voidSetEXTIConfig(IR_NEC_RECEIVER_PIN, AFIO_PA);
	#elif IR_NEC_RECEIVER_PORT == GPIOB
		MAFIO_voidSetEXTIConfig(IR_NEC_RECEIVER_PIN, AFIO_PB);
	#elif IR_NEC_RECEIVER_PORT == GPIOC
		MAFIO_voidSetEXTIConfig(IR_NEC_RECEIVER_PIN, AFIO_PC);
	#endif
	
	MEXTI_voidInit(IR_NEC_RECEIVER_PIN, EXTI_FALLING);			/* Initialize EXTI as falling edge */
	MEXTI_voidSetCallback(IR_NEC_RECEIVER_PIN, voidGetFrame);	/* Set callback function */
	
	HIR_NEC_Callback = Copy_ptr;								/* Set IR_Nec callback funtion pointer */
}

static void voidGetFrame(void)
{
	if(HIR_NEC_u8StartFlag == 0)
	{
		/* Start timer */
		MSTK_voidSetIntervalSingle(250000, voidAnalyseFrame);
		/* Clear starting flag */
		HIR_NEC_u8StartFlag = 1;
	}
	else
	{
		/* Save pulse train time */
		HIR_NEC_u32FrameTime[HIR_NEC_u16EdgeCounter] = MSTK_u32GetElapsedTime();
		/* Reset timer */
		MSTK_voidSetIntervalSingle(250000, voidAnalyseFrame);
		/* Increment edge counter */
		if(HIR_NEC_u16EdgeCounter < 50) HIR_NEC_u16EdgeCounter++;
	}
}

static void voidAnalyseFrame(void)
{
	HIR_NEC_u32FrameData = 0;							/* Reset data for new analysis */
	u32 i;												/* Local counter for indexing */

	/* Validate start bit */
	if(HIR_NEC_u32FrameTime[0] >= 12500 && HIR_NEC_u32FrameTime[0] <= 14500)
	{
		for(i = 0; i < 32; i++)
		{
			if(HIR_NEC_u32FrameTime[1 + i] >= 2000 && HIR_NEC_u32FrameTime[1 + i] <= 2500)
			{
				SET_BIT(HIR_NEC_u32FrameData, i);		/* Set logic 1 */
			}
			else
			{
				CLR_BIT(HIR_NEC_u32FrameData, i);		/* Set logic 0 */
			}
		}
		
		/* Data verification */
		u8 address	=  (HIR_NEC_u32FrameData & 0x000000FF);
		u8 _address	= ~((HIR_NEC_u32FrameData & 0x0000FF00) >> 8);
		u8 command 	=  ((HIR_NEC_u32FrameData & 0x00FF0000) >> 16);
		u8 _command = ~(HIR_NEC_u32FrameData >> 24);

		if((address == _address) && (command == _command))
		{
			/* Successful verification */
			HIR_NEC_Callback(address, command);
		}
		else
		{
			/* Failed verification */
		}
	}
	else
	{
		/* Invalid frame */
	}
	
	/* Reset data variables */
	HIR_NEC_u32FrameTime[0] = 0;
	HIR_NEC_u16EdgeCounter 	= 0;
	HIR_NEC_u8StartFlag 	= 0;
}

void HIR_NEC_voidEnable(void)
{
	MEXTI_voidEnable(IR_NEC_RECEIVER_PIN);				/* Enable EXTIO */
}
void HIR_NEC_voidDisable(void)
{
	MEXTI_voidDisable(IR_NEC_RECEIVER_PIN);				/* Disable EXTIO */
}
