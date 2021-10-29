/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  AFIO_program.c			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  AFIO Handler			***********/
/**************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include AFIO driver header files */
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfig(u8 Copy_u8EXTILine, u8 Copy_u8PortMap)
{
	/* The index of EXTICR (RANK) by [Copy_u8EXTILine / number of EXTI per register] */
	/* The offset (FILE * 4) : file = [Copy_u8EXTILine % number of EXTI per register]] */
	MAFIO->AFIO_EXTICR[Copy_u8EXTILine / 4] &= ~((0b1111) << ((Copy_u8EXTILine % 4) * 4));
	MAFIO->AFIO_EXTICR[Copy_u8EXTILine / 4] |=  ((Copy_u8PortMap) << ((Copy_u8EXTILine % 4) * 4));
}
