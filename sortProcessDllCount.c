#include <stdio.h>
#include <stdlib.h> 
#include "typesStructs.h"
#include"oneSnapShot.h"
#pragma warning(disable:4996)


void PrintList()
{
	//LogEvent("Print program started\n");
	PROCESS* move = PROCESS_Head;
	PROCESS* print = PROCESS_Head;

	while (move != NULL)
	{
		print = move;
		move = move->next;
		printf("the number is %d\n", print->numbersOfDLL);
		//LogEvent("A document has been printed\n");

	}
	//LogEvent("The printing process is finished and the program PrintList is closed\n\n");
	printf("\n\n\n");
}

void PrintCount()
{
	PROCESS* move = PROCESS_Head;
	PROCESS* print = PROCESS_Head;

	while (move != NULL)
	{
		print = move;
		move = move->next;
		printf("the countProcess is %d\n", print->countProcess);
		//LogEvent("A document has been printed\n");

	}
	printf("the tail is %d\n", PROCESS_Tail->countProcess);
	//LogEvent("The printing process is finished and the program PrintList is closed\n\n");
}


void PrintListDictionary()
{
	//LogEvent("Print program started\n");
	dictionaryDLL* move = dictionaryDLL_Head;
	dictionaryDLL* print = dictionaryDLL_Head;

	while (move != NULL)
	{
		print = move;
		move = move->next;
		printf("the number is %s\n", print->nameOfDLL);
		//LogEvent("A document has been printed\n");

	}
	//LogEvent("The printing process is finished and the program PrintList is closed\n\n");
	printf("\n\n\n");
}

void replaceBetweenTwoProcess(PROCESS* processToChange)
{
	//LogEvent("enters the Replace function\n");
	PROCESS* changeProcess = processToChange;
	int numOfProcess;

	if (changeProcess == NULL)
	{
    	//LogEvent("No need to swap. No Items in list\n");
		//There are no numbers
	}
	else if (changeProcess->next == NULL)
	{
		//LogEventVal("No need to swap. This is the only number\n", changeProcess->numbersOfDLL);
		//single
	}
	else if (changeProcess == PROCESS_Head && changeProcess->next == PROCESS_Tail)
	{
		//LogEventVal("swap between two num. There are only two numbers\n", changeProcess->numbersOfDLL);
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
	else if (changeProcess == PROCESS_Head)
	{
		//LogEventVal("swap starts from the beginning. This is the first document\n", changeProcess->numbersOfDLL);
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
	else if (changeProcess->next == PROCESS_Tail)
	{
		//LogEventVal("swap between two num. The number is one before last\n", changeProcess->numbersOfDLL);
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
		//LogEventVal("swap between two num. The change starts from the middle\n", changeProcess->numbersOfDLL);
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

	//LogEvent("The replacement process is done and the program Replace is finished\n\n");
}

void SortingBetweenTwoProcessCountDLL()
{
	//LogEvent("enters the Sorting_between_two function\n");

	PROCESS* curreProcess = PROCESS_Head;
	if (!curreProcess)
	{
		//LogError("The list is empty\n");
		// The list is empty
		return;
	}

	char change = 1;
	while (change != 0)
	{
		//LogEvent("The sorting process has started\n");

		change = 0;
		while (curreProcess != NULL)
		{
			if (curreProcess->next != NULL && curreProcess->numbersOfDLL > curreProcess->next->numbersOfDLL)
			{
				//LogEventVal("the current number\n", curreProcess->numbersOfDLL);
				//LogEventVal("the next number\n", curreProcess->next->numbersOfDLL);
				//LogEventVal("The current number is bigger than the next number\n\n", curreProcess->numbersOfDLL);
				replaceBetweenTwoProcess(curreProcess);
				change++;
			}
			curreProcess = curreProcess->next;
		}

		curreProcess = PROCESS_Head;
	}
	//LogEvent("The sorting process has Ended\n\n");
	PrintList();

	//LogEvent("The selection process is done and the program Sorting_between_two is finished\n\n");
}


