#include <string.h>
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "SnapShotList.h"
#pragma warning(disable:4996)

processNotExist = 0;

void checkListProcess(PROCESS* CheckProcess)
{
	PROCESS* currentProcess = PROCESS_Head;

	while (currentProcess != NULL)
	{
		if ((strcmp(currentProcess->nameOfProcess,CheckProcess->nameOfProcess) == 0) && currentProcess->processId == CheckProcess->processId)
		{
			currentProcess->PageFaultCount += CheckProcess->PageFaultCount;
			currentProcess->WorkingSetSize += CheckProcess->WorkingSetSize;
			currentProcess->QuotaPeakPagedPoolUsage += CheckProcess->QuotaPeakPagedPoolUsage;
			currentProcess->QuotaPagedPoolUsage += CheckProcess->QuotaPagedPoolUsage;
			currentProcess->PagefileUsage += CheckProcess->PagefileUsage;

		
			checkListDLL(currentProcess, CheckProcess->dll);
			processNotExist = 1;
			return;

		}


		currentProcess = currentProcess->next;
	}




}







