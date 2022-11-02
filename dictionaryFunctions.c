#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "dictionaryFunctions.h"
#include "logFile.h"
#pragma warning(disable:4996)

dictionaryDLL* dictionaryDLL_Head = NULL;
dictionaryDLL* dictionaryDLL_Tail = NULL;

int countnewDictionaryDLL = 0;
int notExistsDLLInList = 0;
char* nameDH = "";
 
//Creates single-valued processes linked list
//add the first snapshot
void dictionaryProcess(snapshot* snapShotList){

	Loglinebreak();
	LogEvent("enter the function (dictionaryProcess)");

	//sign to check all processes in addProcess
	FirstListProcess = 1;

	snapshot* currSnapShot = snapShotList;

	while (currSnapShot != NULL) {

		//Run on all snapshots
	    //Run on all a processes in snapshots

		PROCESS* currProcess = currSnapShot->myprocess;
		
		LogEvent("enter to loop that check if process exists or not and if not add it");
		while(currProcess != NULL) {

			//Checks if the process exists or not
			//and if not add it
			addProcess(currProcess);


			currProcess = currProcess->next;
		}

		currSnapShot = currSnapShot->next;
	}
	LogEvent("The function (dictionaryProcess) is done and created link list of single-valued processes\n");
}



//Creates single-valued dictionary dll linked list
//add the first process in a single-valued process linked list
 void dictionaryDLLFunction(PROCESS* sortProcessList){

	 Loglinebreak();
	 LogEvent("enter the function (dictionaryDLLFunction)");

		PROCESS* currentPro = sortProcessList;
		PROCESS* OldcurrentPro;
		int countOfEqualDll = 0;

		dictionaryDLL* currentDictionaryDLL1 = dictionaryDLL_Head;
		DLLName* currentCheckDLL = sortProcessList->dll;

		LogEvent("enter to loop that check if dll exists or not and if not add it to new strust dictionary dll");
		//Run on all processes
		while (currentPro != NULL){
		       
			//Run on all a dlls in processes
			currentCheckDLL = currentPro->dll;
		    while (currentCheckDLL != NULL){//dll in process
		    
				//Run on all a dictionary dll lined list 
				currentDictionaryDLL1 = dictionaryDLL_Head;
		    	while (currentDictionaryDLL1 != NULL){//dictionary dll
		    	
		            ///checking if the dlls are equal
		    		if (strcmp( currentCheckDLL->nameOfDLL, currentDictionaryDLL1->nameOfDLL) == 0){

						LogEventWithVariable("enter to condition that signifies that the dll exists in dictionary dll lined list,dll name is", currentCheckDLL->nameOfDLL);
						LogEventWithVariable("the name of process is", currentPro->nameOfProcess);

						//sign that the dll exists in dictionary dll lined list 
						notExistsDLLInList = 1;
						countOfEqualDll++;
						//Checking the location of the dictionary dll which is equal to dll in process
						//and adds the process to the dictionary process linked list in dictionary dll
						//the function add the dll and the process
						checkDictionaryDLL(currentCheckDLL, currentPro);
						LogEvent("back to function (dictionaryDLLFunction)");

						//free(currentCheckDLL);

						currentDictionaryDLL1 = dictionaryDLL_Tail;
		    		}
					currentDictionaryDLL1 = currentDictionaryDLL1->next;// if the dlls are  
		    	}

				//enter only if the dll not exists in dictionary dll lined list 
		    	if (notExistsDLLInList != 1){

					LogEvent("enter to condition only if the dll not exists in dictionary dll lined list");

					//adds the dll to the dictionary dll linkad list
		    		addDictionaryDLL(currentCheckDLL, currentPro);
					LogEvent("back to function (dictionaryDLLFunction) after adding the dll to the dictionary dll linkad list");

		    	}
				
		    	currentCheckDLL = currentCheckDLL->next;

				//Reset the sign to the next dll
				notExistsDLLInList = 0;
		    }

			OldcurrentPro = currentPro;
		    currentPro = currentPro->next;
		    free(OldcurrentPro);
		}

		LogEvent("The function (dictionaryDLLFunction) is done and created link list of single-valued dll\n");

 }


 //adds the dll which does not exist in th list to the dictionary dll linkad list
 //the function add the dll and the process that used him
