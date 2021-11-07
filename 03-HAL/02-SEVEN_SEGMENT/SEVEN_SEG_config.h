/****************************************************************/
/***********	Author	 :  Tarek Elmenshawy		*************/
/***********	File Name:  SEVEN_SEG_config.h		*************/
/***********	Version	 :  V0.1					*************/
/***********	Date	 :  19-10-2021				*************/
/***********	Function :  7 Seg. Config Handler	*************/
/****************************************************************/

/****************************************************************/
/***	  Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef SEVEN_SEG_CONFIG_H
#define SEVEN_SEG_CONFIG_H

/****************************************************************/
/*																*/
/*		Seven Segmrnt Type:										*/
/*							1- SEVEN_SEG_COMMON_ANODE			*/
/*							2- SEVEN_SEG_COMMON_CATHODE			*/
/*																*/
/****************************************************************/
#define SEVEN_SEG_TYPE	SEVEN_SEG_COMMON_CATHODE


/****************************************************************/
/*																*/
/*					PORTs:										*/
/*							1- GPIOA							*/
/*							2- GPIOB							*/
/*																*/
/****************************************************************/
#define SEVEN_SEG_PORT	GPIOA

/* Select PORT PINs (0 : 15) */
#define SEVEN_SEG_PINA	0
#define SEVEN_SEG_PINB	1
#define SEVEN_SEG_PINC	2
#define SEVEN_SEG_PIND	3
#define SEVEN_SEG_PINE	4
#define SEVEN_SEG_PINF	5
#define SEVEN_SEG_PING	6
#define SEVEN_SEG_PINH	7

#endif	/* SEVEN_SEG_CONFIG_H */