#include <stdio.h>
#include <stdlib.h>
#include "typesStructs.h"
#include "resetCollectionsFile.h"
#include "structHeaderFunction.h"
#include "logFile.h"
#pragma warning(disable:4996)


int restet = 0;
//Creates space to header structs
void headerMalloc(){

	Loglinebreak();
	LogEvent("enter the function (headerMalloc)");

	//sign that resets the space to header structss
	if (restet == 1){
	
		restet = 0;
		free(snapShotHeaderFile);
		free(processHeaderFile);
		free(DLLHeaderFile);
		LogEvent("headerMalloc were released");
		LogEvent("The function (headerMalloc) is done\n");
		return;
	}


	snapShotHeaderFile = (snapShotHeader*)malloc(sizeof(snapShotHeader));
	if (!snapShotHeaderFile)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}

	processHeaderFile = (processHeader*)malloc(sizeof(processHeader));
	if (!processHeaderFile)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}


	DLLHeaderFile = (DLLNameHeaders*)malloc(sizeof(DLLNameHeaders));
	if (!DLLHeaderFile)
	{
		//error
		LogError(strerror(GetLastError()));
		return;
	}

	LogEvent("The function (headerMalloc) is done and created 3 Allocations for header stucts\n");
}