void addDictionaryDLL(DLLName* nameSortDLL, PROCESS* processSortDLL) {

	Loglinebreak();
	LogEvent("enter the function (addDictionaryDLL)");

	//if the function (addDictionaryDLL) gets NULL it will reset the dictionaryDLL_Head 
	if (nameSortDLL == NULL && processSortDLL == NULL){
	
		//resetting the dictionary dll count
		countnewDictionaryDLL = 0;
		dictionaryDLL_Head = NULL;
		LogEvent("dictionaryDLL_Head is reset, nameSortDLL and processSortDLL is NULL");
		LogEvent("The function (addDictionaryDLL) is done\n");
		return;
	}
	

	dictionaryDLL* newDictionaryDLL = (dictionaryDLL*)malloc(sizeof(dictionaryDLL));
	if (!newDictionaryDLL)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}

	//count the dictionary dll, every time a new dictionary dll enter to function it is increases by one
	countnewDictionaryDLL++;
	newDictionaryDLL->countDictionaryDLL = countnewDictionaryDLL;

	//Links the process to the dcionary process linked list 
	MakeProcessDictionary(processSortDLL);
	LogEvent("back to function (newDictionaryDLL)");

	//save in new dictionary dll the head and tail of the dictionary process
	newDictionaryDLL->dictionaryProcessTail = dictionaryProcess_Tail;
	newDictionaryDLL->dictionaryProcessUsed = dictionaryProcess_Head;
	strcpy(newDictionaryDLL->nameOfDLL, nameSortDLL->nameOfDLL);

	//links the new dictionary dll to the linked list
	newDictionaryDLL->next = NULL;
	if (dictionaryDLL_Head == NULL) {
		dictionaryDLL_Head = newDictionaryDLL;
		dictionaryDLL_Tail = newDictionaryDLL;
		newDictionaryDLL->prev = NULL;
	}
	else {
		dictionaryDLL_Tail->next = newDictionaryDLL;
		newDictionaryDLL->prev = dictionaryDLL_Tail;
		dictionaryDLL_Tail = newDictionaryDLL;
	}

	//Reset the dictionaryProcess_Head to the next dictionary dll.
	MakeProcessDictionary(NULL);
	//free(nameSortDLL);
	LogEventWithNumber("The function (newDictionaryDLL) is done and the dictionary dll is linked, number\n", countnewDictionaryDLL);
}




//Checking the location of the dictionary dll which is equal to dll in process
//and adds the process to the dictionary process linked list in dictionary dll
//the function add the dll and the process
void checkDictionaryDLL(DLLName* dDLL, PROCESS* newProDictionary){

	Loglinebreak();
	LogEvent("enter the function (checkDictionaryDLL)");

	dictionaryDLL* moveDictionaryDLL = dictionaryDLL_Head;

	while (moveDictionaryDLL != NULL){
	
		if (strcmp(moveDictionaryDLL->nameOfDLL, dDLL->nameOfDLL) == 0){

			LogEvent("enter to condition when found the location of the dictionary dll");

			//adds the process to the dictionary process linked list in dictionary dll
			//the function add the dictionary dll and the process
			 addDictionaryProcess(moveDictionaryDLL, newProDictionary);

			 LogEvent("back to function (checkDictionaryDLL)");

			 moveDictionaryDLL = dictionaryDLL_Tail;
		}

		moveDictionaryDLL = moveDictionaryDLL->next;
	}

	LogEvent("The function (checkDictionaryDLL) is done and linked the process to the previous process in the same dictionary dll\n");
}

