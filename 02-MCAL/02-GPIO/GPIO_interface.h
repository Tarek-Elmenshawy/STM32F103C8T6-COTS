/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  GPIO_interface.h		***********/
/***********	Version	 :  V0.2					***********/
/***********	Date	 :  10-9-2021				***********/
/***********	Function :  GPIO Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef	GPIO_INTERFACE_H
#define	GPIO_INTERFACE_H


/* Types of GPIO PORTs */
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2


/* Output Constants */
#define GPIO_HIGH	1
#define GPIO_LOW	0


/* Indexes of PORT PINS */
#define	GPIO_PIN0	0
#define	GPIO_PIN1	1
#define	GPIO_PIN2	2
#define	GPIO_PIN3	3
#define	GPIO_PIN4	4
#define	GPIO_PIN5	5
#define	GPIO_PIN6	6
#define	GPIO_PIN7	7
#define	GPIO_PIN8	8
#define	GPIO_PIN9	9
#define	GPIO_PIN10	10
#define	GPIO_PIN11	11
#define	GPIO_PIN12	12
#define	GPIO_PIN13	13
#define	GPIO_PIN14	14
#define	GPIO_PIN15	15


/* Configurations for input mode */
#define	GPIO_INPUT_ADC			(0b0000)
#define	GPIO_INPUT_FLOATING		(0b0100)
#define	GPIO_INPUT_PULL_UP		(0b1000)
#define	GPIO_INPUT_PULL_DOWN	(0b1000)


/* Configurations for output speed 10 MHz */
#define	GPIO_OUTPUT_10MHZ_PP	(0b0001)
#define GPIO_OUTPUT_10MHZ_OD	(0b0101)
#define GPIO_OUTPUT_10MHZ_AF_PP	(0b1001)
#define GPIO_OUTPUT_10MHZ_AF_OD	(0b1101)


/* Configurations for output speed 2 MHz */
#define	GPIO_OUTPUT_2MHZ_PP		(0b0010)
#define GPIO_OUTPUT_2MHZ_OD		(0b0110)
#define GPIO_OUTPUT_2MHZ_AF_PP	(0b1010)
#define GPIO_OUTPUT_2MHZ_AF_OD	(0b1110)


/* Configurations for output speed 50 MHz */
#define	GPIO_OUTPUT_50MHZ_PP	(0b0011)			
#define GPIO_OUTPUT_50MHZ_OD	(0b0111)
#define GPIO_OUTPUT_50MHZ_AF_PP	(0b1011)
#define GPIO_OUTPUT_50MHZ_AF_OD	(0b1111)

/* Function Prototypes */
void MGPIO_voidSetPinDirection	(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);
u8	 MGPIO_voidLockPinDirection	(u8 Copy_u8PORT, u8 Copy_u8PIN);
void MGPIO_voidSetPinValue		(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value);
u8   MGPIO_voidGetPinValue		(u8 Copy_u8PORT, u8 Copy_u8PIN);
void MGPIO_voidTogglePinValue	(u8 Copy_u8PORT, u8 Copy_u8PIN);


#endif	/* GPIO_INTERFACE_H */
