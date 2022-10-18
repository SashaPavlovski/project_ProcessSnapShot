#include <stdio.h>
#include <string.h>
#include <time.h>
#include "typesStructs.h"
#include "fileFunction.h"
#include "AcceptingProcess.h"
#include "oneSnapShot.h"
#include "resetCollectionsFile.h"
#include "structHeaderFunction.h"
#include "homePageHTML.h"
#include "dictionaryFunctions.h"
#include "homePageDLL.h"
#include "resetCollectionsFile.h"
#pragma warning(disable:4996)


int userResponse = 0;
char str[100] = "";
int main()
{
	int HTMLUsed = 0;
	firstTimeHomePage = 0;
	headerMalloc();
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	int a = 1;

	while (userResponse != 9)
	{

		printf("Please type a number:\n 1 Take One SnapShot\n 2 Take 20 SnapShots\n 3 Start Long SnapShot\n 4 End Long SnapShot\n 5 Generate HTML Report\n 6 Reset Collections\n 7 Save in File\n 8 Load from File\n 9 Quit\n");

		scanf("%d", &userResponse);
		switch (userResponse) {
		case 1:

			sprintf(str, "%d.%d.%d/%d:%d:%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			addOneSnapShot(NULL);
			//Take One SnapShot
			break;

		case 2:

			sprintf(str, "%d.%d.%d/%d:%d:%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			addOneSnapShot(NULL);
			//Take 20 SnapShots
			break;
		case 3:

			sprintf(str, "%d.%d.%d/%d:%d:%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			addOneSnapShot(NULL);
			//Start Long SnapShot
			break;

		case 5:
			HtmlPage();
			HTMLUsed = 1;
			//Generate HTML Report
			break;
		case 6:
			
			a = 1;
			if (HTMLUsed == 0) {
				resetCollections(snapshot_Head);

			}
			else {
				deleteDictionaryDLLAndPro();
				resetCollections(snapshot_Head);
				HTMLUsed = 0;
			}
			//Reset Collections
			break;

		case 7:

			uploadSnapToFile();
			//Save in File 
			break;

		case 8:
			
			loadSnapFromFile();
			//Load from File
			break;

		case 9:
			countOfCreateFileIndex2 = 0;
			countOfCreateFileIndex3 = 0;
			firstTimeInFile = 0;
			firstTimeHomePage = 0;
			//free(newNameOfFile);
			saveInToFileHTML(readFromFile());
			break;
		}


	}
	return 0;
}







