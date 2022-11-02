#include <stdio.h>
#include <string.h>
#include "typesStructs.h"
#include "homePageHTML.h"
#include "oneSnapShot.h"
#include "dictionaryFunctions.h"
#include "operationFunction.h"
#include "dinamicHomePage.h"
#include "homePageDLL.h"
#include "logFile.h"
#pragma warning(disable:4996)


int countDLLPageHTML = 0;
extern PROCESS* sortListProcess = NULL;


//Builds the home page
//Builds the dll pages
void HtmlPage(){
	
	Loglinebreak();
	LogEvent("enter the function (HtmlPage)");

	//Resetting the count of the dll files
	countOfCreateFileIndex3 = 0;

	//Reset the PROCESS_Head 
	addProcess(NULL);
	LogEvent("back to function (HtmlPage)");

	//Reset the dictionaryDLL_Head 
	addDictionaryDLL(NULL, NULL);
	LogEvent("back to function (HtmlPage)");

	//creating a linked list of single-valued processes
	//add a first snapshot
	dictionaryProcess(snapshot_Head);
	LogEvent("back to function (HtmlPage)");


	//Saving in a variable the new process linked list
	sortListProcess = PROCESS_Head;

	int amountProcesses = PROCESS_Tail->countProcess;

	//creating a linked list of single-valued dll which includes the processes that used it dll.
	//add a first new process that already single-valued in linked list
	dictionaryDLLFunction(sortListProcess);
	LogEvent("back to function (HtmlPage)");


	int amountDictionaryDLL = dictionaryDLL_Tail->countDictionaryDLL;

	//Calculates the average all the memory that the processes use in all the samples together
	SIZE_T averageProcessM = (SIZE_T)memoryAvgForALLSnapshot();
	LogEvent("back to function (HtmlPage)");

	//Creates on the home page the Dll's cnt, Processes cnt and Memory avg
	char* dataNav = dynamicNav(amountDictionaryDLL, amountProcesses, averageProcessM);
	LogEvent("back to function (HtmlPage)");

	//update that is not the first time that we want to save something on the home page
	firstTimeHomePage = 1;

	firstTimeInFile = 1;
	//Save the nav data on the home page
	dynamicNavHtml("index.html",dataNav);
	free(dataNav);
	LogEvent("back to function (HtmlPage)");

	dictionaryDLL* currDD = dictionaryDLL_Head;
	firstTimeInFile = 0;

	LogEvent("enter to loop that create processes pages for each dictionary dll");
	while (currDD != NULL){
	
		//create title for the page
		char* titleDLL = dinamicTitleProcessesUsed(currDD);

		//create table for the page
		char* tableDLL = dinamicTableProcessesUsed(currDD);

		//Create each dll, table and title of all the processes that used him
		dynamicTitleHtml("index3.html", tableDLL, titleDLL);

		//reset to pass to new dll page
		firstTimeInFile = 0;
		currDD = currDD->next;
	}
	LogEvent("back to function (HtmlPage) and created the pages");

	//Saving the dll table on the home page
	char* nameF = dynamicHtml("index.html",dynamicDLLTable(dictionaryDLL_Head), NULL);

	LogEvent("The function (HtmlPage) is done and created a processes pages on the home pages\n");
}


//Creates html line whit Dll's cnt, Processes cnt and Memory avg
char* dynamicNav(int DLLCountHTML, int ProceessCountHTML, SIZE_T MemoryAvgHTML){

	Loglinebreak();
	LogEvent("enter the function (dynamicNav)");

	char* dataNav = (char*)malloc((sizeof(int) * 2) + sizeof(SIZE_T) + 10000);
	if (!dataNav){
	
		//error
		LogError(strerror(GetLastError()));
		return ;
	}
	sprintf(dataNav,"\n<div> Dll's cnt: %d </div>\n<div> Processes cnt: %d </div>\n<div> Memory avg: %llu </div>\n", DLLCountHTML, ProceessCountHTML, MemoryAvgHTML);

	//Returns the line
	LogEvent("The function (dynamicNav) is done and created dlls cnt, Processes cnt and Memory avg\n");
	return dataNav;
}



