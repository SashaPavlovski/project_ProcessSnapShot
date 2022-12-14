#include <stdio.h>
#include <stdlib.h> 
#include "typesStructs.h"
#include"oneSnapShot.h"
#include "logFile.h"
#pragma warning(disable:4996)




void replaceBetweenTwoProcess(PROCESS* processToChange){

	Loglinebreak();
	LogEvent("enters the (replaceBetweenTwoProcess) function");
	PROCESS* changeProcess = processToChange;
	int numOfProcess;

	if (changeProcess == NULL){
	
    	LogEvent("No need to swap. No process in list\n");
		return;
		//There are no numbers
	}
	else if (changeProcess->next == NULL){
	
		LogEventWithNumber("No need to swap. This is the only number", changeProcess->countProcess);
		return;
		//single
	}
	else if (changeProcess == PROCESS_Head && changeProcess->next == PROCESS_Tail){
	
		LogEvent("swap between two num. There are only two numbers");
		numOfProcess = changeProcess->countProcess;
		changeProcess->countProcess = changeProcess->next->countProcess;
		changeProcess->next->countProcess = numOfProcess;
		changeProcess->next = NULL;
		changeProcess->prev = PROCESS_Tail;
		PROCESS_Tail->prev = NULL;
		PROCESS_Tail->next = changeProcess;
		PROCESS_Tail = changeProcess;
		PROCESS_Head = changeProcess->prev;

		//only two numbers
	}
	else if (changeProcess == PROCESS_Head){
	
		LogEvent("swap starts from the beginning. This is the first process");
		numOfProcess = changeProcess->countProcess;
		changeProcess->countProcess = changeProcess->next->countProcess;
		changeProcess->next->countProcess = numOfProcess;
		changeProcess->next->prev = NULL;
		changeProcess = changeProcess->next->next;
		PROCESS_Head->next->next = PROCESS_Head;
		PROCESS_Head->prev = PROCESS_Head->next;
		PROCESS_Head->next = changeProcess;
		changeProcess->prev = PROCESS_Head;
		PROCESS_Head = PROCESS_Head->prev;
		changeProcess = PROCESS_Head->next;
		//change from the beginning

	}
	else if (changeProcess->next == PROCESS_Tail){
	
		LogEvent("swap between two process. The process is one before last");
		numOfProcess = changeProcess->countProcess;
		changeProcess->countProcess = changeProcess->next->countProcess;
		changeProcess->next->countProcess = numOfProcess;
		changeProcess->next->prev = changeProcess->prev;
		changeProcess->prev = PROCESS_Tail;
		PROCESS_Tail->next = changeProcess;
		changeProcess->next = NULL;
		PROCESS_Tail->prev->next = changeProcess->prev;
		PROCESS_Tail = PROCESS_Tail->next;

		//change the tail
	}
	else
	{
		LogEvent("swap between two process. The change starts from the middle");
		numOfProcess = changeProcess->countProcess;
		changeProcess->countProcess = changeProcess->next->countProcess;
		changeProcess->next->countProcess = numOfProcess;
		changeProcess->next->prev = changeProcess->prev;
		changeProcess->prev = changeProcess->next;
		changeProcess->next = changeProcess->next->next;
		changeProcess->prev->next = changeProcess;
		changeProcess->prev->prev->next = changeProcess->prev;
		changeProcess->next->prev = changeProcess;

		//Change from the middle
	}

	LogEvent("The replacement process is done and the function (replaceBetweenTwoProcess) is done\n");
}

void SortingBetweenTwoProcessCountDLL(){

	LogEvent("enters the (SortingBetweenTwoProcessCountDLL) function\n");

	PROCESS* curreProcess = PROCESS_Head;
	if (!curreProcess){
	
		LogError(strerror(GetLastError()));

		// The list is empty
		return;
	}

	char change = 1;

	LogEvent("The sorting process loop has started\n");

	while (change != 0){
	
		change = 0;

		while (curreProcess != NULL){
		
			if (curreProcess->next != NULL && curreProcess->numbersOfDLL > curreProcess->next->numbersOfDLL){
			
				replaceBetweenTwoProcess(curreProcess);
				change++;
			}
			curreProcess = curreProcess->next;
		}

		curreProcess = PROCESS_Head;
	}


	LogEvent("The sorting process has Ended and the fumction (SortingBetweenTwoProcessCountDLL) is done\n\n");
}


