/****************************************************************/
/***********     Author    :  Tarek Elmenshawy        ***********/
/***********     File Name :  RCC_interface.h         ***********/
/***********     Version   :  V0.2                    ***********/
/***********     Date      :  08-9-2021               ***********/
/***********     Function  :  RCC Public Contents	  ***********/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/****************************************************************/
/*																*/
/*			Bus Types:											*/
/*					1- RCC_AHB_BUS								*/
/*					2- RCC_APB1_BUS								*/
/*					3- RCC_APB1_BUS								*/
/*																*/
/****************************************************************/
#define RCC_AHB_BUS		0
#define RCC_APB1_BUS	1
#define RCC_APB2_BUS	2

/****************************************************************/
/*																*/
/* 			Peripheral Clock Enable For AHB Bus: 				*/
/*					1- RCC_DMA1									*/
/*					2- RCC_DMA2									*/
/*					3- RCC_SRAM									*/
/*					4- RCC_FLITF								*/
/*					5- RCC_CRC									*/
/*					6- RCC_FSMC									*/
/*					7- RCC_SDIO									*/
/*																*/
/****************************************************************/
#define RCC_DMA1	0
#define RCC_DMA2	1
#define RCC_SRAM	2
#define RCC_FLITF	4
#define RCC_CRC		6
#define RCC_FSMC	8
#define RCC_SDIO	10

/****************************************************************/
/*																*/
/*			Peripheral Clock Enable For APB2 Bus:				*/
/*					1- RCC_AFIO									*/
/*					2- RCC_IOPA									*/
/*					3- RCC_IOPB									*/
/*					4- RCC_IOPC									*/
/*					5- RCC_IOPD									*/
/*					6- RCC_IOPE									*/
/*					7- RCC_IOPF									*/
/*					8- RCC_IOPG									*/
/*					9- RCC_ADC1									*/
/*					10- RCC_ADC2								*/
/*					11- RCC_TIM1								*/
/*					12- RCC_SPI1								*/
/*					13- RCC_TIM8								*/
/*					14- RCC_USART1								*/
/*					15- RCC_ADC3								*/
/*					16- RCC_TIM9								*/
/*					17- RCC_TIM10								*/
/*					18- RCC_TIM11								*/
/*																*/
/****************************************************************/
#define RCC_AFIO	0
#define RCC_IOPA	2
#define RCC_IOPB	3
#define RCC_IOPC	4
#define RCC_IOPD	5
#define RCC_IOPE	6
#define RCC_IOPF	7
#define RCC_IOPG	8
#define RCC_ADC1	9
#define RCC_ADC2	10
#define RCC_TIM1	11
#define RCC_SPI1	12
#define RCC_TIM8	13
#define RCC_USART1	14
#define RCC_ADC3	15
#define RCC_TIM9	19
#define RCC_TIM10	20
#define RCC_TIM11	21

/****************************************************************/
/*																*/
/*			Peripheral Clock Enable For APB1 Bus:				*/
/*					1- RCC_TIM2									*/
/*					2- RCC_TIM3									*/
/*					3- RCC_TIM4									*/
/*					4- RCC_TIM5									*/
/*					5- RCC_TIM6									*/
/*					6- RCC_TIM7									*/
/*					7- RCC_TIM12								*/
/*					8- RCC_TIM13								*/
/*					9- RCC_TIM14								*/
/*					10- RCC_WWDG								*/
/*					11- RCC_SPI2								*/
/*					12- RCC_SPI3								*/
/*					13- RCC_USART2								*/
/*					14- RCC_USART3								*/
/*					15- RCC_UART4								*/
/*					16- RCC_UART5								*/
/*					17- RCC_I2C1								*/
/*					18- RCC_I2C2								*/
/*					19- RCC_USB									*/
/*					20- RCC_CAN 								*/
/*					21- RCC_BKP									*/
/*					22- RCC_PWR									*/
/*					23- RCC_DAC									*/
/*																*/
/****************************************************************/
#define RCC_TIM2	0
#define RCC_TIM3	1
#define RCC_TIM4	2
#define RCC_TIM5	3
#define RCC_TIM6	4
#define RCC_TIM7	5
#define RCC_TIM12	6
#define RCC_TIM13	7
#define RCC_TIM14	8
#define RCC_WWDG	11
#define RCC_SPI2	14
#define RCC_SPI3	15
#define RCC_USART2	17
#define RCC_USART3	18
#define RCC_UART4	19
#define RCC_UART5	20
#define RCC_I2C1	21
#define RCC_I2C2	22
#define RCC_USB		23
#define RCC_CAN 	25
#define RCC_BKP		27
#define RCC_PWR		28
#define RCC_DAC		29


void MRCC_voidInitSysClock(void);

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
