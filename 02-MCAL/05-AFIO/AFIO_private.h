/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  AFIO_private.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  26-10-2021				***********/
/***********	Function :  AFIO Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef AFIO_PRIVATE_H
#define	AFIO_PRIVATE_H

typedef struct{
	
	volatile u32 AFIO_EVCR;			/* Event Control Register 						*/
	volatile u32 AFIO_MAPR;			/* AF Remap and Debug Configuration Register 	*/
	volatile u32 AFIO_EXTICR[5];	/* external Interrupt Configuration Register 	*/
	volatile u32 AFIO_MAPR2;		/* AF Remap and Debug Configuration Register2	*/
	
}AFIO_TypeDef;

#define MAFIO ((volatile AFIO_TypeDef *)0x40010000)	/* Base address of AFIO			*/


#endif	/* AFIO_PRIVATE_H */