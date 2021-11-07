/*******************************************************************/
/***********	Author	 :  Tarek Elmenshawy			************/
/***********	File Name:  LED_MATRIX_program.c		************/
/***********	Version	 :  V0.1						************/
/***********	Date	 :  5-10-2021					************/
/***********	Function :  LES_MATRIX Handler			************/
/*******************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of MCAL layer */
#include "GPIO_interface.h"
#include "STK_interface.h"

/* Include KED_MATRIX header files*/
#include "LED_MATRIX_interface.h"
#include "LED_MATRIX_config.h"
#include "LED_MATRIX_private.h"

void HLED_MATRIX_voidInit(void)
{	
	u8 Local_u8Index = 0;
	
	/* Configure column pins as output push-pull */
	for(Local_u8Index = 0; Local_u8Index < LED_MATRIX_NUM_COLS; Local_u8Index++)
		MGPIO_voidSetPinDirection(LED_MATRIX_u8ColPins[Local_u8Index][0], LED_MATRIX_u8ColPins[Local_u8Index][1], GPIO_OUTPUT_2MHZ_PP);			
	
	/* Configure row pins as output push-pull */
	for(Local_u8Index = 0; Local_u8Index < LED_MATRIX_NUM_ROWS; Local_u8Index++)
		MGPIO_voidSetPinDirection(LED_MATRIX_u8RowPins[Local_u8Index][0], LED_MATRIX_u8RowPins[Local_u8Index][1], GPIO_OUTPUT_2MHZ_PP);			
}


void HLED_MATRIX_voidDisplayFrame(u8 *Copy_u8Frame)
{
	u8 Local_u8Index = 0;
	
	while(1)
	{
		#if   LED_MATRIX_OPERATION_MODE == LED_MATRIX_COL_CONTROL
			
			for(Local_u8Index = 0; Local_u8Index < LED_MATRIX_NUM_COLS; Local_u8Index++)
			{
				/* Disable all columns */
				HLED_MATRIX_voidDisableAllLines(LED_MATRIX_u8ColPins, LED_MATRIX_NUM_COLS);
				
				/* Set the corresponding row value */
				HLED_MATRIX_voidSetLineValue(LED_MATRIX_u8RowPins, LED_MATRIX_NUM_ROWS, Copy_u8Frame[Local_u8Index]);
				
				/* Enable the corresponding column */
				#if   LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_LOW
					MGPIO_voidSetPinValue(LED_MATRIX_u8ColPins[Local_u8Index][0], LED_MATRIX_u8ColPins[Local_u8Index][1], 0);
				#elif LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_HIGH
					MGPIO_voidSetPinValue(LED_MATRIX_u8ColPins[Local_u8Index][0], LED_MATRIX_u8ColPins[Local_u8Index][1], 1);
				#else
					#error("Wrong LED MATRIX operation control mode configuration")
				#endif

				/* Delay for some time */
				MSTK_voidSetBusyWait(2500);
			}
			
		#elif LED_MATRIX_OPERATION_MODE == LED_MATRIX_ROW_CONTROL
			
			for(Local_u8Index = 0; Local_u8Index < LED_MATRIX_NUM_ROWS; Local_u8Index++)
			{
				/* Disable all rows */
				HLED_MATRIX_voidDisableAllLines(LED_MATRIX_u8RowPins, LED_MATRIX_NUM_ROWS);
				
				/* Set the corresponding column value */
				HLED_MATRIX_voidSetLineValue(LED_MATRIX_u8ColPins, LED_MATRIX_NUM_COLS, Copy_u8Frame[Local_u8Index]);
				
				/* Enable the corresponding row */
				#if   LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_LOW
					MGPIO_voidSetPinValue(LED_MATRIX_u8RowPins[Local_u8Index][0], LED_MATRIX_u8RowPins[Local_u8Index][1], 0);
				#elif LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_HIGH
					MGPIO_voidSetPinValue(LED_MATRIX_u8RowPins[Local_u8Index][0], LED_MATRIX_u8RowPins[Local_u8Index][1], 1);
				#else
					#error("Wrong LED MATRIX operation control mode configuration")
				#endif

				/* Delay for some time */
				MSTK_voidSetBusyWait(2500);
			}
			
		#else 
			#error("Wrong LED MATRIX operation mode configuration")
		#endif
	}
}

static void HLED_MATRIX_voidDisableAllLines(u8 Copy_u8LinePin[][2], u8 Copy_u8NumLines)
{
	u8 Local_u8Index = 0;
	
	/* Disable all Lines */
	for(Local_u8Index = 0; Local_u8Index < Copy_u8NumLines; Local_u8Index++)
	{
		#if   LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_LOW
			MGPIO_voidSetPinValue(Copy_u8LinePin[Local_u8Index][0], Copy_u8LinePin[Local_u8Index][1], 1);	
		#elif LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_HIGH
			MGPIO_voidSetPinValue(Copy_u8LinePin[Local_u8Index][0], Copy_u8LinePin[Local_u8Index][1], 0);
		#else
			#error("Wrong LED MATRIX operation control mode configuration")
		#endif
	}
}

static void HLED_MATRIX_voidSetLineValue(u8 Copy_u8LinePin[][2], u8 Copy_u8NumLines, u8 Copy_u8Value)
{
	u8 Local_u8Index = 0;
	u8 Local_u8Bit	 = 0;
	
	/* Set value to corresponding line */
	for(Local_u8Index = 0; Local_u8Index < Copy_u8NumLines; Local_u8Index++)
	{
		Local_u8Bit = GET_BIT(Copy_u8Value, Local_u8Index);
		#if   LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_LOW
			MGPIO_voidSetPinValue(Copy_u8LinePin[Local_u8Index][0], Copy_u8LinePin[Local_u8Index][1], Local_u8Bit);	
		#elif LED_MATRIX_CONTROL_MODE == LED_MATRIX_ACTIVE_HIGH
			MGPIO_voidSetPinValue(Copy_u8LinePin[Local_u8Index][0], Copy_u8LinePin[Local_u8Index][1], !Local_u8Bit);
		#else
			#error("Wrong LED MATRIX operation control mode configuration")
		#endif
	}
}