//Creates the table of single-valued dlls
//add a dictionaryDLL_Head
char* dynamicDLLTable(dictionaryDLL* D_DLLHeadHtml){

	Loglinebreak();
	LogEvent("enter the function (dynamicDLLTable)");

	dictionaryDLL* currDictionaryDLL = D_DLLHeadHtml;
	char* dataDLLTable = (char*)malloc(500);
	char* allTheOptions = (char*)malloc(sizeof(dictionaryDLL) * dictionaryDLL_Tail->countDictionaryDLL+100);
	if (!allTheOptions){
	
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	allTheOptions[0] = NULL;
	while (currDictionaryDLL != NULL){
	
		//Count the number of dictionary dll
		countDLLPageHTML++;

	    if (!dataDLLTable){
	    
	    	//error
			LogError(strerror(GetLastError()));
	    	return;
	    }
		sprintf(dataDLLTable, "\n<tr>\n<td><div class=\"dllName\"> %s </div></td >\n<td><div class=\"link\"><a href = \"useDll_%d.html\">dll%d.html</a></div></td>\n</tr>\n", currDictionaryDLL->nameOfDLL, countDLLPageHTML, countDLLPageHTML);

		currDictionaryDLL = currDictionaryDLL->next;

		//Connects each line that is created (dataDLLTable) to one place (allTheOptions)
		strcat(allTheOptions, dataDLLTable);
	}
	free(dataDLLTable);

	LogEventWithNumber("The function (dynamicDLLTable) is done and created single-valued dlls table , number of dlls in table is", countDLLPageHTML);
	Loglinebreak();

	//returns the entire created table
	return allTheOptions;
}


//Creates the title of used processes count in one dictionary dll
//add a dictionary dll
char* dinamicTitleProcessesUsed(dictionaryDLL* oneDictionaryDLL){

	Loglinebreak();
	LogEvent("enter the function (dinamicTitleProcessesUsed)");


	char* titelProcesses = (char*)malloc(100);
	titelProcesses[0] = NULL;
	if (!titelProcesses){
	
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	sprintf(titelProcesses, "<h1 class=\"toptitle\"> %d process used </h1>", oneDictionaryDLL->dictionaryProcessTail->countDictionaryProcess);

	LogEventWithNumber("The function (dinamicTitleProcessesUsed) is done and created single-valued dlls title , number of dll is", oneDictionaryDLL->dictionaryProcessTail->countDictionaryProcess);
	Loglinebreak();

	//Returns the title
	return titelProcesses;

}



//Creates the table of used processes name in one dictionary dll
//add a dictionary dll
char* dinamicTableProcessesUsed(dictionaryDLL* oneDictionaryDLL){

	Loglinebreak();
	LogEvent("enter the function (dinamicTableProcessesUsed)");

	S_dictionaryProcess* processesOfDDLL = oneDictionaryDLL->dictionaryProcessUsed;
	char* tableProcesses = (char*)malloc(10000);
	tableProcesses[0] = NULL;
	char* allTheOptions = (char*)malloc(sizeof(S_dictionaryProcess) * oneDictionaryDLL->dictionaryProcessTail->countDictionaryProcess + 100000);
	allTheOptions[0] = NULL;
	if (!allTheOptions){
	
		//error
		LogError(strerror(GetLastError()));
		return;
	}
	while (processesOfDDLL != NULL){
	

	     if (!tableProcesses){
	     
	     	//error
			 LogError(strerror(GetLastError()));
	     	return;
	     }
	     sprintf(tableProcesses, "\n<tr>\n<td> <div class=\"processId\"> %d </div></td>\n<td><div class=\"processName\"> %s </div></td>\n</tr>\n", processesOfDDLL->countDictionaryProcess, processesOfDDLL->nameOfProcess);
		 processesOfDDLL = processesOfDDLL->next;

		 //Connects each line that is created (tableProcesses) to one place (allTheOptions)
		 strcat(allTheOptions, tableProcesses);
	}
	free(tableProcesses);

	LogEvent("The function (dinamicTableProcessesUsed) is done and created processes tables for each dictionary dll");
	Loglinebreak();

	//returns the entire created table
	return allTheOptions;

}





