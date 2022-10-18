#include <string.h>
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "SnapShotList.h"
#pragma warning(disable:4996)

int processNotExist = 0;


//get the process before it is added to the linked list
//and checks if the process already exists in likned list
void checkListProcess(PROCESS* CheckProcess)
{
	PROCESS* currentProcess = PROCESS_Head;

	while (currentProcess != NULL)
	{
		//If they are equal in both name and ID
		if ((strcmp(currentProcess->nameOfProcess,CheckProcess->nameOfProcess) == 0) && currentProcess->processId == CheckProcess->processId)
		{
			//connect the memory information
			currentProcess->PageFaultCount += CheckProcess->PageFaultCount;
			currentProcess->WorkingSetSize += CheckProcess->WorkingSetSize;
			currentProcess->QuotaPeakPagedPoolUsage += CheckProcess->QuotaPeakPagedPoolUsage;
			currentProcess->QuotaPagedPoolUsage += CheckProcess->QuotaPagedPoolUsage;
			currentProcess->PagefileUsage += CheckProcess->PagefileUsage;

			//checking between the two likned list of their dll
			checkListDLL(currentProcess, CheckProcess->dll);

			//sign that the process entered the condition
			processNotExist = 1;

			//when found a process that is already in the linked list there is no need to continue the loop
			return;

		}

		//move to the next process
		currentProcess = currentProcess->next;
	}

}






