/****************************************************************/
/***********	Author	 :  Tarek Elmenshawy		 ************/
/***********	File Name:  OS_program.c			 ************/
/***********	Version	 :  V0.1					 ************/
/***********	Date	 :  15-11-2021				 ************/
/***********	Function :  OS Handler				 ************/
/****************************************************************/

/* Include libraries */
#include "std_types.h"
#include "bit_math.h"

/* Include interface files of lower layers */
#include "STK_interface.h"

/* Include OS driver header files */
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

void OS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16TaskPeriodicity, u8 Copy_u8FirstDelay, void (*Copy_TaskCall)(void));
{
	Task[Copy_u8TaskID].u16Periodicity 	= Copy_u16TaskPeriodicity - 1;	/* Set task periodicity */
	Task[Copy_u8TaskID].u8FirstDelay 	= Copy_u8FirstDelay;			/* Set task first delay */
	Task[Copy_u8TaskID].TaskCall 		= Copy_TaskCall;				/* Set task callback */
	Task[Copy_u8TaskID].u8State			= OS_STATE_READY;				/* Set task state as ready */
}

void OS_voidStart(void)
{
	/* Start periodic interval of period 1 mSec */
	MSTK_voidSetIntervalPeriodic(1000, OS_Handler);
}

void OS_voidKillTask(u8 Copy_u8TaskID)
{
	Task[Copy_u8TaskID].u16Periodicity 	= 0;							/* Clear task periodicity */
	Task[Copy_u8TaskID].u8FirstDelay 	= 0;							/* Clear task first delay */
	Task[Copy_u8TaskID].TaskCall 		= NULL;							/* Clear task callback */
	Task[Copy_u8TaskID].u8State			= OS_STATE_NONE;				/* Clear task state */
}

void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	Task[Copy_u8TaskID].u8State			= OS_STATE_SUSPENDED;			/* Set task state as suspended */
}

void OS_voidResumeTask(u8 Copy_u8TaskID)
{
	Task[Copy_u8TaskID].u8State			= OS_STATE_READY;				/* Set task state as ready */
}

void OS_Handler(void)
{
	u8 Local_u8Counter;													/* Local counter */
	
	for(Local_u8Counter = 0; Local_u8Counter < OS_NUMBER_OF_TASKS; Local_u8Counter++)
	{
		/* Checking task's state and function validation*/
		if(Task[Local_u8Counter] == OS_STATE_READY && Task[Local_u8Counter].TaskCall != NULL)
		{
			if(Task[Local_u8Counter].u8FirstDelay == 0)
			{
				/* Set task state as running */
				Task[Local_u8Counter].u8State = OS_STATE_RUNNING;
				/* Call task fuction */
				Task[Local_u8Counter].TaskCall();
				/* Set task state as ready */
				Task[Local_u8Counter].u8State = OS_STATE_READY;
				/* Reload periodicity */
				Task[Local_u8Counter].u8FirstDelay = Task[Local_u8Counter].u16Periodicity;
			}
			else
			{
				Task[Local_u8Counter].u8FirstDelay--;
			}
			
		}
	}
}