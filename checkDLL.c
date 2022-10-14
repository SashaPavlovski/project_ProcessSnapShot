#include <string.h>
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "SnapShotList.h"
#pragma warning(disable:4996)

extern int ExistsDLL = 0;
void checkListDLL(PROCESS* currentProcess, DLLName * CheckDLL)
{
	DLLName* currentDLL = currentProcess->dll;
	DLLName* currentCheckDLL = CheckDLL;
	while (currentCheckDLL != NULL)//new 
	{
		currentDLL = currentProcess->dll;

		while (currentDLL != NULL)//origin
		{

			if (strcmp(currentCheckDLL->nameOfDLL,currentDLL->nameOfDLL) == 0 )//checking if the dlls are equal
			{
				currentDLL = DLLName_Tail;
				ExistsDLL = 1;
			}
				currentDLL = currentDLL->next;// if the dlls are  
		}
	     if (ExistsDLL != 1)
	      {
			
			 DLLName* dllTailProcessCurrent;
			 dllTailProcessCurrent = addDLLToExistList(currentProcess->dllTail, currentCheckDLL);
			 currentProcess->dllTail = dllTailProcessCurrent;
			 currentProcess->numbersOfDLL = dllTailProcessCurrent->countDLL;
	     	
	      }
		currentCheckDLL = currentCheckDLL->next;
		ExistsDLL = 0;
		
	}

	int w = 4;

}

