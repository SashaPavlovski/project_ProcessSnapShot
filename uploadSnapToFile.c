#include <stdio.h>
#include <stdlib.h> 
#include "typesStructs.h"
#include "typesFilesHeader.h"
#include "fileFunction.h"
#include "logFile.h"
#pragma warning(disable:4996)

snapShotHeader* snapShotHeaderFile = NULL;
processHeader* processHeaderFile = NULL;
DLLNameHeaders* DLLHeaderFile = NULL;

char fileName[50] = "";
//Uploads the samples into a file
void uploadSnapToFile() {

	Loglinebreak();
	LogEvent("enter the function (uploadSnapToFile)");

	int write;
	if (snapShotHeaderFile->versionSnapShot == NULL )
	{
		//the snapShotHeaderFile not exists
		LogEvent("There are no  existing Snapshots");
		return;
	}
	printf("enter name for file\n");
	scanf("%s", fileName);
	FILE* f = fopen(fileName, "wb");
	if (!f)
	{
		LogError(strerror(GetLastError()));

		exit(1);
	}

	LogEvent("The file is opened for writing");

	write = fwrite(snapShotHeaderFile,sizeof(snapShotHeader),1,f);
	if (!write)
	{
		//error
		LogError(strerror(GetLastError()));

		return;
	}
	write = fwrite(processHeaderFile, sizeof(processHeader), 1, f);
	if (!write)
	{
		//error
		LogError(strerror(GetLastError()));

		return;
	}
	
	write = fwrite(DLLHeaderFile, sizeof(DLLNameHeaders), 1, f);
	if (!write)
	{
			//error
		LogError(strerror(GetLastError()));

		return;
	}

	LogEvent("all the header structs were read");


	snapshot* currentSnapShot = snapshot_Head;
	PROCESS* currentProcess = currentSnapShot->myprocess;
	DLLName* currentDLL = currentProcess->dll;

	while (currentSnapShot != NULL)
	{
	     write = fwrite(currentSnapShot, sizeof(snapshot), 1, f);
		 if (!write)
		 {
			 //error
			 LogError(strerror(GetLastError()));

			 return;
		 }
		 LogEventWithNumber("Read snapShot", currentSnapShot->countSnapsNumber);

		 currentProcess = currentSnapShot->myprocess;

		 while (currentProcess != NULL)
		 {
			 write = fwrite(currentProcess, sizeof(PROCESS), 1, f);
			 if (!write)
			 {
				 //error
				 LogError(strerror(GetLastError()));

				 return;
			 }
			 LogEventWithNumber("load process", currentProcess->countProcess);

			 currentDLL = currentProcess->dll;

			 while (currentDLL != NULL)
			 {
				 write = fwrite(currentDLL, sizeof(DLLName), 1, f);
				 if (!write)
				 {
					 //error
					 LogError(strerror(GetLastError()));

					 return;
				 }
				 LogEventWithNumber("load dll", currentDLL->countDLL);

				 currentDLL = currentDLL->next;
			 }


			 currentProcess = currentProcess->next;

		 }

		currentSnapShot = currentSnapShot->next;
	}
	fclose(f);

	LogEvent("The file is closed and the function (uploadSnapToFile) is done\n");
}


