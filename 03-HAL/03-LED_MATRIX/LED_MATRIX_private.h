/*******************************************************************/
/***********	Author	 :  Tarek Elmenshawy			************/
/***********	File Name:  LED_MATRIX_private.h		************/
/***********	Version	 :  V0.2						************/
/***********	Date	 :  5-10-2021					************/
/***********	Function :  LES_MATRIX Private Contents	************/
/*******************************************************************/

/********************************************************************/
/******		 Guard of file will call one time in .c file	   ******/
/********************************************************************/

#ifndef LED_MATRIX_PRIVATE_H
#define LED_MATRIX_PRIVATE_H

u8 LED_MATRIX_u8ColPins[LED_MATRIX_NUM_COLS][2] =
{
	{LED_MATRIX_COL0},
	{LED_MATRIX_COL1},
	{LED_MATRIX_COL2},
	{LED_MATRIX_COL3},
	{LED_MATRIX_COL4},
	{LED_MATRIX_COL5},
	{LED_MATRIX_COL6},
	{LED_MATRIX_COL7},
};

u8 LED_MATRIX_u8RowPins[LED_MATRIX_NUM_ROWS][2] =
{
	{LED_MATRIX_ROW0},
	{LED_MATRIX_ROW1},
	{LED_MATRIX_ROW2},
	{LED_MATRIX_ROW3},
	{LED_MATRIX_ROW4},
	{LED_MATRIX_ROW5},
	{LED_MATRIX_ROW6},
	{LED_MATRIX_ROW7},
};

/* Globle variables */
volatile u8 *LED_MATRIX_u8Frame;
volatile u8 LED_MATRIX_u8CurrentIndex;

#define LED_MATRIX_COL_CONTROL	1
#define LED_MATRIX_ROW_CONTROL	2

#define LED_MATRIX_ACTIVE_HIGH	3	
#define LED_MATRIX_ACTIVE_LOW	4

/* Fuction prototypes */
static void HLED_MATRIX_voidDisableAllLines(u8 Copy_u8LinePin[][2], u8 Copy_u8NumLines);
static void HLED_MATRIX_voidSetLineValue(u8 Copy_u8LinePin[][2], u8 Copy_u8NumLines, u8 Copy_u8Value);
static void HLED_MATRIX_voidDisplayNextLine(void);

#endif	/* LED_MATRIX_PRIVATE_H */
