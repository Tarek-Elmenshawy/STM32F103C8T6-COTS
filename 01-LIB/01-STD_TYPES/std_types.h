/****************************************************************/
/***********     Author    :  Tarek Elmenshawy       ************/
/***********     File Name :  std_types.h            ************/
/***********     Version   :  V0.1                   ************/
/***********     Date      :  07-9-2021              ************/
/***********     Function  :  Standar Data Types     ************/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char      u8 ;	/*					   0 ... 255			*/
typedef unsigned short int u16;	/*					   0 ... 65,535			*/
typedef unsigned long  int u32;	/*					   0 ... 4,294,967,295	*/

typedef char      		   s8 ;	/*			  -128 ... 0 ... 172			*/
typedef short int 		   s16;	/*		   -32,768 ... 0 ... 32,767			*/
typedef long int  		   s32;	/*	-2,147,483,648 ... 0 ... 2,147,483,647	*/

#endif