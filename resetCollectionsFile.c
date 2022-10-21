#include <stdlib.h> 
#include <stdio.h>
#include "typesStructs.h"
#include "resetCollectionsFile.h"
#include "structHeaderFunction.h"
#include "homePageHTML.h"
#include "logFile.h"
#pragma warning(disable:4996)

//deletes all created samples
//gets the head of the first sample
void resetCollections(snapshot* headSanpSot)
{
	firstTimeInFile = 0;
	firstTimeHomePage = 0;
	//sign to delete the place of the header structs
	restet = 1;
	//delete the place of the header structs
	headerMalloc();
	snapshot* currentSnapShot = headSanpSot;
	PROCESS* currentProcess;
	DLLName* currentDLL;
	snapshot* oldSnapShot;
	PROCESS* oldProcess;
	DLLName* oldDLL;
	while (currentSnapShot != NULL)
	{
		currentProcess = currentSnapShot->myprocess;
		while (currentProcess != NULL)
		{
			currentDLL = currentProcess->dll;
			while (currentDLL != NULL)
			{
				oldDLL = currentDLL;
				currentDLL = currentDLL->next;
				free(oldDLL);
			}

			oldProcess = currentProcess;
			currentProcess = currentProcess->next;
			free(oldProcess);

		}

		oldSnapShot = currentSnapShot;
		currentSnapShot = currentSnapShot->next;
		free(oldSnapShot);

	}

}