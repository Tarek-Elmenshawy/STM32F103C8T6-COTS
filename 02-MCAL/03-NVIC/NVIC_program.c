/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  NVIC_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  23-10-2021				***********/
/***********	Function :  NVIC Handler			***********/
/**************************************************************/

/* Includes libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include NVIC driver header files */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID)
{
	/* The index of ISER (RANK) by [Copy_u8InterruptID / number of register bits] */
	/* The index of peripheral bit (FILE) by [Copy_u8InterruptID % number of register bits] */
	MNVIC->NVIC_ISER[Copy_u8InterruptID / 32] = (1 << (Copy_u8InterruptID % 32)); 
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptID)
{
	/* The index of ICER (RANK) by [Copy_u8InterruptID / number of register bits] */
	/* The index of peripheral bit (FILE) by [Copy_u8InterruptID % number of register bits] */
	MNVIC->NVIC_ICER[Copy_u8InterruptID / 32] = (1 << (Copy_u8InterruptID % 32)); 
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	/* The index of ISPR (RANK) by [Copy_u8InterruptID / number of register bits] */
	/* The index of peripheral bit (FILE) by [Copy_u8InterruptID % number of register bits] */
	MNVIC->NVIC_ISPR[Copy_u8InterruptID / 32] = (1 << (Copy_u8InterruptID % 32)); 
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	/* The index of ICPR (RANK) by [Copy_u8InterruptID / number of register bits] */
	/* The index of peripheral bit (FILE) by [Copy_u8InterruptID % number of register bits] */
	MNVIC->NVIC_ICPR[Copy_u8InterruptID / 32] = (1 << (Copy_u8InterruptID % 32)); 
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID)
{
	/* The index of IABR (RANK) by [Copy_u8InterruptID / number of register bits] */
	/* The index of peripheral bit (FILE) by [Copy_u8InterruptID % number of register bits] */
	u8 Local_u8Flag = GET_BIT(MNVIC->NVIC_IABR[Copy_u8InterruptID / 32], Copy_u8InterruptID % 32); 
	
	/* Return active flag */
	return Local_u8Flag;
}

