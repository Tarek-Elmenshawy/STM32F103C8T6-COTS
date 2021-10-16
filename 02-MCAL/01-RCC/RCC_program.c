/***************************************************************/																										
/***********     Author    :  Tarek Elmenshawy       ***********/
/***********     File Name :  RCC_program.c          ***********/
/***********     Version   :  V0.2                   ***********/
/***********     Date      :  08-9-2021              ***********/
/***********     Function  :  RCC Handler			 ***********/
/***************************************************************/

/* Include Libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include RCC Driver Header files*/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSysClock(void)
{
	u32 Loc_u32TimeOut = 0;
	
	#if   RCC_CLOCK_TYPE == RCC_HSE
		
		MRCC->RCC_CFGR &= ~((u32)0b11);											// Reset System Clock Switch (SW[1:0])
		MRCC->RCC_CFGR |= RCC_CFGR_SW_HSE;										// Select HSE clock as system clock source
		SET_BIT(MRCC->RCC_CR, RCC_CR_HSEON_BIT);								// Enable HSE clock with no bypass

		/* Waiting until HSE ready flag is set */
		while((GET_BIT(MRCC->RCC_CR, RCC_CR_HSERDY_BIT) == 0) && (Loc_u32TimeOut < 100000)) Loc_u32TimeOut++;
		if(Loc_u32TimeOut >= 100000){ /* Time out */ }

	#elif RCC_CLOCK_TYPE == RCC_HSE_BYPASS
		
		MRCC->RCC_CFGR &= ~((u32)0b11);											// Reset System Clock Switch (SW[1:0])
		MRCC->RCC_CFGR |= RCC_CFGR_SW_HSE;										// Select HSE clock as system clock source
		MRCC->RCC_CR   |= ((1 << RCC_CR_HSEON_BIT) | (1 << RCC_CR_HSEBYP_BIT));	// Enable HSE clock with bypass
		
		/* Waiting until HSE ready flag is set */
		while((GET_BIT(MRCC->RCC_CR, RCC_CR_HSERDY_BIT) == 0) && (Loc_u32TimeOut < 100000)) Loc_u32TimeOut++;
		if(Loc_u32TimeOut >= 100000){ /* Time out */ }
		
	#elif RCC_CLOCK_TYPE == RCC_HSI
		
		MRCC->RCC_CFGR &= ~((u32)0b11);											// Reset System Clock Switch (SW[1:0])
		MRCC->RCC_CFGR |= RCC_CFGR_SW_HSI;										// Select HSI clock as system clock source
		SET_BIT(MRCC->RCC_CR, RCC_CR_HSION_BIT);								// Enable HSI clock
		
		/* Waiting until HSI ready flag is set */
		while((GET_BIT(MRCC->RCC_CR, RCC_CR_HSIRDY_BIT) == 0) && (Loc_u32TimeOut < 100000)) Loc_u32TimeOut++;
		if(Loc_u32TimeOut >= 100000){ /* Time out */ }
		
	#elif RCC_CLOCK_TYPE == RCC_PLL
		
		MRCC->RCC_CFGR &= ~((u32)0b11);											// Reset System Clock Switch (SW[1:0])
		MRCC->RCC_CFGR |= RCC_CFGR_SW_PLL;										// Select PLL as system clock source
		
		/* Choosing multiplication factor for PLL*/
		#if (RCC_PLL_CLOCK_MUL_VAL >= RCC_PLL_CLOCK_MUL_BY_2) && (RCC_PLL_CLOCK_MUL_VAL <= RCC_PLL_CLOCK_MUL_BY_16)
			
			MRCC->RCC_CFGR &= ~(0b1111 << 18);									// Reset PLL Multiplication Factor (PLLMUL[3:0])
			MRCC->RCC_CFGR |=  (RCC_PLL_CLOCK_MUL_VAL << 18);					// Set Multiplication Factor for PLL
			
		#else
			#error("Wrong PLL multiplication factor configuration")
		#endif
		
		/* Select PLL input clock source */
		#if   RCC_PLL_SOURCE == RCC_PLL_HSI_DEV_BY_2
			
			SET_BIT(MRCC->RCC_CR  , RCC_CR_HSION_BIT);							// Enable HSI clock
			CLR_BIT(MRCC->RCC_CFGR, RCC_CFGR_PLLSRC_BIT);						// Set (HIS clock / 2) as PLL clock source
			
		#elif RCC_PLL_SOURCE == RCC_PLL_HSE_DEV_BY_2
			
			#if RCC_PLL_HSE_BYPASS == RCC_PLL_HSE_ENABLE_BYPASS
				MRCC->RCC_CR |= ((1 << RCC_CR_HSEON_BIT) | (1 << RCC_CR_HSEBYP_BIT)); // Enable HSE clock with bypass
			#else
				SET_BIT(MRCC->RCC_CR, RCC_CR_HSEON_BIT);						// Enable HSE clock with no bypass
			#endif
			
			MRCC->RCC_CFGR |= ((1 << RCC_CFGR_PLLSRC_BIT) | (1 << RCC_CFGR_PLLXTPRE_BIT));// Select (HES clock / 2) as PLL clock source
			
		#elif RCC_PLL_SOURCE == RCC_PLL_HSE
			
			#if RCC_PLL_HSE_BYPASS == RCC_PLL_HSE_ENABLE_BYPASS
				MRCC->RCC_CR |= ((1 << RCC_CR_HSEON_BIT) | (1 << RCC_CR_HSEBYP_BIT)); // Enable HSE clock with bypass
			#else
				SET_BIT(MRCC->RCC_CR, RCC_CR_HSEON_BIT);						// Enable HSE clock with no bypass
			#endif
			
			SET_BIT(MRCC->RCC_CFGR, RCC_CFGR_PLLSRC_BIT);						// Select HES clock as PLL clock source
			
		#else
			#error("Wrong PLL input clock source configuration")
		#endif
		
		SET_BIT(MRCC->RCC_CR, RCC_CR_PLLON_BIT);								// Enable HSI clock
		
		/* Waiting until PLL ready flag is set */
		while((GET_BIT(MRCC->RCC_CR, RCC_CR_PLLRDY_BIT) == 0) && (Loc_u32TimeOut < 100000)) Loc_u32TimeOut++;
		if(Loc_u32TimeOut >= 100000){ /* Time out */ }
		
	#else
		#error("Wrong clock system type configuration")
	#endif
	
	/* For Clock System Security */
	#if RCC_CLOCK_SECURITY_SYSTEM == RCC_DISABLE_CLOCK_SECURITY_SYSTEM
		CLR_BIT(MRCC->RCC_CR, RCC_CR_CSSON_BIT);								// Disable clock system security
	#elif RCC_CLOCK_SECURITY_SYSTEM == RCC_ENABLE_CLOCK_SECURITY_SYSTEM
		SET_BIT(MRCC->RCC_CR, RCC_CR_CSSON_BIT);								// Enable clock system security
	#else
		#error("Wrong clock system security configuration")
	#endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{	
	/* Input Validation */
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB_BUS : SET_BIT(MRCC->RCC_AHBENR , Copy_u8PerId); break;	// Enable clock for the passed peripheral ID on AHB bus
			case RCC_APB1_BUS: SET_BIT(MRCC->RCC_APB1ENR, Copy_u8PerId); break;	// Enable clock for the passed peripheral ID on APB1 bus
			case RCC_APB2_BUS: SET_BIT(MRCC->RCC_APB2ENR, Copy_u8PerId); break;	// Enable clock for the passed peripheral ID on APB2 bus
			default			 : /* Return error */ 						 break;
		}
	}
	else
	{
		/* Return error */
	}
}

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* Input Validation */
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB_BUS : CLR_BIT(MRCC->RCC_AHBENR , Copy_u8PerId); break;	// Disable clock for the passed peripheral ID on AHB bus
			case RCC_APB1_BUS: CLR_BIT(MRCC->RCC_APB1ENR, Copy_u8PerId); break;	// Disable clock for the passed peripheral ID on APB1 bus
			case RCC_APB2_BUS: CLR_BIT(MRCC->RCC_APB2ENR, Copy_u8PerId); break;	// Disable clock for the passed peripheral ID on APB2 bus
			default			 : /* Return error */						 break;
		}
	}
	else
	{
		/* Return error */
	}
}

