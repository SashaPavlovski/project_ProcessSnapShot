#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "operationFunction.h"

#pragma warning(disable:4996)


int addingDll(snapshot* snapShot) {

	PROCESS* moveProcess = snapShot->myprocess;
	long sumOfDll = 0;


		while (moveProcess != NULL) {
			sumOfDll += moveProcess->numbersOfDLL;
			moveProcess = moveProcess->next;
		}

		return sumOfDll;
}


SIZE_T memoryAverage (snapshot* snapShot) {

	PROCESS* moveProcess = snapShot->myprocess;
	SIZE_T averageOfMemory = 0;


	while (moveProcess != NULL) {
		averageOfMemory += moveProcess->WorkingSetSize;
		moveProcess = moveProcess->next;
	}

	averageOfMemory = averageOfMemory / snapShot->countOfProcess;
	return averageOfMemory;
}



SIZE_T memoryAvgForALLSnapshot() {

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
	return averageOfMemory;

}
