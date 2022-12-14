#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "AcceptingProcess.h"
#include "structHeaderFunction.h"
#include "typesFilesHeader.h"
#include "operationFunction.h"
#include "homePageHTML.h"
#include "displayFunction.h"
#include "logFile.h"
#pragma warning(disable:4996)

snapshot* snapshot_Head = NULL;
snapshot* snapshot_Tail = NULL;

int countOfSnapsNumber = 0;
int loadFormFile = 0;
int titleProcesses = 0;
extern char str[100] = "";

//get new SnapShot and links it to a snapsot linked list if we download from a file
//or create a new Snapchat
void addOneSnapShot(snapshot* newSnapShotFromFile){

	Loglinebreak();
	LogEvent("enter the function (addOneSnapShot)");

	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	//creates a new place in memory
	newSnapShot = (snapshot*)malloc(sizeof(snapshot));
	if (!newSnapShot)
	{
		//error - No memory allocation
		LogError(strerror(GetLastError()));
		exit(1);
	}

	//each snapshot has a new list
    //reset the PROCESS_Head 
	addProcess(NULL);

	//Enter only if it does not download from a file
	if (loadFormFile == 0){

		LogEvent("enter to condition creation snapshot");
	
		//Saving the sampling start time
		sprintf(str, "%d.%d.%d/%d:%d:%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

		//creates a linked list of processors
		getProcessesInfo();

		LogEvent("back to function (addOneSnapShot)");
		//sorts by the amount of dlls in each processor
		SortingBetweenTwoProcessCountDLL();

		LogEvent("back to function (addOneSnapShot)");
		//Saves the process linked list and its quantity
		newSnapShot->myprocess = PROCESS_Head;
		newSnapShot->countOfProcess = PROCESS_Tail->countProcess;
	}
	else{

		LogEvent("enter to condition of load form file");
		//add the all information from new snapshot into the new space
		newSnapShot = newSnapShotFromFile;
	}

	//count the snapshots, every time a new snapsot enter to function it is increases by one
	++countOfSnapsNumber;

	//add the snapshot number into the new space
	newSnapShot->countSnapsNumber = countOfSnapsNumber;

	//caves the time the user press to create a new snapshot
	strcpy(newSnapShot->timeOfSnapshot, str);

	newSnapShot->next = NULL;

	//links the new snapshot to the linked list
	if (snapshot_Head == NULL)
	{

		snapshot_Head = newSnapShot;
		snapshot_Tail = newSnapShot;
		newSnapShot->prev = NULL;
	}
	else
	{
		snapshot_Tail->next = newSnapShot;
		newSnapShot->prev = snapshot_Tail;
		snapshot_Tail = newSnapShot;
	}

	    //creates a header struct for snapshots
		headerSnapShotDetails();

		//Enter only if it does not download from a file
		//creates an html page for processes and the home page
		if (loadFormFile == 0) creatingHtml();
		LogEventWithNumber("The function (addOneSnapShot) is done and the snapShot is linked, number\n", countOfSnapsNumber);
}



// creates a header struct
void headerSnapShotDetails(){

	Loglinebreak();
	LogEvent("enter the function (headerSnapShotDetails)");
	//Updates the version of the snapshot struct 
	snapShotHeaderFile->versionSnapShot = versionOfSnapShot;

	//saves the amount of the snapshots
	snapShotHeaderFile->countSnapshot = snapshot_Tail->countSnapsNumber;

	
	LogEvent("The function (headerSnapShotDetails) is done\n");
}



//creates an html page for processes and the home page
void creatingHtml() {
	
	Loglinebreak();
	LogEvent("enter the function (creatingHtml)");

	//Resets the sing that means read the file from the beginning
	firstTimeInFile = 0;

	//creating a dynamic process table
	//add a new snapshot
	char* temporaryHTML = displayProcessesInTable(newSnapShot);
	LogEvent("back to function (creatingHtml)");

	//creating a dynamic process title
	//add a new snapshot
	char* temporaryTitle = displayProcessesInTitle(newSnapShot);
	LogEvent("back to function (creatingHtml)");

	//creates an html page for all the processes in snapshot
	char* linkToSample = dynamicTitleHtml("index2.html", temporaryHTML, temporaryTitle);
	LogEvent("back to function (creatingHtml)");

	free(temporaryHTML);

	firstTimeInFile = 0;

	//creating a dynamic sample table
    //add a new snapshot, file name of tne HTML processes page, amount of dll in Snapshot, amount of memory of all processes.
	char* dynamicLineHtml = displaySnapShotInTable(newSnapShot, linkToSample, addingDll(newSnapShot), memoryAverage(newSnapShot));
	LogEvent("back to function (creatingHtml)");

	//creates the first part of a home page
	//the table of samples
	//add file name of page we want to open and the dinamic sample table.
	dynamicHtml("index.html", dynamicLineHtml, NULL);
	free(linkToSample);
	LogEvent("The function (creatingHtml) is done and created a sample page on the home page\n");
}
