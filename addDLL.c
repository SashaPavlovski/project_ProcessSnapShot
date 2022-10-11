#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "typesStructs.h"
#include "typesFilesHeader.h"
#include "SnapShotList.h"
#include "structHeaderFunction.h"
#include "oneSnapShot.h"
#pragma warning(disable:4996)


 DLLName* DLLName_Head = NULL;
 DLLName* DLLName_Tail = NULL;

countOfDll = 0;
void addDLL(char dllName[])
{

	++countOfDll;
	if (dllName == NULL)
		{
	    	countOfDll = 0;
			DLLName_Head = NULL;
			return;
		}
	// The function has started
	DLLName* newDLL = (DLLName*)malloc(sizeof(DLLName));
	if (!newDLL)
	{
		//error - No memory allocation
		exit(1);
	}

	newDLL->countDLL = countOfDll;
	strcpy(newDLL->nameOfDLL, dllName);

	newDLL->next = NULL;
	if (DLLName_Head == NULL)
	{

		DLLName_Head = newDLL;
		DLLName_Tail = newDLL;
		newDLL->prev = NULL;
	}
	else
	{
		DLLName_Tail->next = newDLL;
		newDLL->prev = DLLName_Tail;
		DLLName_Tail = newDLL;
	
	}

	 headerDLLDetails();
}





DLLName* addDLLToExistList(DLLName* TailOfExistDLL, DLLName* newList)
{
	     newList->countDLL = TailOfExistDLL->countDLL + 1;
		 newList->next = NULL;

		 TailOfExistDLL->next = newList;
         newList->prev = TailOfExistDLL;
         TailOfExistDLL = newList;

		headerDLLDetails();
		 return TailOfExistDLL;
}




void headerDLLDetails()
{
	DLLHeaderFile->versionDLLName= versionOfDLL;
	DLLHeaderFile->reserve[0];
}