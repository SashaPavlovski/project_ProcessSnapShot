#include <stdio.h>
#include <stdlib.h>
#include "typesStructs.h"
#include "resetCollectionsFile.h"
#include "structHeaderFunction.h"
#pragma warning(disable:4996)


int restet = 0;
//Creates space to header structs
void headerMalloc()
{
	//sign that resets the space to header structss
	if (restet == 1)
	{
		restet = 0;
		free(snapShotHeaderFile);
		free(processHeaderFile);
		free(DLLHeaderFile);
		return;
	}


	snapShotHeaderFile = (snapShotHeader*)malloc(sizeof(snapShotHeader));
	if (!snapShotHeaderFile)
	{
		//error
		return;
	}

	processHeaderFile = (processHeader*)malloc(sizeof(processHeader));
	if (!processHeaderFile)
	{
		//error
		return;
	}


	DLLHeaderFile = (DLLNameHeaders*)malloc(sizeof(DLLNameHeaders));
	if (!DLLHeaderFile)
	{
		//error
		return;
	}


}
