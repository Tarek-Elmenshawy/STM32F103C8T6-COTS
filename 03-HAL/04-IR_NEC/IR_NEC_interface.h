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

#define IR_NEC_PREV_CH_BUTTON		69
#define IR_NEC_NEXT_CH_BUTTON		71
#define IR_NEC_CH_BUTTON			70

#define IR_NEC_NEXT_BUTTON			64
#define IR_NEC_PREV_BUTTON			68
#define IR_NEC_PLAY_PAUSE_BUTTON	67

#define IR_NEC_VOL_UP_BUTTON		21
#define IR_NEC_VOL_DOWN_BUTTON		7
#define IR_NEC_EQ_BUTTON			9

#define IR_NEC_FOL_UP_BUTTON		13
#define IR_NEC_FOL_DOWN_BUTTON		25
	
#define IR_NEC_0_BUTTON				22
#define IR_NEC_1_BUTTON				12
#define IR_NEC_2_BUTTON				24
#define IR_NEC_3_BUTTON				94
#define IR_NEC_4_BUTTON				8
#define IR_NEC_5_BUTTON				28
#define IR_NEC_6_BUTTON				90
#define IR_NEC_7_BUTTON				66
#define IR_NEC_8_BUTTON				82
#define IR_NEC_9_BUTTON				74

/* Function prototypes */
void HIR_NEC_voidInit(void (*Copy_ptr)(u8 Copy_u8IRAddress, u8 Copy_u8IRCommand));
void HIR_NEC_voidEnable(void);
void HIR_NEC_voidDisable(void);

#endif	/* IR_NEC_INTERFACE_H */
