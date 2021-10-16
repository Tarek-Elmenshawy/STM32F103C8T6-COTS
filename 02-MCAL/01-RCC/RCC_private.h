/****************************************************************/
/***********     Author    :  Tarek Elmenshawy        ***********/
/***********     File Name :  RCC_private.h           ***********/
/***********     Version   :  V0.2                    ***********/
/***********     Date      :  08-9-2021               ***********/
/***********     Function  :  RCC Private Contents    ***********/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef struct{
	volatile u32 RCC_CR;		// 0x00
	volatile u32 RCC_CFGR;      // 0x04
	volatile u32 RCC_CIR;       // 0x08
	volatile u32 RCC_APB2RSTR;  // 0x0C
	volatile u32 RCC_APB1RSTR;  // 0x10
	volatile u32 RCC_AHBENR;    // 0x14
	volatile u32 RCC_APB2ENR;   // 0x18
	volatile u32 RCC_APB1ENR;	// 0x1C
	volatile u32 RCC_BDCR;		// 0x20
	volatile u32 RCC_CSR;		// 0x24
}RCC;

/* Clock Control Register Bits */
#define RCC_CR_HSION_BIT	0
#define RCC_CR_HSIRDY_BIT	1
#define RCC_CR_HSEON_BIT	16
#define RCC_CR_HSERDY_BIT	17
#define RCC_CR_HSEBYP_BIT	18
#define RCC_CR_CSSON_BIT	19
#define RCC_CR_PLLON_BIT	24
#define RCC_CR_PLLRDY_BIT	25

/* Clock Configuration Register */
#define RCC_CFGR_SW_HSI			(0b00)
#define RCC_CFGR_SW_HSE			(0b01)
#define RCC_CFGR_SW_PLL			(0b10)
#define RCC_CFGR_PLLXTPRE_BIT	17
#define RCC_CFGR_PLLSRC_BIT		16



/* M is referred to MCAL */
#define MRCC	((volatile RCC *)0x40021000)

/****************************************************************/
/*																*/
/*			Clock Types: 										*/
/*						1- RCC_HSI								*/
/*						2- RCC_HSE								*/
/*						3- RCC_HSE_BYPASS						*/
/*						4- RCC_PLL								*/
/*																*/
/****************************************************************/
#define RCC_HSI			0
#define RCC_HSE			1
#define RCC_HSE_BYPASS	2
#define RCC_PLL			3


/****************************************************************/
/*																*/
/*			PLL Source Types:									*/
/*							1- RCC_PLL_HSI_DEV_BY_2				*/
/*							2- RCC_PLL_HSE_DEV_BY_2				*/
/*							3- RCC_PLL_HSE						*/
/*																*/
/****************************************************************/
#define RCC_PLL_HSI_DEV_BY_2	0
#define RCC_PLL_HSE_DEV_BY_2	1
#define RCC_PLL_HSE				2


/****************************************************************/
/*				  HSE Bypass:									*/
/*							1- RCC_PLL_HSE_DISABLE_BYPASS		*/
/*							2- RCC_PLL_HSE_ENABLE_BYPASS		*/
/****************************************************************/
#define RCC_PLL_HSE_DISABLE_BYPASS	0
#define RCC_PLL_HSE_ENABLE_BYPASS	1


/****************************************************************/
/*																*/
/*			Clock Factor For PLL:								*/
/*							1- RCC_PLL_CLOCK_MUL_BY_2			*/
/*							2- RCC_PLL_CLOCK_MUL_BY_3			*/
/*							3- RCC_PLL_CLOCK_MUL_BY_4			*/
/*							4- RCC_PLL_CLOCK_MUL_BY_5			*/
/*							5- RCC_PLL_CLOCK_MUL_BY_6			*/
/*							6- RCC_PLL_CLOCK_MUL_BY_7			*/
/*							7- RCC_PLL_CLOCK_MUL_BY_8			*/
/*							8- RCC_PLL_CLOCK_MUL_BY_9			*/
/*							9- RCC_PLL_CLOCK_MUL_BY_10			*/
/*							10- RCC_PLL_CLOCK_MUL_BY_11			*/
/*							11- RCC_PLL_CLOCK_MUL_BY_12			*/
/*							12- RCC_PLL_CLOCK_MUL_BY_13			*/
/*							13- RCC_PLL_CLOCK_MUL_BY_14			*/
/*							14- RCC_PLL_CLOCK_MUL_BY_15			*/
/*							15- RCC_PLL_CLOCK_MUL_BY_16			*/
/*																*/
/****************************************************************/
#define RCC_PLL_CLOCK_MUL_BY_2	(0b0000)
#define RCC_PLL_CLOCK_MUL_BY_3	(0b0001)
#define RCC_PLL_CLOCK_MUL_BY_4	(0b0010)
#define RCC_PLL_CLOCK_MUL_BY_5	(0b0011)
#define RCC_PLL_CLOCK_MUL_BY_6	(0b0100)
#define RCC_PLL_CLOCK_MUL_BY_7	(0b0101)
#define RCC_PLL_CLOCK_MUL_BY_8	(0b0110)
#define RCC_PLL_CLOCK_MUL_BY_9	(0b0111)
#define RCC_PLL_CLOCK_MUL_BY_10	(0b1000)
#define RCC_PLL_CLOCK_MUL_BY_11	(0b1001)
#define RCC_PLL_CLOCK_MUL_BY_12	(0b1010)
#define RCC_PLL_CLOCK_MUL_BY_13	(0b1011)
#define RCC_PLL_CLOCK_MUL_BY_14	(0b1100)
#define RCC_PLL_CLOCK_MUL_BY_15	(0b1101)
#define RCC_PLL_CLOCK_MUL_BY_16	(0b1110)


/****************************************************************/
/*																*/
/*	Clock Security System:										*/
/*		1- RCC_ENABLE_CLOCK_SECURITY_SYSTEM						*/
/*			- To set HSI by H.W. when there is failure in HSE	*/
/*																*/
/*		2- RCC_DISABLE_CLOCK_SECURITY_SYSTEM					*/
/*																*/
/****************************************************************/
#define RCC_ENABLE_CLOCK_SECURITY_SYSTEM	0
#define RCC_DISABLE_CLOCK_SECURITY_SYSTEM	1

#endif