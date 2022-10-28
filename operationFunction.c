#include <stdlib.h> 
#include <stdio.h>
#include "typesStructs.h"
#include "operationFunction.h"
#include "logFile.h"
#pragma warning(disable:4996)

//Summarize all count dlls in each process
//add a new snapshot
int addingDll(snapshot* snapShot) {
	
	Loglinebreak();
	LogEvent("enter the function (addingDll)");

	PROCESS* moveProcess = snapShot->myprocess;
	int sumOfDll = 0;
	//long



		while (moveProcess != NULL) {
			sumOfDll += moveProcess->numbersOfDLL;
			moveProcess = moveProcess->next;
		}


		LogEventWithNumber("The function (addingDll) is done and connected the sum of dll in snapShot", sumOfDll);

		//returns the count dlls amount
		return sumOfDll;
}

//calculate average of all memory of processes
//add a new snapshot
SIZE_T memoryAverage (snapshot* snapShot) {

	Loglinebreak();
	LogEvent("enter the function (memoryAverage)");

	PROCESS* moveProcess = snapShot->myprocess;
	SIZE_T averageOfMemory = 0;


	while (moveProcess != NULL) {
		averageOfMemory += moveProcess->WorkingSetSize;
		moveProcess = moveProcess->next;
	}

	averageOfMemory = averageOfMemory / snapShot->countOfProcess;

	LogEvent("The function (memoryAverage) is done and calculate average of all memory of processes");
	//returns the memory average
	return averageOfMemory;
}


//calculate average of all memory of processes that in all the snapshotns
SIZE_T memoryAvgForALLSnapshot() {

	Loglinebreak();
	LogEvent("enter the function (memoryAvgForALLSnapshot)");

	snapshot* moveSnapshot = snapshot_Head;
	PROCESS* moveProcess = moveSnapshot->myprocess;
	SIZE_T averageOfMemory = 0;
	int sumOfProcess = 0;


	while (moveSnapshot != NULL) {

		moveProcess = moveSnapshot->myprocess;

		while (moveProcess != NULL) {
			sumOfProcess++;
			averageOfMemory += moveProcess->WorkingSetSize;

			moveProcess = moveProcess->next;
		}

		moveSnapshot = moveSnapshot->next;
	}
	averageOfMemory = averageOfMemory / sumOfProcess;

	LogEvent("The function (memoryAvgForALLSnapshot) is done and calculate average of all memory of processes in all the snapshotns\n");
	//returns the memory average
	return averageOfMemory;

}


//checks which process in the snapshot takes up the most memory
//add a new snapshot
PROCESS* theBiggestMemory(snapshot* snapShot_html){

	Loglinebreak();
	LogEvent("enter the function (theBiggestMemory)");

	PROCESS* theProcess = snapShot_html->myprocess;
	PROCESS* retProcess = "";
	SIZE_T theBiggesMemory = snapShot_html->myprocess->WorkingSetSize;


	while (theProcess != NULL){
	
		//Whenever the memory of process is bigger than theBiggesMemory 
		//the memory of process becomes theBiggesMemory
		if (theProcess->WorkingSetSize > theBiggesMemory){
		
			theBiggesMemory = theProcess->WorkingSetSize;
			retProcess = theProcess;
		}
		theProcess = theProcess->next;

	}

	LogEvent("The function (theBiggestMemory) is done and checks which process in the snapshot takes up the most memory\n");

	//returns the process that takes up the most memory
	return retProcess;
}