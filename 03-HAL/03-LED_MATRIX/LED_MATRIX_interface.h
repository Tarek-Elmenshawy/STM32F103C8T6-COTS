/*******************************************************************/
/***********	Author	 :  Tarek Elmenshawy			************/
/***********	File Name:  LED_MATRIX_interface.h		************/
/***********	Version	 :  V0.1						************/
/***********	Date	 :  5-10-2021					************/
/***********	Function :  LES_MATRIX Public Contents	************/
/*******************************************************************/

/********************************************************************/
/******		 Guard of file will call one time in .c file	   ******/
/********************************************************************/

#ifndef LED_MATRIX_INTERFACE_H
#define LED_MATRIX_INTERFACE_H

/* Function prototypes */
void HLEDMATRIX_voidInit(void);
void HLEDMATRIX_voidDisplayFrame(u8 *Copy_u8Frame);

#endif	/* LED_MATRIX_INTERFACE_H */