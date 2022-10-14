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
	SIZE_T averageOfMemoty = 0;


	while (moveProcess != NULL) {
		averageOfMemoty += moveProcess->WorkingSetSize;
		moveProcess = moveProcess->next;
	}

	averageOfMemoty = averageOfMemoty / snapShot->countOfProcess;
	return averageOfMemoty;
}





