/****************************************************************/
/***********     Author    :  Tarek Elmenshawy       ************/
/***********     File Name :  RCC_config.h	         ************/
/***********     Version   :  V0.2                   ************/
/***********     Date      :  08-9-2021              ************/
/***********     Function  :  RCC Config Handler	 ************/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/****************************************************************/
/*																*/
/*			Clock System Types: 								*/
/*							  1- RCC_HSI						*/
/*							  2- RCC_HSE						*/
/*							  3- RCC_HSE_BYPASS					*/
/*							  4- RCC_PLL						*/
/*																*/
/****************************************************************/
#define RCC_CLOCK_TYPE				RCC_HSE


/****************************************************************/
/*																*/
/*			PLL Source Types:									*/
/*							1- RCC_PLL_HSI_DEV_BY_2				*/
/*							2- RCC_PLL_HSE_DEV_BY_2				*/
/*							3- RCC_PLL_HSE						*/
/*																*/
/*				  HSE Bypass:									*/
/*							1- RCC_PLL_HSE_DISABLE_BYPASS		*/
/*							2- RCC_PLL_HSE_ENABLE_BYPASS		*/
/*																*/
/*	Note: Select value only if you have PLL as input clock		*/
/*		  source												*/
/*																*/
/****************************************************************/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_SOURCE				RCC_PLL_HSE_DEV_BY_2
#define RCC_PLL_HSE_BYPASS			RCC_PLL_HSE_DISABLE_BYPASS			
#endif

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
/*	Note: Select value only if you have PLL as input clock		*/
/*		  source												*/
/*																*/
/****************************************************************/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_CLOCK_MUL_VAL		RCC_PLL_CLOCK_MUL_BY_9
#endif

/****************************************************************/
/*																*/
/*	Clock Security System:										*/
/*		1- RCC_ENABLE_CLOCK_SECURITY_SYSTEM						*/
/*			- To set HSI by H.W. when there is failure in HSE	*/
/*																*/
/*		2- RCC_DISABLE_CLOCK_SECURITY_SYSTEM					*/
/*																*/
/****************************************************************/
#define RCC_CLOCK_SECURITY_SYSTEM	RCC_DISABLE_CLOCK_SECURITY_SYSTEM


#endif
