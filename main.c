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

int main(){
	LogInit("logFile");
	LogEvent("The program has started");
	Loglinebreak();
	//to know if delete the directory dll and processes
	//if the user presses 6
	int HTMLUsed = 0;

	firstTimeHomePage = 0;
	
	//Creates a malloc for the header structs
	headerMalloc();
	LogEvent("back to function (main)");


	while (userResponse != 9)
	{

		printf("Please choose a number:\n 1 Take One SnapShot\n 2 Take 20 SnapShots\n 3 Start Long SnapShot\n 4 End Long SnapShot\n 5 Generate HTML Report\n 6 Reset Collections\n 7 Save in File\n 8 Load from File\n 9 Quit\n");

		scanf("%d", &userResponse);
		LogEventWithNumber("The user chose the number", userResponse);
		switch (userResponse) {
		case 1:
			//Take One SnapShot
			loadFormFile = 0;
			LogEventWithNumber("enter case", userResponse);
			addOneSnapShot(NULL);
			break;

		case 2:
			//Take 20 SnapShots
			loadFormFile = 0;
			LogEventWithNumber("enter case", userResponse);
			addOneSnapShot(NULL);
			break;
		case 3:
			//Start Long SnapShot
			loadFormFile = 0;
			LogEventWithNumber("enter case", userResponse);
			addOneSnapShot(NULL);
			break;

		case 5:
			//Generate HTML Report
			LogEventWithNumber("enter case", userResponse);
			HtmlPage();
			HTMLUsed = 1;
			break;
		case 6:
			//Reset Collections
			LogEventWithNumber("enter case", userResponse);
			if (HTMLUsed == 0) {
				LogEvent("Enters the case where there is no dictionary dll");
				resetCollections(snapshot_Head);

			}
			else {
				LogEvent("Enters the case where there is dictionary dll");
				deleteDictionaryDLLAndPro();
				resetCollections(snapshot_Head);
				HTMLUsed = 0;
			}
			break;

		case 7:
			//Save in File 
			LogEventWithNumber("enter case", userResponse);
			uploadSnapToFile();
			break;

		case 8:
			//Load from File
			LogEventWithNumber("enter case", userResponse);
			loadSnapFromFile();
			break;

		
		case 9:
			//Exit the program
			LogEventWithNumber("enter case", userResponse);
			if (HTMLUsed == 0) {
				LogEvent("Enters the case where there is no dictionary dll");
				resetCollections(snapshot_Head);
			}
			else {
				LogEvent("Enters the case where there is dictionary dll");
				deleteDictionaryDLLAndPro();
				resetCollections(snapshot_Head);
				HTMLUsed = 0;
			}
	    }

		LogEvent("back to the (main) function\n");
	}
	LogEvent("The program has done");
	return 0;
}







