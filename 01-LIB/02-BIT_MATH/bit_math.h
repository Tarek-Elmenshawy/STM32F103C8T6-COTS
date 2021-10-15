/***************************************************************/
/***********     Author    :  Tarek Elmenshawy       ***********/
/***********     File Name :  bit_math.h             ***********/
/***********     Version   :  V0.1                   ***********/
/***********     Date      :  07-9-2021              ***********/
/***********     Function  :  Bit Operations   		 ***********/
/***************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT)	(VAR |=  (1 << (BIT)))
#define CLR_BIT(VAR, BIT)	(VAR &= ~(1 << (BIT)))
#define GET_BIT(VAR, BIT)	(((VAR) >> (BIT)) & 1)
#define TOG_BIT(VAR, BIT)	(VAR ^=  (1 << (BIT)))

#endif
