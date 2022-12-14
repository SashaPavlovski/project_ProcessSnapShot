#include <stdlib.h> 
#include <stdio.h>
#include "typesStructs.h"
#include "typesFilesHeader.h"
#include "SnapShotList.h"
#include "structHeaderFunction.h"
#include "oneSnapShot.h"
#include "logFile.h"
#pragma warning(disable:4996)

//resets the head and tail of dll
 DLLName* DLLName_Head = NULL;
 DLLName* DLLName_Tail = NULL;

int countOfDll = 0;

//adds a dll to the linked list
//gets a dll name
void addDLL(char dllName[200]){
	// The function has started
	LogEvent("enter the function (addDLL)");

	


	//if the function (addDLL) gets NULL it will reset the DLLName_Head 
	if (dllName == NULL){
	    //resetting the dll count
	   	countOfDll = 0;
		DLLName_Head = NULL;
		LogEvent("DLLName_Head is reset dllName is NULL");
		LogEvent("The function (addDLL) is done\n");
		return;
	}
	//count the dll, every time a new dll enter to function it is increases by one
	++countOfDll;

	//creates a new place in memory
	DLLName* newDLL = (DLLName*)malloc(sizeof(DLLName));
	if (!newDLL){
	
		//error - No memory allocation
		LogError(strerror(GetLastError()));
		exit(1);
	}

	//add the dll number into the new space
	newDLL->countDLL = countOfDll;

	//add the dll name into the new space
	strcpy(newDLL->nameOfDLL, dllName);

	//resetting the next because there is none
	newDLL->next = NULL;

	//entered only when the first dll is created
	if (DLLName_Head == NULL){
	
		//save the first dll in DLLName_Head
		DLLName_Head = newDLL;

		//the tail always points to the last dll
		DLLName_Tail = newDLL;

		//There is nothing in front of newDLL because it the first
		newDLL->prev = NULL;
	}
	else{
	
		//connecting the old dll to the new dll
		DLLName_Tail->next = newDLL;

	    //connecting the new dll to the old dll
		newDLL->prev = DLLName_Tail;

		//makes the tail be the new dll
		DLLName_Tail = newDLL;
	
	}



	// creates a header struct for dll
	if(countOfDll == 1)
    headerDLLDetails();
	LogEventWithNumber("The function (addDLL) is done and the dll is linked, number\n", countOfDll);
}




//add the checked dll to the origin linked list
//get the tail dll of original process and the new dll that not in original dll linked list of the process 
DLLName* addDLLToExistList(DLLName* TailOfExistDLL, DLLName* newList){
	Loglinebreak();
	LogEvent("enter the function (addDLLToExistList)");

	//increasing the DLL by 1
	 newList->countDLL = TailOfExistDLL->countDLL + 1;

	 //the dll is new and there are no things after him
	 newList->next = NULL;

	 //connecting the new dll to the original linked list
	 TailOfExistDLL->next = newList;

	 //connecting the original linked list to the new dll
     newList->prev = TailOfExistDLL;

	 //makes the tail be the new dll
     TailOfExistDLL = newList;

	 LogEvent("The function (addDLLToExistList) is done and add the checked dll to the origin linked list\n");
	//sends the modified tail
    return TailOfExistDLL;
}



// creates a header struct
void headerDLLDetails(){
	Loglinebreak();
	LogEvent("enter the function (headerDLLDetails)");
	//Updates the version of the dll struct 
	DLLHeaderFile->versionDLLName= versionOfDLL;

	LogEvent("The function (headerDLLDetails) is done and save the header of dll link list\n");
}