/****************************************************************/
/***********	Author	 :  Tarek Elmenshawy		 ************/
/***********	File Name:  OS_private.h			 ************/
/***********	Version	 :  V0.1					 ************/
/***********	Date	 :  15-11-2021				 ************/
/***********	Function :  OS Private Contents		 ************/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct{
	
	u16 u16Periodicity;
	u8	u8FirstDelay;
	u8	u8State;
	
	void (*TaskCall)(void);
	
}TASK_TypeDef;

TASK_TypeDef Task[OS_NUMBER_OF_TASKS];

#define NULL				((void*)0)

#define OS_STAET_NONE		0
#define OS_STATE_READY		1
#define OS_STATE_RUNNING	2
#define OS_STATE_SUSPENDED	3
#define OS_STATE_BLOCKED	4

#endif	/* OS_PRIVATE_H */