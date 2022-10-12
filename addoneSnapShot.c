#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "structHeaderFunction.h"
#include "typesFilesHeader.h"
#include "operationFunction.h"
#include "homePageHTML.h"
#include "displayFunction.h"
#pragma warning(disable:4996)

snapshot* snapshot_Head = NULL;
snapshot* snapshot_Tail = NULL;

int countOfSnapsNumber = 0;
int loadFormFile = 0;

void addOneSnapShot(snapshot* newSnapShotFromFile)
{
	newSnapShot = (snapshot*)malloc(sizeof(snapshot));
	if (!newSnapShot)
	{
		//error - No memory allocation
		exit(1);
	}

	

	if (loadFormFile == 0)
	{
		GetProcessesInfo();
		SortingBetweenTwoProcessCountDLL();
		PrintCount();
		newSnapShot->myprocess = PROCESS_Head;
		newSnapShot->countOfProcess = PROCESS_Tail->countProcess;
	}
	else
	{
		newSnapShot = newSnapShotFromFile;
	}

	++countOfSnapsNumber;
	newSnapShot->countSnapsNumber = countOfSnapsNumber;
	strcpy(newSnapShot->timeOfSnapshot, str);
	newSnapShot->next = NULL;
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

		addProcess(NULL);

		headerSnapShotDetails();
		char* linkToSample = (char*)malloc(50);
		if (!linkToSample)
		{
			//error
			return 1;
		}
	 
		char* temporaryHTML = displayProcessesInTable(newSnapShot);
		char* temporaryTitle = displayProcessesInTitle(newSnapShot);
		linkToSample = dynamicTitleHtml("index2.html", temporaryHTML, temporaryTitle);
		free(temporaryHTML);
		firstTime = 0;
		char* fileNameHtml = displaySnapShotInTable(newSnapShot, linkToSample, addingDll(newSnapShot->myprocess), memoryAverage(newSnapShot));
		//free(temporaryTitle);
		dynamicHtml("index.html",fileNameHtml);
		
}




void headerSnapShotDetails()
{
	snapShotHeaderFile->versionSnapShot = versionOfSnapShot;
	snapShotHeaderFile->countSnapshot = snapshot_Tail->countSnapsNumber;
	snapShotHeaderFile->reserve[0];
}





char* displaySnapShotInTable(snapshot* snapShot_html,char* fileNameHtml,int countDLLInSnapHTML,SIZE_T sizeOfMemoryHTML) {

	char* lineInTable = (char*)malloc(sizeof(long));
	if (!lineInTable)
	{
		//error
		return 1;
	}
	sprintf(lineInTable, "<tr>\n<td> %d </td>\n<td><a href =\"%s\" >Sample%d</a></td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n</tr>\n", snapShot_html->countSnapsNumber, fileNameHtml, snapShot_html->countSnapsNumber, snapShot_html->countOfProcess, countDLLInSnapHTML, sizeOfMemoryHTML);
	return lineInTable;
		

}

char* displayDLLSInProcess(PROCESS* htmlProcess) {
	//DLLName* DLLOption = (DLLName*)malloc(sizeof(DLLName));
	DLLName* DLLOption = htmlProcess->dll;
	char* lineInTable = (char*)malloc(sizeof(DLLName) +200);
	char* origin = lineInTable;
	if (!lineInTable)
	{
		//error
		return 1;
	}
	char* allTheOptions = (char*)malloc(sizeof(DLLName)* htmlProcess->numbersOfDLL+10000);
	if (!allTheOptions)
	{
		//error
		return 1;
	}
	allTheOptions[0] = NULL;
	while (DLLOption != NULL)
	{

		sprintf(lineInTable, "<option> %s </option>\n", DLLOption->nameOfDLL);
		DLLOption = DLLOption->next;
		strcat(allTheOptions, lineInTable);
	   
	    
	}

	free(origin);
	return allTheOptions;

}

char* displayProcessesInTable(snapshot* snapShot_html) {

	PROCESS* process = snapShot_html->myprocess;
	char* lineInTable = (char*)malloc(sizeof(PROCESS)*10000);
	if (!lineInTable)
	{
		//error
		return 1;
	}
	char* allTheProcesses = (char*)malloc(sizeof(PROCESS) * snapShot_html->countOfProcess + 1000000);
	if (!allTheProcesses)
	{
		//error
		return 1;
	}
	allTheProcesses[0] = NULL;
	while (process != NULL)
	{
	char* optionOfDLL = displayDLLSInProcess(process);
	lineInTable[0] = NULL;
	sprintf(lineInTable, "<tr>\n<td> %s </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td><select>\n<option selected>dll's list</option>\n%s</select></td>\n</tr>", process->nameOfProcess, process->processId, process->PageFaultCount, process->WorkingSetSize, process->QuotaPagedPoolUsage, process->QuotaPeakPagedPoolUsage, process->PagefileUsage, process->numbersOfDLL, optionOfDLL);
	free(optionOfDLL);
	process = process->next;
	strcat(allTheProcesses, lineInTable);
	}
	return allTheProcesses;


}
char* displayProcessesInTitle(snapshot* snapShot_html) {

	char* lineInTable = (char*)malloc(sizeof(200));
	if (!lineInTable)
	{
		//error
		return 1;
	}
	sprintf(lineInTable, "<h1> Samples List Number : %d At %s </h1>", snapShot_html->countSnapsNumber, snapShot_html->timeOfSnapshot);
	return lineInTable;


}








