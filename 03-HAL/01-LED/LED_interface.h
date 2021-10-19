/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  LED_interface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  19-10-2021				***********/
/***********	Function :  LED Public Contents		***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/* Functions Prototypes */
void LED_voidInitLed	(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidLedON		(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidLedOFF		(u8 Copy_u8PORT, u8 Copy_u8PIN);
void LED_voidLedToggel	(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif /* LED_INTERFACE_H */