/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  GPIO_private.h			***********/
/***********	Version  :  V0.2					***********/
/***********	Date	 :  10-9-2021				***********/
/***********	Function :  GPIO Private Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef	GPIO_PRIVATE_H
#define	GPIO_PRIVATE_H

typedef struct{
	volatile u32 GPIO_CRL;						/* Port Configuration Register Low 	*/
	volatile u32 GPIO_CRH;						/* Port Configuration Register HIGH */
	volatile u32 GPIO_IDR;						/* Port Input Data Register 		*/
	volatile u32 GPIO_ODR;						/* Port Output Data Register 		*/
	volatile u32 GPIO_BSRR;						/* Port Bit Set Reset Register 		*/
	volatile u32 GPIO_BRR;						/* Port Bit Reset Register 			*/
	volatile u32 GPIO_LCKR;						/* Port Configuration Register 		*/
}GPIO;


#define	GPIO_LCKK	16							/* Lock Key: Bit 16 in LCKR			*/

#define	MGPIOA	((volatile GPIO *)0x40010800)	/* Base Address of GPIOA 			*/
#define	MGPIOB	((volatile GPIO *)0x40010C00)	/* Base Address of GPIOB 			*/
#define	MGPIOC	((volatile GPIO *)0x40011000)	/* Base Address of GPIOC 			*/



#endif	/* GPIO_PRIVATE_H */