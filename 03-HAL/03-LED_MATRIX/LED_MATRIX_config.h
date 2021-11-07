/*******************************************************************/
/***********	Author	 :  Tarek Elmenshawy			************/
/***********	File Name:  LED_MATRIX_config.h			************/
/***********	Version	 :  V0.1						************/
/***********	Date	 :  5-10-2021					************/
/***********	Function :  LES_MATRIX Config Handler	************/
/*******************************************************************/

/*******************************************************************/
/******		 Guard of file will call one time in .c file	  ******/
/*******************************************************************/

#ifndef LED_MATRIX_CONFIG_H
#define LED_MATRIX_CONFIG_H

#define LED_MATRIX_NUM_COLS			8
#define LED_MATRIX_NUM_ROWS			8

#define LED_MATRIX_COL0				GPIOA,0
#define LED_MATRIX_COL1				GPIOA,1
#define LED_MATRIX_COL2				GPIOA,2
#define LED_MATRIX_COL3				GPIOA,3
#define LED_MATRIX_COL4				GPIOA,4
#define LED_MATRIX_COL5				GPIOA,5
#define LED_MATRIX_COL6				GPIOA,6
#define LED_MATRIX_COL7				GPIOA,7

#define LED_MATRIX_ROW0				GPIOB,0
#define LED_MATRIX_ROW1				GPIOB,1
#define LED_MATRIX_ROW2				GPIOB,5
#define LED_MATRIX_ROW3				GPIOB,6
#define LED_MATRIX_ROW4				GPIOB,7
#define LED_MATRIX_ROW5				GPIOB,8
#define LED_MATRIX_ROW6				GPIOB,9
#define LED_MATRIX_ROW7				GPIOB,10

/********************************************************************/
/*																	*/
/*			Operation Mode:											*/
/*							1-LED_MATRIX_COL_CONTROL				*/
/*							2-LED_MATRIX_ROW_CONTROL				*/
/*																	*/
/********************************************************************/
#define LED_MATRIX_OPERATION_MODE	LED_MATRIX_COL_CONTROL

/********************************************************************/
/*																	*/
/*			Operation Control Mode:									*/
/*							1-LED_MATRIX_ACTIVE_HIGH				*/
/*							2-LED_MATRIX_ACTIVE_LOW					*/
/*																	*/
/********************************************************************/
#define LED_MATRIX_CONTROL_MODE		LED_MATRIX_ACTIVE_LOW


#endif	/* LED_MATRIX_CONFIG_H */
