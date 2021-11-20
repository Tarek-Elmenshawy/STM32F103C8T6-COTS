/********************************************************************/
/***********	Author	 :  Tarek Elmenshawy			*************/
/***********	File Name:  DAC_private.h				*************/
/***********	Version	 :  V0.1						*************/
/***********	Date	 :  19-11-2021					*************/
/***********	Function :  DAC Private Contents		*************/
/********************************************************************/

/********************************************************************/
/******		 Guard of file will call one time in .c file	   ******/
/********************************************************************/

#ifndef DAC_PRIVATE_H
#define DAC_PRIVATE_H

const u8 HDAC_Pin[DAC_RESOLUTION][2] =
{
	{DAC_BIT0_PIN},
	{DAC_BIT1_PIN},
	{DAC_BIT2_PIN},
	{DAC_BIT3_PIN},
	{DAC_BIT4_PIN},
	{DAC_BIT5_PIN},
	{DAC_BIT6_PIN},
	{DAC_BIT7_PIN},
};

volatile u16 HDAC_u16Counter = 0;

static void HDAC_Handler(void);

#endif	/* DAC_PRIVATE_H */
