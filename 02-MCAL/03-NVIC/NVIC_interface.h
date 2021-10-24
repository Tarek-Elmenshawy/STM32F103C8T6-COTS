/**************************************************************/
/***********	Author	 :  Tarek Elmenshawy		***********/
/***********	File Name:  NVIC_inteface.h			***********/
/***********	Version	 :  V0.1					***********/
/***********	Date	 :  23-10-2021				***********/
/***********	Function :  NVIC Public Contents	***********/
/**************************************************************/

/**************************************************************/
/***	  Guard of file will call one time in .c file		***/
/**************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define NVIC_GROUP16_SUB0	(0x05FA0300)	/* 4 bits for group priorities, 0 bits for subpriorities */
#define NVIC_GROUP8_SUB2 	(0x05FA0400)	/* 3 bits for group priorities, 1 bits for subpriorities */
#define NVIC_GROUP4_SUB4 	(0x05FA0500)	/* 2 bits for group priorities, 2 bits for subpriorities */
#define NVIC_GROUP2_SUB8 	(0x05FA0600)	/* 1 bits for group priorities, 3 bits for subpriorities */
#define NVIC_GROUP0_SUB16 	(0x05FA0700)	/* 0 bits for group priorities, 4 bits for subpriorities */

////////////////////////////////////////////////////////////////
/* SCB_SHPR1 */
#define NVIC_MEM_MANAGE		-12				/* Memory management 						*/
#define NVIC_BUS_FAULT		-11				/* Prefetch fault, memory access fault 		*/
#definr NVIC_USAGE_FAULT	-10				/* Undefined instruction or illegal state 	*/
////////////////////////////////////////////////////////////////
/* SCB_SHPR2 */
#define NIVC_SV_CALL		-5				/* System service call via SWI instruction	*/
////////////////////////////////////////////////////////////////
/* SCB_SHPR3 */
#define NVIC_PEN_SV			-2				/* Pendable request for system service 		*/
#define NVIC_SYS_TICK		-1				/* System tick timer 						*/
////////////////////////////////////////////////////////////////

/* Function Prototypes */
void MNVIC_voidEnableInterrupt	(u8 Copy_u8InterruptID);
void MNVIC_voidDisableInterrupt	(u8 Copy_u8InterruptID);
void MNVIC_voidSetPendingFlag	(u8 Copy_u8InterruptID);
void MNVIC_voidClearPendingFlag	(u8 Copy_u8InterruptID);
u8	 MNVIC_u8GetActiveFlag		(u8 Copy_u8InterruptID);
void MNVIC_voidSetPriority		(s8 Copy_u8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_GroupControl);

#endif	/* NVIC_INTERFACE_H */