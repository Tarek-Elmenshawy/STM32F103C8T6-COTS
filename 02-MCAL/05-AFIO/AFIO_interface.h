/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  AFIO_interface.h		***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  AFIO Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define AFIO_PA	 (0b0000)	/* Port A as source input for EXTI */
#define AFIO_PB	 (0b0001)	/* Port B as source input for EXTI */
#define AFIO_PC	 (0b0010)	/* Port C as source input for EXTI */
#define AFIO_PD	 (0b0011)	/* Port D as source input for EXTI */
#define AFIO_PE	 (0b0100)	/* Port E as source input for EXTI */
#define AFIO_PF	 (0b0101)	/* Port F as source input for EXTI */
#define AFIO_PG	 (0b0110)	/* Port G as source input for EXTI */

/* Function Prototypes */
void MAFIO_voidSetEXTIConfig(u8 Copy_u8EXTILine, u8 Copy_u8PortMap);


#endif	/* AFIO_INTERFACE_H */