#include <string.h>
#include <stdio.h>
#include "typesStructs.h"
#include "SnapShotList.h"
#include "logFile.h"
#pragma warning(disable:4996)

extern int ExistsDLL = 0;

//if both processes are equal in checkListProcess function
//checking between the two likned list of their dll
//if there is a different dll in a linked list that is checked, add it to the original linked list.
//get the original process and dll linked list of the process that is in checking

void checkListDLL(PROCESS* currentProcess, DLLName * CheckDLL)
{
	DLLName* currentDLL = currentProcess->dll;
	DLLName* currentCheckDLL = CheckDLL;

	while (currentCheckDLL != NULL)//in checking

	{
		currentDLL = currentProcess->dll;

		while (currentDLL != NULL)//original 
		{

			if (strcmp(currentCheckDLL->nameOfDLL,currentDLL->nameOfDLL) == 0 )//checking if the dlls name are equal
			{
				//run to the end of the original linked list after finding their are equal
				currentDLL = DLLName_Tail;

				//sign that the dll entered the condition
				ExistsDLL = 1;
			}
				currentDLL = currentDLL->next;
		}


	     if (ExistsDLL != 1)
	     {
			 //entered only if the dll that in checking is not in the original list
			 //add the checked dll to the origin linked list
			 DLLName* dllTailProcessCurrent = addDLLToExistList(currentProcess->dllTail, currentCheckDLL);
			
			 //after adding the dll to the lined list
			 //update the dllTail and numbersOfDLL in the original process 
			 currentProcess->dllTail = dllTailProcessCurrent;
			 currentProcess->numbersOfDLL = dllTailProcessCurrent->countDLL;
	     	
	     }
		currentCheckDLL = currentCheckDLL->next;
		
		//reset the sign for the next checked dll
		ExistsDLL = 0;
		
	}

}

