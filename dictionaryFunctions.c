#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "dictionaryFunctions.h"
#pragma warning(disable:4996)

dictionaryDLL* dictionaryDLL_Head = NULL;
dictionaryDLL* dictionaryDLL_Tail = NULL;

int countnewDictionaryDLL = 0;
int notExistsDLLInList = 0;
char* nameDH = "";
 
//Creates single-valued processes linked list
//add the first snapshot
void dictionaryProcess(snapshot* snapShotList){

	//sign to check all processes in addProcess
	FirstListProcess = 1;

	snapshot* currSnapShot = snapShotList;
	//PROCESS* OldcurrProcess;
	while (currSnapShot != NULL) {

		//Run on all snapshots
	    //Run on all a processes in snapshots

		PROCESS* currProcess = currSnapShot->myprocess;
		

		while(currProcess != NULL) {

			//Checks if the process exists or not
			//and if not add it
			addProcess(currProcess);


			//OldcurrProcess = currProcess;
			currProcess = currProcess->next;
		}

		currSnapShot = currSnapShot->next;
	}

}



//Creates single-valued dictionary dll linked list
//add the first process in a single-valued process linked list
 void dictionaryDLLFunction(PROCESS* sortProcessList){

		PROCESS* currentPro = sortProcessList;
		PROCESS* OldcurrentPro;
		

		dictionaryDLL* currentDictionaryDLL1 = dictionaryDLL_Head;
		DLLName* currentCheckDLL = sortProcessList->dll;

		//Run on all processes
		while (currentPro != NULL)
		{        
			//Run on all a dlls in processes
			currentCheckDLL = currentPro->dll;
		    while (currentCheckDLL != NULL)//dll in process
		    {
				//Run on all a dictionary dll lined list 
				currentDictionaryDLL1 = dictionaryDLL_Head;
		    	while (currentDictionaryDLL1 != NULL)//dictionary dll
		    	{
		            ///checking if the dlls are equal
		    		if (strcmp( currentCheckDLL->nameOfDLL, currentDictionaryDLL1->nameOfDLL) == 0)
		    		{
						//sign that the dll exists in dictionary dll lined list 
						notExistsDLLInList = 1;

						//Checking the location of the dictionary dll which is equal to dll in process
						//and adds the process to the dictionary process linked list in dictionary dll
						//the function add the dll and the process
						checkDictionaryDLL(currentCheckDLL, currentPro);
						//free(currentCheckDLL);

						currentDictionaryDLL1 = dictionaryDLL_Tail;
		    		}
					currentDictionaryDLL1 = currentDictionaryDLL1->next;// if the dlls are  
		    	}

				//enter only if the dll not exists in dictionary dll lined list 
		    	if (notExistsDLLInList != 1)
		    	{
					//adds the dll to the dictionary dll linkad list
		    		addDictionaryDLL(currentCheckDLL, currentPro);
		    
		    	}
				
		    	currentCheckDLL = currentCheckDLL->next;

				//Reset the sign to the next dll
				notExistsDLLInList = 0;
		    }

			OldcurrentPro = currentPro;
		    currentPro = currentPro->next;
		    free(OldcurrentPro);
		}

}


 //adds the dll which does not exist in th list to the dictionary dll linkad list
 //the function add the dll and the process that used him
void addDictionaryDLL(DLLName* nameSortDLL, PROCESS* processSortDLL) {

	//if the function (addDictionaryDLL) gets NULL it will reset the dictionaryDLL_Head 
	if (nameSortDLL == NULL && processSortDLL == NULL)
	{
		//resetting the dictionary dll count
		countnewDictionaryDLL = 0;
		dictionaryDLL_Head = NULL;
		return;
	}
	

	dictionaryDLL* newDictionaryDLL = (dictionaryDLL*)malloc(sizeof(dictionaryDLL));
	if (!newDictionaryDLL)
	{
		//error
		return ;
	}

	//count the dictionary dll, every time a new dictionary dll enter to function it is increases by one
	countnewDictionaryDLL++;
	newDictionaryDLL->countDictionaryDLL = countnewDictionaryDLL;

	//Links the process to the dcionary process linked list 
	MakeProcessDictionary(processSortDLL);

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
	
}




//Checking the location of the dictionary dll which is equal to dll in process
//and adds the process to the dictionary process linked list in dictionary dll
//the function add the dll and the process
void checkDictionaryDLL(DLLName* dDLL, PROCESS* newProDictionary)
{
	dictionaryDLL* moveDictionaryDLL = dictionaryDLL_Head;

	while (moveDictionaryDLL != NULL)
	{
		if (strcmp(moveDictionaryDLL->nameOfDLL, dDLL->nameOfDLL) == 0)
		{
			//adds the process to the dictionary process linked list in dictionary dll
			//the function add the dictionary dll and the process
			 addDictionaryProcess(moveDictionaryDLL, newProDictionary);
			 moveDictionaryDLL = dictionaryDLL_Tail;
		}

		moveDictionaryDLL = moveDictionaryDLL->next;
	}



}

