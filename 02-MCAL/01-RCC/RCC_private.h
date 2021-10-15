/***************************************************************/
/***********     Author    :  Tarek Elmenshawy       ***********/
/***********     File Name :  RCC_private.h          ***********/
/***********     Version   :  V0.1                   ***********/
/***********     Date      :  08-9-2021              ***********/
/***********     Function  :                         ***********/
/***************************************************************/

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



// M is referred to MCAL
#define MRCC	((volatile RCC *)0x40021000)

#endif