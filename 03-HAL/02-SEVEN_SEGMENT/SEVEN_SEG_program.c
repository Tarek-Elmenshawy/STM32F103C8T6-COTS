/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  SEVEN_SEG_program.c		***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  19-10-2021				***********/
/***********	Function :  7 Segment Handler		***********/
/**************************************************************/

/* Include Libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of lower layer */
#include "RCC_interface.h"
#include "GPIO_interface.h"

/* Include SEVEN_SEG header files */
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"

const u8 Globl_u8SevSegPattern[10][7] = {
  /* a  b  c  d  e  f  g */
	{1, 1, 1, 1, 1, 1, 0},     /* Zero 	*/
	{0, 1, 1, 0, 0, 0, 0},     /* One 	*/
	{1, 1, 0, 1, 1, 0, 1},     /* Two 	*/
	{1, 1, 1, 1, 0, 0, 1},     /* Three */
	{0, 1, 1, 0, 0, 1, 1},     /* Four 	*/
	{1, 0, 1, 1, 0, 1, 1},     /* Five 	*/
	{1, 0, 1, 1, 1, 1, 1},     /* Six 	*/
	{1, 1, 1, 0, 0, 0, 0},     /* Seven	*/
	{1, 1, 1, 1, 1, 1, 1},     /* Eight	*/
	{1, 1, 1, 1, 0, 1, 1}      /* Nine 	*/
};

void SEVEN_SEG_voidInitSevenSegment(void)
{
	#if   SEVEN_SEG_PORT == GPIOA
		
		/* Enable Clock of GPIOA */
		MRCC_voidEnableClock(RCC_APB2_BUS, RCC_IOPA);

		/* Configure Seven Segment PINs as output push-pull */
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINA, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINB, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINC, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PIND, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINE, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINF, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PING, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA, SEVEN_SEG_PINH, GPIO_OUTPUT_10MHZ_PP);
		
		#if   SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_CATHODE
		
			/* Set PIN H output HIGH to light dot segment */
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINH, 1);
			
		#elif SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_ANODE
		
			/* Set PIN H output LOW to light dot segment */
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINH, 0);
			
		#else
			#error("Wrong Seven Segment Type Selection ")
		#endif
		
	#elif SEVEN_SEG_PORT == GPIOB

		/* Enable Clock of GPIOB */
		MRCC_voidEnableClock(RCC_APB2_BUS, RCC_IOPB);
	
		/* Configure Seven Segment PINs as output push-pull */
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINA, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINB, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINC, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PIND, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINE, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINF, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PING, GPIO_OUTPUT_10MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOB, SEVEN_SEG_PINH, GPIO_OUTPUT_10MHZ_PP);
		
		#if   SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_CATHODE
		
			/* Set PIN H output HIGH to light dot segment */
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINH, 1);
			
		#elif SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_ANODE
		
			/* Set PIN H output LOW to light dot segment */
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINH, 0);
			
		#else
			#error("Wrong Seven Segment Type Selection ")
		#endif
		
	#else
		#error("Wrong Seven Segment PORT Configuration")
	#endif
}


void SEVEN_SEG_voidDisplayNumber(u8 Copy_u8Number)
{
	#if   SEVEN_SEG_PORT == GPIOA
		
		/* Set Seven Segment PINs output corresponding to Copy_u8Number */
		#if SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_CATHODE
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINA, Globl_u8SevSegPattern[Copy_u8Number][0]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINB, Globl_u8SevSegPattern[Copy_u8Number][1]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINC, Globl_u8SevSegPattern[Copy_u8Number][2]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PIND, Globl_u8SevSegPattern[Copy_u8Number][3]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINE, Globl_u8SevSegPattern[Copy_u8Number][4]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINF, Globl_u8SevSegPattern[Copy_u8Number][5]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PING, Globl_u8SevSegPattern[Copy_u8Number][6]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINH, 0);
		#else
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINA, !Globl_u8SevSegPattern[Copy_u8Number][0]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINB, !Globl_u8SevSegPattern[Copy_u8Number][1]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINC, !Globl_u8SevSegPattern[Copy_u8Number][2]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PIND, !Globl_u8SevSegPattern[Copy_u8Number][3]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINE, !Globl_u8SevSegPattern[Copy_u8Number][4]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINF, !Globl_u8SevSegPattern[Copy_u8Number][5]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PING, !Globl_u8SevSegPattern[Copy_u8Number][6]);
			MGPIO_voidSetPinValue(GPIOA, SEVEN_SEG_PINH, 1);
		#endif
		
	#else
		
		/* Set Seven Segment PINs output corresponding to Copy_u8Number */
		#if SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_CATHODE
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINA, Globl_u8SevSegPattern[Copy_u8Number][0]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINB, Globl_u8SevSegPattern[Copy_u8Number][1]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINC, Globl_u8SevSegPattern[Copy_u8Number][2]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PIND, Globl_u8SevSegPattern[Copy_u8Number][3]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINE, Globl_u8SevSegPattern[Copy_u8Number][4]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINF, Globl_u8SevSegPattern[Copy_u8Number][5]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PING, Globl_u8SevSegPattern[Copy_u8Number][6]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINH, 0);
		#else
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINA, !Globl_u8SevSegPattern[Copy_u8Number][0]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINB, !Globl_u8SevSegPattern[Copy_u8Number][1]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINC, !Globl_u8SevSegPattern[Copy_u8Number][2]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PIND, !Globl_u8SevSegPattern[Copy_u8Number][3]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINE, !Globl_u8SevSegPattern[Copy_u8Number][4]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINF, !Globl_u8SevSegPattern[Copy_u8Number][5]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PING, !Globl_u8SevSegPattern[Copy_u8Number][6]);
			MGPIO_voidSetPinValue(GPIOB, SEVEN_SEG_PINH, 1);
		#endif
		
	#endif
}



