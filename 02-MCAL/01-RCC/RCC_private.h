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
	volatile u32 RCC_CR;						/* Clock Control Register 					*/
	volatile u32 RCC_CFGR;						/* Clock Configuration Register 			*/
	volatile u32 RCC_CIR;						/* Clock Interrupt Register 				*/
	volatile u32 RCC_APB2RSTR;  				/* APB2 Peripheral Reset Register 			*/
	volatile u32 RCC_APB1RSTR;  				/* APB1 Peripheral Reset Register 			*/
	volatile u32 RCC_AHBENR;    				/* AHB Peripheral Clock Enable Register 	*/
	volatile u32 RCC_APB2ENR;   				/* APB2 Peripheral Clock Enable Register	*/
	volatile u32 RCC_APB1ENR;					/* APB1 Peripheral Clock Enable Register	*/
	volatile u32 RCC_BDCR;						/* Backup Domain Control Register 			*/
	volatile u32 RCC_CSR;						/* Control/Status Register					*/
}RCC;


/* Clock Control Register (RCC_CR) Bits */
#define RCC_CR_HSION_BIT	0					/* Internal High-Speed Clock Enable			*/
#define RCC_CR_HSIRDY_BIT	1					/* Internal High-Speed Clock Ready Flag		*/
#define RCC_CR_HSEON_BIT	16					/* External High-Speed Clock Enable			*/
#define RCC_CR_HSERDY_BIT	17					/* External High-Speed Clock Ready Flag		*/
#define RCC_CR_HSEBYP_BIT	18					/* External High-Speed Clock Bypass			*/
#define RCC_CR_CSSON_BIT	19					/* Clock Security System Enable				*/
#define RCC_CR_PLLON_BIT	24					/* PLL Enable								*/
#define RCC_CR_PLLRDY_BIT	25					/* PLL Clock Ready Fag						*/


/* Clock Configuration Register (RCC_CFG) */
#define RCC_CFGR_SW_HSI			(0b00)			/* HSE as System Clock Configuration		*/
#define RCC_CFGR_SW_HSE			(0b01)			/* HSI as System Clock Configuration		*/
#define RCC_CFGR_SW_PLL			(0b10)			/* PLL as System Clock Configuration		*/
#define RCC_CFGR_PLLXTPRE_BIT	17				/* HSE Diver For PLL Entry					*/
#define RCC_CFGR_PLLSRC_BIT		16				/* PLL Entry Cock Source					*/


/* M is referred to MCAL */
#define MRCC	((volatile RCC *)0x40021000)	/* Base Address of RCC						*/


/* Clock System Types */
#define RCC_HSI			0
#define RCC_HSE			1
#define RCC_HSE_BYPASS	2
#define RCC_PLL			3


/* PLL Source Types */
#define RCC_PLL_HSI_DEV_BY_2	0
#define RCC_PLL_HSE_DEV_BY_2	1
#define RCC_PLL_HSE				2


/* HSE Mode for PLL */
#define RCC_PLL_HSE_DISABLE_BYPASS	0
#define RCC_PLL_HSE_ENABLE_BYPASS	1


/* Clock Factor For PLL */
#define RCC_PLL_CLOCK_MUL_BY_2	(0b0000)		/* PLL Input Clock x 2						*/
#define RCC_PLL_CLOCK_MUL_BY_3	(0b0001)		/* PLL Input Clock x 3						*/		
#define RCC_PLL_CLOCK_MUL_BY_4	(0b0010)		/* PLL Input Clock x 4						*/
#define RCC_PLL_CLOCK_MUL_BY_5	(0b0011)		/* PLL Input Clock x 5						*/
#define RCC_PLL_CLOCK_MUL_BY_6	(0b0100)		/* PLL Input Clock x 6						*/
#define RCC_PLL_CLOCK_MUL_BY_7	(0b0101)		/* PLL Input Clock x 7						*/
#define RCC_PLL_CLOCK_MUL_BY_8	(0b0110)		/* PLL Input Clock x 8						*/
#define RCC_PLL_CLOCK_MUL_BY_9	(0b0111)		/* PLL Input Clock x 9						*/
#define RCC_PLL_CLOCK_MUL_BY_10	(0b1000)		/* PLL Input Clock x 10						*/
#define RCC_PLL_CLOCK_MUL_BY_11	(0b1001)		/* PLL Input Clock x 11						*/
#define RCC_PLL_CLOCK_MUL_BY_12	(0b1010)		/* PLL Input Clock x 12						*/
#define RCC_PLL_CLOCK_MUL_BY_13	(0b1011)		/* PLL Input Clock x 13						*/
#define RCC_PLL_CLOCK_MUL_BY_14	(0b1100)		/* PLL Input Clock x 14						*/
#define RCC_PLL_CLOCK_MUL_BY_15	(0b1101)		/* PLL Input Clock x 15						*/
#define RCC_PLL_CLOCK_MUL_BY_16	(0b1110)		/* PLL Input Clock x 16						*/


/* Clock Security System */
#define RCC_ENABLE_CLOCK_SECURITY_SYSTEM	0
#define RCC_DISABLE_CLOCK_SECURITY_SYSTEM	1

#endif	/* RCC_PRIVATE_H */