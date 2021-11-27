/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  TIM_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-11-2021				***********/
/***********	Function :  TIM Private Contents	***********/
/**************************************************************/

/**************************************************************/
/*****    Guard of file will call one time in .c file	  *****/
/**************************************************************/

#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H

#define TIM_SINGLE_INTERVAL		1
#define TIM_PERIODIC_INTERVAL	2

#define TIM_CR1_CEN		0								/* Counter Enable Bit							*/
#define TIM_CR1_OPM		3								/* One Pulse Mode Bit							*/
#define TIM_DIER_UIE	0								/* Update Interrupt Enable Bit					*/
#define TIM_SR_UIF		0								/* Update Interrupt Flag Bit					*/

typedef struct{
	
	volatile u32 TIM_CR1;								/* Timer Control Register 1						*/
	volatile u32 TIM_CR2;								/* Timer Control Register 2						*/
	volatile u32 TIM_SMCR;								/* Timer Slave Mode Control Register			*/
	volatile u32 TIM_DIER;								/* Timer DMA/Interrupt Enable Control Register	*/
	volatile u32 TIM_SR;								/* Timer Status Register						*/
	volatile u32 TIM_EGR;								/* Timer Event Generation Register				*/
	volatile u32 TIM_CCMR1;								/* Timer Capture/Compare Mode Register 1		*/
	volatile u32 TIM_CCMR2;								/* Timer Capture/Compare Mode Register 2		*/
	volatile u32 TIM_CCER;								/* Timer Capture/Compare Enable Register		*/
	volatile u32 TIM_CNT;								/* Timer Counter Register						*/
	volatile u32 TIM_PSC;								/* Timer Prescaler Register						*/
	volatile u32 TIM_ARR;								/* Timer Auto-reload Register					*/
	volatile u32 TIM_RCR;								/* Timer Repetition Counter Register			*/
	volatile u32 TIM_CCR[4];							/* Timer Capture/Compare Registers				*/
	volatile u32 TIM_BDTR;								/* Timer Break and Dead-time Register			*/
	volatile u32 TIM_DCR;								/* Timer DMA Control Register					*/
	volatile u32 TIM_DMAR;								/* Timer DMA address for full transfer Register	*/
	
}TIM_AC_TypeDef;										/* Advanced-Control Timers (TIM1) 				*/

typedef struct{
	
	volatile u32 TIM_CR1;								/* Timer Control Register 1						*/
	volatile u32 TIM_CR2;								/* Timer Control Register 2						*/
	volatile u32 TIM_SMCR;								/* Timer Slave Mode Control Register			*/
	volatile u32 TIM_DIER;								/* Timer DMA/Interrupt Enable Control Register	*/
	volatile u32 TIM_SR;								/* Timer Status Register						*/
	volatile u32 TIM_EGR;								/* Timer Event Generation Register				*/
	volatile u32 TIM_CCMR1;								/* Timer Capture/Compare Mode Register 1		*/
	volatile u32 TIM_CCMR2;								/* Timer Capture/Compare Mode Register 2		*/
	volatile u32 TIM_CCER;								/* Timer Capture/Compare Enable Register		*/
	volatile u32 TIM_CNT;								/* Timer Counter Register						*/
	volatile u32 TIM_PSC;								/* Timer Prescaler Register						*/
	volatile u32 TIM_ARR;								/* Timer Auto-reload Register					*/
	volatile u32 RESSRVED0;
	volatile u32 TIM_CCR[4];							/* Timer Capture/Compare Registers				*/
	volatile u32 RESSRVED1;
	volatile u32 TIM_DCR;								/* Timer DMA Control Register					*/
	volatile u32 TIM_DMAR;								/* Timer DMA address for full transfer Register	*/

}TIM_GP_TypeDef;										/* General Purpose Timers (TIM2 to TIM5)		*/

#define MTIM1 ((volatile TIM_AC_TypeDef *)0x40012C00)	/* Base address of Timer 1						*/

#define MTIM2 ((volatile TIM_GP_TypeDef *)0x40000000)	/* Base address of Timer 2						*/
#define MTIM3 ((volatile TIM_GP_TypeDef *)0x40000400)	/* Base address of Timer 3						*/
#define MTIM4 ((volatile TIM_GP_TypeDef *)0x40000800)	/* Base address of Timer 4						*/

/* Global variables */
void (* TIM_Callback[5])(void);

#endif	/* TIM_PRIVATE_H */
