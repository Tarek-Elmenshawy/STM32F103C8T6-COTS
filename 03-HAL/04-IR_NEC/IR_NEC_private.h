/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  IR_NEC_private.h		***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  15-11-2021				***********/
/***********	Function :  IR_NEC Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef IR_NEC_PRIVATE_H
#define IR_NEC_PRIVATE_H

/* Global callback function pointer */
void (*HIR_NEC_Callback)(u8 Copy_u8IRAddress, u8 Copy_u8IRCommand);

/* Global variables */
volatile u32 HIR_NEC_u32FrameData 	  = 0;
volatile u32 HIR_NEC_u32FrameTime[50] = {0};
volatile u16 HIR_NEC_u16EdgeCounter   = 0;
volatile u8  HIR_NEC_u8StartFlag 	  = 0;

/* Function prototypes */
static void voidGetFrame(void);
static void voidAnalyseFrame(void);


#endif	/* IR_NEC_PRIVATE_H */
