#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "structHeaderFunction.h"
#include "typesFilesHeader.h"
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

	
	int bbb = 1;


}




void headerSnapShotDetails()
{
	snapShotHeaderFile->versionSnapShot = versionOfSnapShot;
	snapShotHeaderFile->countSnapshot = snapshot_Tail->countSnapsNumber;
	snapShotHeaderFile->reserve[0];
}




















