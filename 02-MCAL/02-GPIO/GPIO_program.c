/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  GPIO_program.c			***********/
/***********	Version	 :  V0.2					***********/
/***********	Date	 :  10-9-2021				***********/
/***********	Function :  GPIO Handler			***********/
/**************************************************************/

/* Include Libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include GPIO Driver Header Files */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
	/* Select PORT */
	switch(Copy_u8PORT)
	{
		case GPIOA	:
			if(Copy_u8PIN <= 7)
			{
				MGPIOA->GPIO_CRL &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOA->GPIO_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			else if(Copy_u8PIN <= 15)
			{
				/* Subtract 8 from Copy_u8PIN to return to register scale (PIN[0 : 7]) */
				Copy_u8PIN  -= 8;
				MGPIOA->GPIO_CRH &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOA->GPIO_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			break;
		
		case GPIOB	:
			if(Copy_u8PIN <= 7)
			{
				MGPIOB->GPIO_CRL &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOB->GPIO_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			else if(Copy_u8PIN <= 15)
			{
				/* Subtract 8 from Copy_u8PIN to return to register scale (PIN[0 : 7]) */
				Copy_u8PIN  -= 8;
				MGPIOB->GPIO_CRH &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOB->GPIO_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			break;
		
		case GPIOC	:
			if(Copy_u8PIN <= 7)
			{
				MGPIOC->GPIO_CRL &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOC->GPIO_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			else if(Copy_u8PIN <= 15)
			{
				/* Subtract 8 from Copy_u8PIN to return to register scale (PIN[0 : 7]) */
				Copy_u8PIN -= 8;
				MGPIOC->GPIO_CRH &= ~((0b111) << (Copy_u8PIN * 4));			// Reset MODE and CNF bits
				MGPIOC->GPIO_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4));	// Set MODE and CNF according to Copy_u8Mode
			}
			break;
	}
}

u8 MGPIO_voidLockPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN)
{	
	u8 Local_u8LockFlag = 0;
	
	/* Select PORT */
	switch(Copy_u8PORT)
	{
		case GPIOA	:
			/* Lock Configuration PIN in PORTA */
			SET_BIT(MGPIOA->GPIO_LCKR, Copy_u8PIN);
			
			/* Lock Key Writing Sequence */
			SET_BIT(MGPIOA->GPIO_LCKR, GPIO_LCKK);
			CLR_BIT(MGPIOA->GPIO_LCKR, GPIO_LCKK);
			SET_BIT(MGPIOA->GPIO_LCKR, GPIO_LCKK);
			
			if(GET_BIT(MGPIOA->GPIO_LCKR, GPIO_LCKK) == 0)
			{
				if(GET_BIT(MGPIOA->GPIO_LCKR, GPIO_LCKK) == 1)
				{	
					/* Configuration Lock is activated */
					Local_u8LockFlag = 1;
				}
			}
			break;
			
		case GPIOB	:
			/* Lock Configuration PIN in PORTB */
			SET_BIT(MGPIOB->GPIO_LCKR, Copy_u8PIN);
			
			/* Lock Key Writing Sequence */
			SET_BIT(MGPIOB->GPIO_LCKR, GPIO_LCKK);
			CLR_BIT(MGPIOB->GPIO_LCKR, GPIO_LCKK);
			SET_BIT(MGPIOB->GPIO_LCKR, GPIO_LCKK);
			
			if(GET_BIT(MGPIOB->GPIO_LCKR, GPIO_LCKK) == 0)
			{
				if(GET_BIT(MGPIOB->GPIO_LCKR, GPIO_LCKK) == 1)
				{	
					/* Configuration Lock is activated */
					Local_u8LockFlag = 1;
				}
			}
			break;
			
		case GPIOC	:
			/* Lock Configuration PIN in PORTC */
			SET_BIT(MGPIOC->GPIO_LCKR, Copy_u8PIN);
			
			/* Lock Key Writing Sequence */
			SET_BIT(MGPIOC->GPIO_LCKR, GPIO_LCKK);
			CLR_BIT(MGPIOC->GPIO_LCKR, GPIO_LCKK);
			SET_BIT(MGPIOC->GPIO_LCKR, GPIO_LCKK);
			
			if(GET_BIT(MGPIOC->GPIO_LCKR, GPIO_LCKK) == 0)
			{
				if(GET_BIT(MGPIOC->GPIO_LCKR, GPIO_LCKK) == 1)
				{	
					/* Configuration Lock is activated */
					Local_u8LockFlag = 1;
				}
			}
	}
	
	/* Return Lock Flag */
	return Local_u8LockFlag;
}


void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{	
	/* Select PORT */
	switch(Copy_u8PORT)
	{
		case GPIOA	:
			/* Set PIN value according to Copy_u8Value */
			#if GPIO_OPTOMISATION_STATUS == GPIO_ENABLE_OPTOMISATION
			
				if(Copy_u8Value) SET_BIT(MGPIOA->GPIO_ODR, Copy_u8PIN);
				else CLR_BIT(MGPIOA->GPIO_ODR, Copy_u8PIN);
				
			#elif GPIO_OPTOMISATION_STATUS == GPIO_DISABLE_OPTOMISATION
				
				/* 
				 *	Using BERR and BRR registers consumes number of instructions
				 *	fewer than using ODR register, so BSRR and BRR registers provides
				 *	high performance.
				 */
				if(Copy_u8Value) MGPIOA->GPIO_BSRR = (1 << Copy_u8PIN);
				else MGPIOA->GPIO_BRR = (1 << Copy_u8PIN);
				
			#else
				#error("Wrong optimization configuration")
			#endif
			break;
			
		case GPIOB	:
			/* Set PIN value according to Copy_u8Value */
			#if GPIO_OPTOMISATION_STATUS == GPIO_ENABLE_OPTOMISATION
			
				if(Copy_u8Value) SET_BIT(MGPIOB->GPIO_ODR, Copy_u8PIN);
				else CLR_BIT(MGPIOB->GPIO_ODR, Copy_u8PIN);
				
			#elif GPIO_OPTOMISATION_STATUS == GPIO_DISABLE_OPTOMISATION
				
				/* 
				 *	Using BERR and BRR registers consumes number of instructions
				 *	fewer than using ODR register, so BSRR and BRR registers provides
				 *	high performance.
				 */
				if(Copy_u8Value) MGPIOB->GPIO_BSRR = (1 << Copy_u8PIN);
				else MGPIOB->GPIO_BRR = (1 << Copy_u8PIN);
				
			#else
				#error("Wrong optimization configuration")
			#endif
			break;
			
		case GPIOC	:
			/* Set PIN value according to Copy_u8Value */
			#if GPIO_OPTOMISATION_STATUS == GPIO_ENABLE_OPTOMISATION
			
				if(Copy_u8Value) SET_BIT(MGPIOC->GPIO_ODR, Copy_u8PIN);
				else CLR_BIT(MGPIOC->GPIO_ODR, Copy_u8PIN);
				
			#elif GPIO_OPTOMISATION_STATUS == GPIO_DISABLE_OPTOMISATION
				
				/* 
				 *	Using BERR and BRR regidters consumes number of instructions 
				 *	fewer than using ODR register, so BSRR and BRR registers provides
				 *	high performance.
				 */
				if(Copy_u8Value) MGPIOC->GPIO_BSRR = (1 << Copy_u8PIN);
				else MGPIOC->GPIO_BRR = (1 << Copy_u8PIN);
				
			#else
				#error("Wrong optimization configuration")
			#endif
			break;
	}
}


u8 MGPIO_voidGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 Local_u8Value = 0;
	
	/* Select PORT then read PIN value */
	switch(Copy_u8PORT)
	{
		case GPIOA	:	Local_u8Value = GET_BIT(MGPIOA->GPIO_IDR, Copy_u8PIN);	break;
		case GPIOB	:	Local_u8Value = GET_BIT(MGPIOB->GPIO_IDR, Copy_u8PIN);	break;
		case GPIOC	:	Local_u8Value = GET_BIT(MGPIOC->GPIO_IDR, Copy_u8PIN);	break;
	}
	
	/* Return PIN value */
	return Local_u8Value;
}


void MGPIO_voidTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	/* Select PORT then toggle Pin value*/
	switch(Copy_u8PORT)
	{
		case GPIOA	:	TOG_BIT(MGPIOA->GPIO_ODR, Copy_u8PIN);	break;
		case GPIOB	:	TOG_BIT(MGPIOB->GPIO_ODR, Copy_u8PIN);	break;
		case GPIOC	:	TOG_BIT(MGPIOC->GPIO_ODR, Copy_u8PIN);	break;
	}
}
