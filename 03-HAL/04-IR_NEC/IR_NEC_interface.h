/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  IR_NEC_interface.h		***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  15-11-2021				***********/
/***********	Function :  IR_NEC Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef IR_NEC_INTERFACE_H
#define IR_NEC_INTERFACE_H

/* Function prototypes */
void HIR_NEC_voidInit(void (*Copy_ptr)(u8 Copy_u8IRAddress, u8 Copy_u8IRCommand));
void HIR_NEC_voidEnable(void);
void HIR_NEC_voidDisable(void);

#endif	/* IR_NEC_INTERFACE_H */
