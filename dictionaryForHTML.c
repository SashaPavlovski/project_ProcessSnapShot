#include <stdio.h>
#include <string.h>
#include <time.h>
#include "typesStructs.h"
#include "AcceptingProcess.h"
#include "oneSnapShot.h"
#include "dictionaryFunctions.h"
#include "operationFunction.h"
#include "homePageHTML.h"
#include "homePageDLL.h"
#pragma warning(disable:4996)



extern PROCESS* sortListProcess = NULL;
int countDLLPageHTML = 0;
char* dynamicNav(int DLLCountHTML, int ProceessCountHTML, SIZE_T MemoryAvgHTML);
char* dynamicDLLTable(dictionaryDLL* D_DLLHeadHtml);
char* dynamicNavHtml(char* nameOfFile, char* addString);
char* dinamicTitleProcessesUsed(dictionaryDLL* oneDictionaryDLL);
char* dinamicTableProcessesUsed(dictionaryDLL* oneDictionaryDLL);

void HtmlPage()
{
	countOfCreateFileIndex3 = 0;
	addProcess(NULL);
	addDictionaryDLL(NULL, NULL);
	dictionaryProcess(snapshot_Head);
	sortListProcess = PROCESS_Head;
	int b = PROCESS_Tail->countProcess;
	dictionaryDLLFunction(sortListProcess);
	int a = dictionaryDLL_Tail->countDictionaryDLL;
	SIZE_T c = (SIZE_T)memoryAvgForALLSnapshot();
	char* dataNav = dynamicNav(a,b,c);
	firstTimeHomePage = 1;
	firstTimeInFile = 1;
	dynamicNavHtml("index.html",dataNav);

	dictionaryDLL* currDD = dictionaryDLL_Head;
	firstTimeInFile = 0;
	while (currDD != NULL)
	{
		char* titleDLL = dinamicTitleProcessesUsed(currDD);
		char* tableDLL = dinamicTableProcessesUsed(currDD);
		dynamicTitleHtml("index3.html", tableDLL, titleDLL);
		firstTimeInFile = 0;
		currDD = currDD->next;
	}

	char* nameF = dynamicHtml("index.html",dynamicDLLTable(dictionaryDLL_Head), NULL);
}



char* dynamicNav(int DLLCountHTML, int ProceessCountHTML, SIZE_T MemoryAvgHTML)
{
	char* dataNav = (char*)malloc(sizeof(long));
	dataNav[0] = NULL;
	if (!dataNav)
	{
		//error
		return ;
	}
	sprintf(dataNav,"\n<div> Dll's cnt: %d </div>\n<div> Processes cnt: %d </div>\n<div> Memory avg: %d </div>\n", DLLCountHTML, ProceessCountHTML, MemoryAvgHTML);

	return dataNav;
}




char* dynamicDLLTable(dictionaryDLL* D_DLLHeadHtml)
{
	
	dictionaryDLL* currDictionaryDLL = dictionaryDLL_Head;
	char* dataDLLTable = (char*)malloc(500);
	//dataDLLTable[0] = NULL;
	char* allTheOptions = (char*)malloc(sizeof(dictionaryDLL) * dictionaryDLL_Tail->countDictionaryDLL+100);
	if (!allTheOptions)
	{
		//error
		return;
	}
	allTheOptions[0] = NULL;
	while (currDictionaryDLL != NULL)
	{
		countDLLPageHTML++;

	    if (!dataDLLTable)
	    {
	    	//error
	    	return;
	    }
		sprintf(dataDLLTable, "\n<tr>\n<td> %s </td >\n<td ><a href = \"useDll_%d.html\" >dll%d.html</a></td>\n</tr>\n", currDictionaryDLL->nameOfDLL, countDLLPageHTML, countDLLPageHTML);

		currDictionaryDLL = currDictionaryDLL->next;
		strcat(allTheOptions, dataDLLTable);
	}
	free(dataDLLTable);
	return allTheOptions;
}

char* dinamicTitleProcessesUsed(dictionaryDLL* oneDictionaryDLL)
{

	char* titelProcesses = (char*)malloc(100);
	titelProcesses[0] = NULL;
	if (!titelProcesses)
	{
		//error
		return;
	}
	sprintf(titelProcesses, "<h1> %d process used </h1>", oneDictionaryDLL->dictionaryProcessTail->countDictionaryProcess);

	return titelProcesses;

}


char* dinamicTableProcessesUsed(dictionaryDLL* oneDictionaryDLL)
{
	S_dictionaryProcess* processesOfDDLL = oneDictionaryDLL->dictionaryProcessUsed;
	char* tableProcesses = (char*)malloc(10000);
	tableProcesses[0] = NULL;
	char* allTheOptions = (char*)malloc(sizeof(S_dictionaryProcess)* oneDictionaryDLL->dictionaryProcessTail->countDictionaryProcess + 100000);
	allTheOptions[0] = NULL;
	if (!allTheOptions)
	{
		//error
		return;
	}
	while (processesOfDDLL != NULL)
	{

	     if (!tableProcesses)
	     {
	     	//error
	     	return;
	     }
	     sprintf(tableProcesses, "\n<tr>\n<td> %d </td>\n<td> %s </td>\n</tr>\n", processesOfDDLL->countDictionaryProcess, processesOfDDLL->nameOfProcess);
		 processesOfDDLL = processesOfDDLL->next;
		 strcat(allTheOptions, tableProcesses);
	}
	free(tableProcesses);
	return allTheOptions;

}





