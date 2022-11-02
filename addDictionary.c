#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesStructs.h"
#include "dictionaryFunctions.h"
#include "logFile.h"
#pragma warning(disable : 4996)

S_dictionaryProcess* dictionaryProcess_Head = NULL;
S_dictionaryProcess* dictionaryProcess_Tail = NULL;

S_dictionaryProcess* usedDictionaryProcess = NULL;

//get the first process and links his name to a dictinary process linked list
void MakeProcessDictionary(PROCESS* useProcessInDLL){
	Loglinebreak();
	LogEvent("enter the function (MakeProcessDictionary)");
	if (useProcessInDLL == NULL)
	{
		dictionaryProcess_Head = NULL;
		return 1;
	}

	PROCESS* useProcess = useProcessInDLL;
	usedDictionaryProcess = (S_dictionaryProcess*)malloc(sizeof(S_dictionaryProcess));
	if (usedDictionaryProcess == NULL)
	{
       LogError(strerror(GetLastError()));

		return;
	}

	usedDictionaryProcess->next = NULL;

	//links the first dictinary process to the linked list
	if (dictionaryProcess_Head == NULL) {

		usedDictionaryProcess->countDictionaryProcess = 1;
		dictionaryProcess_Head = usedDictionaryProcess;
		dictionaryProcess_Tail = usedDictionaryProcess;
		usedDictionaryProcess->prev = NULL;
	}


	strcpy(usedDictionaryProcess->nameOfProcess, useProcess->nameOfProcess);
	LogEvent("The function (MakeProcessDictionary) is done and the first dictinary process is linked\n");
}


//get process who used the same dlls and links his name to a dictinary process linked list
//add a dictinary dll that the process used and the process
void addDictionaryProcess(dictionaryDLL* locationDLL, PROCESS* namePro){

	Loglinebreak();
	LogEvent("enter the function (addDictionaryProcess)");

	//Taking the tail of the dictionary process linked list from the dictinary dll
	//links the new dictionary process to the linked list
	S_dictionaryProcess* D_processTail = locationDLL->dictionaryProcessTail;
	S_dictionaryProcess* newProcessInList = (S_dictionaryProcess*)malloc(sizeof(S_dictionaryProcess));
	strcpy(newProcessInList->nameOfProcess, namePro->nameOfProcess);
	newProcessInList->next = NULL;
	D_processTail->next = newProcessInList;
	newProcessInList->prev = D_processTail;
	newProcessInList->countDictionaryProcess = D_processTail->countDictionaryProcess + 1;
	D_processTail = newProcessInList;
	locationDLL->dictionaryProcessTail = newProcessInList;
	LogEvent("The function (addDictionaryProcess) is done and the dictinary process is linked\n");

}

