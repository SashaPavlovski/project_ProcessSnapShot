#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "typesFilesHeader.h"
#include "fileFunction.h"
#include "oneSnapShot.h"
#include "resetCollectionsFile.h"
#pragma warning(disable:4996)

snapshot* newSnapShot = NULL;
PROCESS* newProcess = NULL;

void loadSnapFromFile()
{
	printf("enter name for file\n");
	scanf("%s", fileName);

	FILE* f = fopen(fileName, "rb");
	if (!f)
	{
		printf("The file did not open");
		return 1;
	}
	loadFormFile = 1;
	snapShotHeader* loadSnapShotHeaderFile;
	loadSnapShotHeaderFile = (snapShotHeader*)malloc(sizeof(snapShotHeader));
	if (!loadSnapShotHeaderFile)
	{
		//error
		return 1;
	}
	processHeader* loadProcessHeaderFile;
	loadProcessHeaderFile = (processHeader*)malloc(sizeof(processHeader));
	if (!loadProcessHeaderFile)
	{
		//error
		return 1;
	}
	DLLNameHeaders* loadDLLHeaderFile;
	loadDLLHeaderFile = (DLLNameHeaders*)malloc(sizeof(DLLNameHeaders));
	if (!loadDLLHeaderFile)
	{
		//error
		return 1;
	}


	snapshot* currentSnapShot;
	PROCESS* currentProcess;
	DLLName* currentDLL;

	int read = fread(loadSnapShotHeaderFile, sizeof(snapShotHeader), 1, f);
	if (!read)
	{
		//error
		return 1;
	}

    read = fread(loadProcessHeaderFile, sizeof(processHeader), 1, f);
	if (!read)
	{
		//error
		return 1;
	}

	read = fread(loadDLLHeaderFile, sizeof(DLLNameHeaders), 1, f);
	if (!read)
	{
		//error
		return 1;
	}


	currentSnapShot = (snapshot*)malloc(sizeof(snapshot));
	if (!currentSnapShot)
	{
		//error
		return 1;
	}

	currentProcess = (PROCESS*)malloc(sizeof(PROCESS));
	if (!currentProcess)
	{
		//error
		return 1;
	}

	currentDLL = (DLLName*)malloc(sizeof(DLLName));
	if (!currentDLL)
	{
		//error
		return 1;
	}

	for (int y = 0; y < loadSnapShotHeaderFile->countSnapshot; y++)
	{
		read = fread(currentSnapShot, sizeof(snapshot), 1, f);
		if (!read)
		{
			//error
			return 1;
		}

		addOneSnapShot(currentSnapShot);

		for (int i = 0; i < currentSnapShot->countOfProcess; i++)
		{

			read = fread(currentProcess, sizeof(PROCESS), 1, f);
			if (!read)
			{
				//error
				return 1;
			}

			addProcess(currentProcess);

			for (int j = 0; j < currentProcess->numbersOfDLL; j++)
			{

				read = fread(currentDLL, sizeof(DLLName), 1, f);
				if (!read)
				{
					//error
					return 1;
				}

				addDLL(currentDLL->nameOfDLL);
			}
			Sleep(1000);
			newProcess->dll = DLLName_Head;
			newProcess->dllTail = DLLName_Tail;
		}
		Sleep(1000);
		newSnapShot->myprocess = PROCESS_Head;
		newSnapShot->countOfProcess = PROCESS_Tail->countProcess;
	}

	loadFormFile = 0;



	free(currentSnapShot);
	free(currentProcess);
	free(currentDLL);

		
}


















