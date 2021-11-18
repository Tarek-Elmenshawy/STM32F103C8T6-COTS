/****************************************************************/
/***********	Author	 :  Tarek Elmenshawy		 ************/
/***********	File Name:  OS_interface.h			 ************/
/***********	Version	 :  V0.1					 ************/
/***********	Date	 :  15-11-2021				 ************/
/***********	Function :  OS Public Contents		 ************/
/****************************************************************/

/****************************************************************/
/***	   Guard of file will call one time in .c file		  ***/
/****************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16TaskPeriodicity, u8 Copy_u8FirstDelay, void (*Copy_TaskCall)(void));
void OS_voidStart(void);
void OS_voidKillTask(u8 Copy_u8TaskID);
void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);

#endif	/* OS_INTERFACE_H */