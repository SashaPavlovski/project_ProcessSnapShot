#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesStructs.h"
#include "dictionaryFunctions.h"
#pragma warning(disable : 4996)

S_dictionaryProcess* dictionaryProcess_Head = NULL;
S_dictionaryProcess* dictionaryProcess_Tail = NULL;



void MakeProcessDictionary(PROCESS* useProcessInDLL)
{
	if (useProcessInDLL == NULL)
	{
		dictionaryProcess_Head = NULL;
		return;
	}

	PROCESS* useProcess = useProcessInDLL;
	usedDictionaryProcess = (S_dictionaryProcess*)malloc(sizeof(S_dictionaryProcess));
	if (usedDictionaryProcess == NULL)
	{
		//char* str = strerror(GetLastError());
		//LogError(str);

		return;
	}

	usedDictionaryProcess->next = NULL;

	if (dictionaryProcess_Head == NULL) {

		usedDictionaryProcess->countDictionaryProcess = 1;
		dictionaryProcess_Head = usedDictionaryProcess;
		dictionaryProcess_Tail = usedDictionaryProcess;
		usedDictionaryProcess->prev = NULL;
	}


	strcpy(usedDictionaryProcess->nameOfProcess, useProcess->nameOfProcess);
	
}



void addDictionaryProcess(dictionaryDLL* locationDLL, PROCESS* namePro)
{
	S_dictionaryProcess* D_processTail = locationDLL->dictionaryProcessTail;
	S_dictionaryProcess* newProcessInList = (S_dictionaryProcess*)malloc(sizeof(S_dictionaryProcess));
	strcpy(newProcessInList->nameOfProcess, namePro->nameOfProcess);
	newProcessInList->next = NULL;
	D_processTail->next = newProcessInList;
	newProcessInList->prev = D_processTail;
	newProcessInList->countDictionaryProcess = D_processTail->countDictionaryProcess + 1;
	D_processTail = newProcessInList;
	locationDLL->dictionaryProcessTail = newProcessInList;
}

