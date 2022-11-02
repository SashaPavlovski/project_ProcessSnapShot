#include <string.h>
#include <stdio.h>
#include "typesStructs.h"
#include "SnapShotList.h"
#include "logFile.h"
#pragma warning(disable:4996)

extern int ExistsDLL = 0;
int countNumberEnter = 0;

//if both processes are equal in checkListProcess function
//checking between the two likned list of their dll
//if there is a different dll in a linked list that is checked, add it to the original linked list.
//get the original process and dll linked list of the process that is in checking

void checkListDLL(PROCESS* currentProcess, DLLName* CheckDLL){

	Loglinebreak();
	LogEvent("enter the function (checkListDLL)");

	DLLName* currentDLL = currentProcess->dll;
	DLLName* currentCheckDLL = CheckDLL;

	while (currentCheckDLL != NULL){//in checking

		currentDLL = currentProcess->dll;

		while (currentDLL != NULL){//original 
		

			if (strcmp(currentCheckDLL->nameOfDLL,currentDLL->nameOfDLL) == 0 ){//checking if the dlls name are equal
			
				//run to the end of the original linked list after finding their are equal
				currentDLL = DLLName_Tail;

				//sign that the dll entered the condition
				ExistsDLL = 1;
			}
				currentDLL = currentDLL->next;
		}


	     if (ExistsDLL != 1){

			 LogEvent("enter to condition that entered only if the dll that in checking is not in the original list");
			
			 //entered only if the dll that in checking is not in the original list
			 //add the checked dll to the origin linked list
			 DLLName* dllTailProcessCurrent = addDLLToExistList(currentProcess->dllTail, currentCheckDLL);
			 LogEvent("back to function (checkListDLL)");

			 //after adding the dll to the lined list
			 //update the dllTail and numbersOfDLL in the original process 
			 currentProcess->dllTail = dllTailProcessCurrent;
			 currentProcess->numbersOfDLL = dllTailProcessCurrent->countDLL;
			 countNumberEnter++;
	     }
		currentCheckDLL = currentCheckDLL->next;
		
		//reset the sign for the next checked dll
		ExistsDLL = 0;
		
	}

	LogEventWithNumber("The function (checkListDLL) is done and checked between the two likned list of their dll, number of new dll is", countNumberEnter);
	Loglinebreak();

	countNumberEnter = 0;
}

