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
	////else {
	////	usedDictionaryProcess->dictionaryProcessTail->next = usedDictionaryProcess;
	////	usedDictionaryProcess->prev = usedDictionaryProcess->dictionaryProcessTail;
	////	dictionaryProcess_Head = usedDictionaryProcess->dictionaryProcessTail->dictionaryProcessHead;
	////	dictionaryProcess_Tail = usedDictionaryProcess;
	////	usedDictionaryProcess->countDictionaryProcess = usedDictionaryProcess->dictionaryProcessTail->countDictionaryProcess + 1;

	////}

	strcpy(usedDictionaryProcess->nameOfProcess, useProcess->nameOfProcess);
	
}



void addDictionaryProcess(dictionaryDLL* proTail1, PROCESS* toList)
{
	S_dictionaryProcess* proTail2 = proTail1->dictionaryProcessTail;
	S_dictionaryProcess* nextToList = (S_dictionaryProcess*)malloc(sizeof(S_dictionaryProcess));
	strcpy(nextToList->nameOfProcess, toList->nameOfProcess);
	    nextToList->next = NULL;
	    proTail2->next = nextToList;
		nextToList->prev = proTail2;
		nextToList->countDictionaryProcess = proTail2->countDictionaryProcess + 1;
		proTail2 = nextToList;
		proTail1->dictionaryProcessTail = nextToList;
		int q = 1;
}



/*


//Insert values into the dictionary: key and val
void AddToProcessDictionary(struct Process* processDictionary_key)
{
	struct Process_Dictionary* currentProcess = (struct Process_Dictionary*)malloc(sizeof(struct Process_Dictionary));
	if (currentProcess == NULL)
	{
		char* str = strerror(GetLastError());
		LogError(str);

		return;
	}

	currentProcess->processDictionarykey = (struct Process*)malloc(sizeof(struct Process));
	if (currentProcess->processDictionarykey == NULL)
	{
		char* str = strerror(GetLastError());
		LogError(str);

		return;
	}

	strcpy(currentProcess->processDictionarykey->processName, processDictionary_key->processName);
	currentProcess->processDictionarykey->memoryInfo = processDictionary_key->memoryInfo;
	currentProcess->processDictionarykey->processID = processDictionary_key->processID;
	currentProcess->processDictionarykey->next = NULL;
	currentProcess->processDictionarykey->prev = NULL;


	struct Process_Dictionary* headOfDictionary = HeadP_Dictionary;

	if (HeadP_Dictionary == NULL)
	{
		HeadP_Dictionary = currentProcess;
		TailP_Dictionary = currentProcess;
		currentProcess->next = NULL;
		currentProcess->prev = NULL;
	}
	else
	{
		while (headOfDictionary != NULL)
		{
			if (strcmp(headOfDictionary->processDictionarykey->processName, currentProcess->processDictionarykey->processName) == 0)
			{
				free(currentProcess);
				break;
			}
			if (headOfDictionary->next == NULL)
			{
				TailP_Dictionary->next = currentProcess;
				currentProcess->prev = TailP_Dictionary;
				currentProcess->next = NULL;
				TailP_Dictionary = currentProcess;
				break;
			}

			headOfDictionary = headOfDictionary->next;
		}
	}
}


*/