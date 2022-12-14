#include <stdio.h>
#include "typesStructs.h"
#include "typesFilesHeader.h"
#include "fileFunction.h"
#include "oneSnapShot.h"
#include "resetCollectionsFile.h"
#include "homePageHTML.h"
#include "logFile.h"
#pragma warning(disable:4996)

snapshot* newSnapShot = NULL;
PROCESS* newProcess = NULL;
//reads from the file the header, the snapShot, the processes and the dll into the program
void loadSnapFromFile(){

	Loglinebreak();
	LogEvent("enter the function (loadSnapFromFile)");

	printf("enter name for file\n");
	scanf("%s", fileName);

	FILE* f = fopen(fileName, "rb");
	if (!f){
	
		LogError(strerror(GetLastError()));
		return 1;
	}
	//sign to the add functions that this is loadFormFile.
	loadFormFile = 1;

	snapShotHeader* loadSnapShotHeaderFile;
	loadSnapShotHeaderFile = (snapShotHeader*)malloc(sizeof(snapShotHeader));
	if (!loadSnapShotHeaderFile){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}
	processHeader* loadProcessHeaderFile;
	loadProcessHeaderFile = (processHeader*)malloc(sizeof(processHeader));
	if (!loadProcessHeaderFile){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}
	DLLNameHeaders* loadDLLHeaderFile;
	loadDLLHeaderFile = (DLLNameHeaders*)malloc(sizeof(DLLNameHeaders));
	if (!loadDLLHeaderFile){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	snapshot* currentSnapShot;
	PROCESS* currentProcess;
	DLLName* currentDLL;

	int read = fread(loadSnapShotHeaderFile, sizeof(snapShotHeader), 1, f);
	if (!read){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

    read = fread(loadProcessHeaderFile, sizeof(processHeader), 1, f);
	if (!read){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	read = fread(loadDLLHeaderFile, sizeof(DLLNameHeaders), 1, f);
	if (!read){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	LogEvent("load all the header structs");


	currentSnapShot = (snapshot*)malloc(sizeof(snapshot));
	if (!currentSnapShot){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	currentProcess = (PROCESS*)malloc(sizeof(PROCESS));
	if (!currentProcess){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	currentDLL = (DLLName*)malloc(sizeof(DLLName));
	if (!currentDLL){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}

	for (int y = 0; y < loadSnapShotHeaderFile->countSnapshot; y++){
	
		read = fread(currentSnapShot, sizeof(snapshot), 1, f);
		if (!read){
		
			//error
			LogError(strerror(GetLastError()));
			return 1;
		}

		addOneSnapShot(currentSnapShot);
		LogEventWithNumber("load snapShot", currentSnapShot->countSnapsNumber);

		for (int i = 0; i < currentSnapShot->countOfProcess; i++){
		

			read = fread(currentProcess, sizeof(PROCESS), 1, f);
			if (!read){
			
				//error
				LogError(strerror(GetLastError()));
				return 1;
			}

			addProcess(currentProcess);
			LogEventWithNumber("load process", currentProcess->countProcess);

			for (int j = 0; j < currentProcess->numbersOfDLL; j++){
			

				read = fread(currentDLL, sizeof(DLLName), 1, f);
				if (!read){
				
					//error
					LogError(strerror(GetLastError()));
					return 1;
				}
				addDLL(currentDLL->nameOfDLL);
				LogEventWithNumber("load dll", currentDLL->countDLL);

			}
			
			newProcess->dll = DLLName_Head;
			newProcess->dllTail = DLLName_Tail;
		}
		
		newSnapShot->myprocess = PROCESS_Head;
		newSnapShot->countOfProcess = PROCESS_Tail->countProcess;

		//after it end reading Snapshot,creates html pages
		creatingHtml();
		LogEvent("back to function (loadSnapFromFile) after creating the html pages");

	}

	loadFormFile = 0;



	free(currentSnapShot);
	free(currentProcess);
	free(currentDLL);

	LogEvent("The function (loadSnapFromFile) is done and free the values\n");

}


















