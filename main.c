#include <stdio.h>
#include <string.h>
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
#include "typesFilesHeader.h"
#include "logFile.h"
#pragma warning(disable:4996)


int userResponse = 0;

int main()
{
	//to know if delete the directory dll and processes
	//if the user presses 6
	int HTMLUsed = 0;

	firstTimeHomePage = 0;
	
	//Creates a malloc for the header structs
	headerMalloc();

	
	while (userResponse != 9)
	{

		printf("Please choose a number:\n 1 Take One SnapShot\n 2 Take 20 SnapShots\n 3 Start Long SnapShot\n 4 End Long SnapShot\n 5 Generate HTML Report\n 6 Reset Collections\n 7 Save in File\n 8 Load from File\n 9 Quit\n");

		scanf("%d", &userResponse);
		switch (userResponse) {
		case 1:
			//Take One SnapShot
			loadFormFile = 0;
			addOneSnapShot(NULL);
			break;

		case 2:
			//Take 20 SnapShots
			loadFormFile = 0;
			addOneSnapShot(NULL);
			break;
		case 3:
			//Start Long SnapShot
			loadFormFile = 0;
			addOneSnapShot(NULL);
			break;

		case 5:
			//Generate HTML Report
			HtmlPage();
			HTMLUsed = 1;
			break;
		case 6:
			//Reset Collections
			if (HTMLUsed == 0) {
				resetCollections(snapshot_Head);

			}
			else {
				deleteDictionaryDLLAndPro();
				resetCollections(snapshot_Head);
				HTMLUsed = 0;
			}
			break;

		case 7:
			//Save in File 
			uploadSnapToFile();
			break;

		case 8:
			//Load from File
			loadSnapFromFile();
			break;

		}

	}
	return 0;
}







