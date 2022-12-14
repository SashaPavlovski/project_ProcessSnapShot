#include <stdlib.h> 
#include <stdio.h>
#include "typesStructs.h"
#include "displayFunction.h"
#include "homePageHTML.h"
#include "operationFunction.h"
#include "logFile.h"
#pragma warning(disable:4996)



//creating a dynamic sample table
//add a new snapshot, file name of tne HTML processes page, amount of dll in Snapshot, amount of memory of all processes.
char* displaySnapShotInTable(snapshot* snapShot_html, char* NameProcessHtml, int countDLLInSnapHTML, SIZE_T sizeOfMemoryHTML) {
	Loglinebreak();
	LogEvent("enter the function (displaySnapShotInTable)");
	char* lineInTable = (char*)malloc(sizeof(int) * 100);
	if (!lineInTable)
	{
		//errors
		LogError(strerror(GetLastError()));
		return;
	}
	sprintf(lineInTable, "<tr>\n<td><div class=\"id\"> %d </div></td>\n<td><div class=\"link\"><a href = \"%s\" >Sample%d</a></div></td>\n<td><div class=\"cntProcess\"> %d </div></td>\n<td><div class=\"dllCnt\">12000 %d </div></td>\n<td><div class=\"memoryAvg\"> %d </div></td>\n</tr>\n", snapShot_html->countSnapsNumber, NameProcessHtml, snapShot_html->countSnapsNumber, snapShot_html->countOfProcess, countDLLInSnapHTML, sizeOfMemoryHTML);
	
	LogEventWithNumber("The function (displaySnapShotInTable) is done, sample", snapShot_html->countSnapsNumber);
	Loglinebreak();
	return lineInTable;

}


//creates a subtable of dlls for each process
//add a new process
char* displayDLLSInProcess(PROCESS* htmlProcess) {

	Loglinebreak();
	LogEvent("enter the function (displayDLLSInProcess)");

	DLLName* DLLOption = htmlProcess->dll;
	char* lineInTable = (char*)malloc(sizeof(DLLName) + 200);
	char* origin = lineInTable;
	if (!lineInTable)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	char* allTheOptions = (char*)malloc(sizeof(DLLName) * htmlProcess->numbersOfDLL + 10000);
	if (!allTheOptions)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	allTheOptions[0] = NULL;
	while (DLLOption != NULL)
	{

		sprintf(lineInTable, "<option> %s </option>\n", DLLOption->nameOfDLL);
		DLLOption = DLLOption->next;

		//Connects each line that is created (lineInTable) to one place (allTheOptions)
		strcat(allTheOptions, lineInTable);


	}

	free(origin);

	LogEventWithNumber("The function (displayDLLSInProcess) is done, number of dll option", htmlProcess->numbersOfDLL);
	Loglinebreak();
	//returns the entire created table
	return allTheOptions;
}



//creating a dynamic process table
//add a new snapshot
char* displayProcessesInTable(snapshot* snapShot_html) {

	Loglinebreak();
	LogEvent("enter the function (displayProcessesInTable)");

	//gets the snapshot and checks which process takes up the most memory
	PROCESS* processWithBigMemory = theBiggestMemory(snapShot_html);

	LogEvent("back to function (displayProcessesInTable) and find the process that takes the most memory");

	PROCESS* process = snapShot_html->myprocess;
	char* lineInTable = (char*)malloc(sizeof(PROCESS) * 100000);
	if (!lineInTable){
	
		//error
		LogError(strerror(GetLastError()));
		return 1;
	}
	char* allTheProcesses = (char*)malloc(sizeof(PROCESS) * snapShot_html->countOfProcess + 10000000);
	if (!allTheProcesses){

		//error
		LogError(strerror(GetLastError()));
		return 1;
	}
	allTheProcesses[0] = NULL;
	char* optionOfDLL = NULL;
	while (process != NULL){
	
		//adding to the process with the most memory is a warning sign
		if (processWithBigMemory->WorkingSetSize == process->WorkingSetSize) {
			//creates a subtable of dlls for each process
			optionOfDLL = displayDLLSInProcess(process);
			lineInTable[0] = "";
			sprintf(lineInTable, "\n<tr>\n<td><div class=\"processName\"> %s </div></td>\n<td><div class=\"processId\"> %lu</div> </td>\n<td><div class=\"memory1\"> %lu </div></td>\n<td><div class=\"memory2\"> %llu <i class=\"fa fa-warning\" style=\"color:red\"> </i></div></td>\n<td><div class=\"memory3\"> %llu </div></td>\n<td><div class=\"memory4\"> %llu </div></td>\n<td><div class=\"memory5\"> %llu </div></td>\n<td><div class=\"countDll\"> %d </div></td>\n<td><div class=\"dllList\"><select><option selected>dll's list</option>%s</select></td>\n</tr>\n", process->nameOfProcess, process->processId, process->PageFaultCount, process->WorkingSetSize, process->QuotaPagedPoolUsage, process->QuotaPeakPagedPoolUsage, process->PagefileUsage, process->numbersOfDLL, optionOfDLL);
			LogEventWithVariable("The row process in the table that takes the most memory is", process->nameOfProcess);
		}
		else {

			//creates a subtable of dlls for each process
			optionOfDLL = displayDLLSInProcess(process);
			lineInTable[0] = "";
			sprintf(lineInTable,"\n<tr>\n<td><div class=\"processName\"> %s </div></td>\n<td><div class=\"processId\"> %lu</div> </td>\n<td><div class=\"memory1\"> %lu </div></td>\n<td><div class=\"memory2\"> %llu </div></td>\n<td><div class=\"memory3\"> %llu </div></td>\n<td><div class=\"memory4\"> %llu </div></td>\n<td><div class=\"memory5\"> %llu </div></td>\n<td><div class=\"countDll\"> %d </div></td>\n<td><div class=\"dllList\"><select><option selected>dll's list</option>%s</select></td>\n</tr>\n", process->nameOfProcess, process->processId, process->PageFaultCount, process->WorkingSetSize, process->QuotaPagedPoolUsage, process->QuotaPeakPagedPoolUsage, process->PagefileUsage, process->numbersOfDLL, optionOfDLL);
		}
			process = process->next;

		//Connects each line that is created (lineInTable) to one place (allTheProcesses)
		strcat(allTheProcesses, lineInTable);

	}
	free(lineInTable);
	free(optionOfDLL);

	LogEventWithNumber("The function (displayProcessesInTable) is done, number of processes in table is", snapShot_html->countOfProcess);
	Loglinebreak();

	//returns the entire created table
	return allTheProcesses;
}




//creating a dynamic process title
//add a new snapshot
char* displayProcessesInTitle(snapshot* snapShot_html) {

	Loglinebreak();
	LogEvent("enter the function (displayProcessesInTitle)");

	//know if is for table processes
	titleProcesses = 1;

	char* lineInTable = (char*)malloc(100);
	lineInTable[0] = NULL;
	if (!lineInTable)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	sprintf(lineInTable, "<h1> Samples List Number : %d At %s </h1>", snapShot_html->countSnapsNumber, snapShot_html->timeOfSnapshot);
	
	LogEvent("The function (displayProcessesInTitle) is done and created process title\n");

	//returns the entire created title
	return lineInTable;

}

