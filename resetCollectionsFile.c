#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "resetCollectionsFile.h"
#include "homePageHTML.h"
#pragma warning(disable:4996)


void resetCollections(snapshot* headSanpSot)
{
	firstTimeInFile = 0;
	firstTimeHomePage = 0;
	//free(newNameOfFile);
	saveInToFileHTML(readFromFile());
	restet = 1;
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