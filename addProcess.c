#include <stdlib.h>
#include <stdio.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "typesFilesHeader.h"
#include "resetCollectionsFile.h"
#include "structHeaderFunction.h"
#include "SnapShotList.h"
#include "dictionaryFunctions.h"
#include "logFile.h"
#pragma warning(disable:4996)

 PROCESS* PROCESS_Head = NULL;
 PROCESS* PROCESS_Tail = NULL;

int countP = 0;

//get process and links it to a process linked list
void addProcess(PROCESS* processNew){

	Loglinebreak();
	LogEvent("enter the function (addProcess)");
	
	//each process has a new list
	//reset the DLLName_Head 
	addDLL(NULL);
	LogEvent("back to function (addProcess)");
	//if the function (addProcess) gets NULL it will reset the PROCESS_Head 
	if (processNew == NULL){
	
		//resetting the process count
		countP = 0;
		PROCESS_Head = NULL;
		LogEvent("PROCESS_Head is reset and processNew is NULL");
		LogEvent("The function (addProcess) is done\n");
		return;
	}

	//checking if this is the first time creating a process linked list
	//Entered only from the second process linked list
	if (FirstListProcess >0){

		LogEvent("enter to condition which signifies that this is not the first time creating a process linked list");
		//Checking the new process against the existing process linked list
		//get the new process
		checkListProcess(processNew);

		LogEvent("back to function (addProcess)");

		//entered only if the new process exists in the process linked list
		if (processNotExist == 1){

			LogEvent("enter to condition that entered only if the new process exists in the process linked list and not adding the process to the list");
			//resets and exits the list
			//and not linked to the list
			processNotExist = 0;

			LogEvent("The function (addProcess) is done\n");
			return;
		}

	}

	//count the process, every time a new process enter to function it is increases by one
	++countP;

	//creates a new place in memory
	newProcess = (PROCESS*)malloc(sizeof(PROCESS));
	if (!newProcess){
		LogError(strerror(GetLastError()));
		//error - No memory allocation
		exit(1);
	}


	//add the all information from new process into the new space
	strcpy(newProcess->nameOfProcess, processNew->nameOfProcess);
	newProcess->PageFaultCount = processNew->PageFaultCount;
	newProcess->WorkingSetSize = processNew->WorkingSetSize;
	newProcess->QuotaPeakPagedPoolUsage = processNew->QuotaPeakPagedPoolUsage;
	newProcess->QuotaPagedPoolUsage = processNew->QuotaPagedPoolUsage;
	newProcess->PagefileUsage = processNew->PagefileUsage;
	newProcess->processId = processNew->processId;
	newProcess->numbersOfDLL = processNew->numbersOfDLL;

	//add the process number into the new space
	newProcess->countProcess = countP;

	//Enter only if it does not download from a file
	if (loadFormFile == 0){
		LogEvent("enter to condition creation process");
		//add the all information from new process into the new space
		newProcess->dll = processNew->dll;
		newProcess->dllTail = processNew->dllTail;
	}

	newProcess->next = NULL;

	//links the new process to the linked list
	if (PROCESS_Head == NULL){
	

		PROCESS_Head = newProcess;
		PROCESS_Tail = newProcess;
		newProcess->prev = NULL;
	}
	else{
	
		PROCESS_Tail->next = newProcess;
		newProcess->prev = PROCESS_Tail;
		PROCESS_Tail = newProcess;
	}

	//free(processNew);
	// creates a header struct for processes
	if (countP == 1)
    headerProcessDetails();
	LogEventWithNumber("The function (addProcess) is done and the process is linked, number\n", countOfDll);
}


// creates a header struct
void headerProcessDetails(){
	Loglinebreak();
	LogEvent("enter the function (headerProcessDetails)");
	processHeaderFile->versionProcess = versionOfProcess;
	LogEvent("The function (headerProcessDetails) is done and save the header of dll link list\n");
}