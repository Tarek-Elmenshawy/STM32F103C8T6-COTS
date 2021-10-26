/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  NVIC_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  23-10-2021				***********/
/***********	Function :  NVIC Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct{
	
	volatile u32 NVIC_ISER[32];						/* Interrupt Set Enable Registers 					*/
	volatile u32 NVIC_ICER[32];						/* Interrupt Clear Enable Registers 				*/
	volatile u32 NVIC_ISPR[32];						/* Interrupt Set Pending Registers 					*/
	volatile u32 NVIC_ICPR[32];						/* Interrupt Clear Pending Registers				*/
	volatile u32 NVIC_IABR[32];						/* Interrupt Active Bit Registers 					*/
	volatile u32 RESERVED [32];						/* Reserved											*/
	volatile u8  NVIC_IPR[128];						/* Interrupt Priority Registers 					*/
	
}NVIC_TYPE;

#define MNVIC  ((volatile NVIC_TYPE *)0xE000E100)	/* Base Address of NVIC				 				*/
#define MNVIC_STIR 	((volatile u32  *)0xE000EF00)	/* Address of Software trigger Interrupt Register	*/

typedef struct{
	
	volatile u32 SNC_ACTLR;							/* Auxiliary Control Register						*/
	volatile u32 SCB_CPIID;							/* CPUID BAse Register								*/
	volatile u32 SCB_ICSR;							/* Interrupt Control and State Register				*/
	volatile u32 SCB_VTOR;							/* Vector TAble Offset Register						*/
	volatile u32 SCB_AIRCR;							/* Application Interrupt and Reset Control Register	*/
	volatile u32 SCB_SCR;							/* System Contorl Register							*/
	volatile u32 SCB_CCR;							/* Configuration and Control Register				*/
	volatile u8  SCB_SHPR[12];						/* System Handler Priority Registers				*/
	volatile u32 SCB_SHCSR;							/* System Handler Control and State Register		*/
	volatile u32 SCB_CFSR;							/* Configurable Fault Status Register				*/
	volatile u32 SCB_HFSR;							/* Hard Fault status Register						*/
	volatile u32 SCB_MMFAR;							/* Memory Management Fault Address Register			*/
	volatile u32 SCB_BFAR;							/* Bus Fault Address Register						*/
	
}SCB_TYPE;

#define MSCB ((volatile SCB_TYPE *)0xE000ED00)		/* Base Address of SCB								*/

#endif	/* NVIC_PRIVATE_H */
