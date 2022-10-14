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

	
	addProcess(NULL);

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


		headerSnapShotDetails();

		firstTimeInFile = 0;
		char* temporaryHTML = displayProcessesInTable(newSnapShot);
		char* temporaryTitle = displayProcessesInTitle(newSnapShot);
		char* linkToSample = dynamicTitleHtml("index2.html", temporaryHTML, temporaryTitle);
		//free(temporaryTitle);
		free(temporaryHTML);

		firstTimeInFile = 0;


		char* dynamicLineHtml = displaySnapShotInTable(newSnapShot, linkToSample, addingDll(newSnapShot), memoryAverage(newSnapShot));
        free(linkToSample);
		char* nameF = dynamicHtml("index.html", dynamicLineHtml,NULL);
		//free(nameF);
		//free(dynamicLineHtml);
		
}




void headerSnapShotDetails()
{
	snapShotHeaderFile->versionSnapShot = versionOfSnapShot;
	snapShotHeaderFile->countSnapshot = snapshot_Tail->countSnapsNumber;
	snapShotHeaderFile->reserve[0];
}





char* displaySnapShotInTable(snapshot* snapShot_html,char* NameProcessHtml,int countDLLInSnapHTML,SIZE_T sizeOfMemoryHTML) {

	char* lineInTable = (char*)malloc(sizeof(int)*100);
	//lineInTable[0] = NULL;
	if (!lineInTable)
	{
		//errors
		return 1;
	}
	sprintf(lineInTable, "<tr>\n<td> %d </td>\n<td><a href =\"%s\" >Sample%d</a></td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n</tr>\n", snapShot_html->countSnapsNumber, NameProcessHtml, snapShot_html->countSnapsNumber, snapShot_html->countOfProcess, countDLLInSnapHTML, sizeOfMemoryHTML);
	return lineInTable;
		

}

char* displayDLLSInProcess(PROCESS* htmlProcess) {
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
	char* lineInTable = (char*)malloc(sizeof(PROCESS)*100000);
	if (!lineInTable)
	{
		//error
		return 1;
	}
	char* allTheProcesses = (char*)malloc(sizeof(PROCESS) * snapShot_html->countOfProcess + 10000000);
	if (!allTheProcesses)
	{
		//error
		return 1;
	}
	allTheProcesses[0] = NULL;
	char* optionOfDLL = NULL;
	while (process != NULL)
	{
		optionOfDLL = displayDLLSInProcess(process);
        lineInTable[0] = "";
	    sprintf(lineInTable, "<tr>\n<td> %s </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td> %d </td>\n<td><select>\n<option selected>dll's list</option>\n%s</select></td>\n</tr>", process->nameOfProcess, process->processId, process->PageFaultCount, process->WorkingSetSize, process->QuotaPagedPoolUsage, process->QuotaPeakPagedPoolUsage, process->PagefileUsage, process->numbersOfDLL, optionOfDLL);
	    process = process->next;
	    strcat(allTheProcesses, lineInTable);
	    
	}
	free(lineInTable);
	free(optionOfDLL);
	return allTheProcesses;


}
char* displayProcessesInTitle(snapshot* snapShot_html) {

	char* lineInTable = (char*)malloc(100);
	lineInTable[0] = NULL;
	if (!lineInTable)
	{
		//error
		return 1;
	}
	sprintf(lineInTable, "<h1> Samples List Number : %d At %s </h1>", snapShot_html->countSnapsNumber, snapShot_html->timeOfSnapshot);
	return lineInTable;


}
//
//
//char* dynamicNav()
//{
//	char* dataNav = (char*)malloc(100);
//	dataNav[0] = NULL;
//	if (!dataNav)
//	{
//		//error
//		return 1;
//	}
//	sprintf(dataNav, "\n<div> Dll's cnt: %d </div>\n<div> Processes cnt: %d </div>\n<div> Memory avg: %d </div>\n");
//		
//	return dataNav;
//}






