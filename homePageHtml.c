#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#include "homePageDLL.h"
#include "logFile.h"
#pragma warning(disable:4996)


int firstTimeInFile = 0;
int firstTimeHomePage = 0;
char seperator;
char nameFile[50] = "";

//Creates a pages of home page and simples pages.
//connector between the titles and the tables
//add the name of origin file, the content of page and the title of page.
char* dynamicHtml(char* nameOfFile, char* addString, char* topHtml){

	Loglinebreak();
	LogEvent("enter the function (dynamicHtml)");

	strcpy(nameFile, nameOfFile);
	char* dynamicTable = addString;
	//The file is read
	char* htmlFileTemplate = readFromFile();
	LogEvent("back to function (dynamicHtml)");
	firstTimeInFile = 1;
	char* found = "";
	int len;
	char* newFileSpace = "";

	//dont have a title
	if (topHtml == NULL){
	
		LogEvent("enter to condition that not have a title");
	
		if (countDLLPageHTML > 0){

			LogEvent("enter to condition that mean this is not a first dictionary dll page");
			//sing that this is not a first dictionary dll page.
			countDLLPageHTML = 0;
			found = strstr(htmlFileTemplate, SEPERATOR_TEMP);
			len = found - htmlFileTemplate;
		}
		else{

			LogEvent("enter to condition that mean this is the first dictionary dll page");
			found = strstr(htmlFileTemplate, SEPERATOR);
			len = found - htmlFileTemplate;
		}

		//saving the entire top before adding dynamic data.
		newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTable));
		strncpy(newFileSpace, htmlFileTemplate, len);
		newFileSpace[len] = NULL;
		LogEvent("saving the entire top part in a variable");
	}
	else{

		LogEvent("enter to condition that have a title");
		//saves the top part of the source file.
		found = strstr(htmlFileTemplate, SEPERATOR);
		newFileSpace = (char*)malloc(strlen(found) + strlen(topHtml) + 1 + strlen(dynamicTable));
		LogEvent("saving the top part in a variable");
		strcpy(newFileSpace, topHtml);
	}
	// adding dynamic part.
	strcat(newFileSpace, dynamicTable);
	strcat(newFileSpace, found);

	//saved the file
	char* nameForFile = saveInToFileHTML(newFileSpace);
	LogEvent("back to function (dynamicHtml)");
	free(htmlFileTemplate);
	
	LogEventWithVariable("The function (dynamicHtml) is done and created html pages, name", nameForFile);
	Loglinebreak();

	return nameForFile;
}




//Creates a dinamic title part and sends to the dynamicHtml function
//add the name of origin file, the content of page and the title of page.
char* dynamicTitleHtml(char* nameOfFile, char* addString, char* title) {

	Loglinebreak();
	LogEvent("enter the function (dynamicTitleHtml)");

	//Creates new names for files
	newNameOfFile = createNewName(nameOfFile);
	LogEventWithVariable("back to function (dynamicTitleHtml). new name is", newNameOfFile);

	strcpy(nameFile, nameOfFile);
	char* dynamicTitle = title;
	//The file is read
	char* htmlFileTemplate = readFromFile();
	LogEvent("back to function (dynamicTitleHtml)");

	char* found = strstr(htmlFileTemplate, SEPERATOR_TITLE);
	

	int len = found - htmlFileTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTitle));
	if (!newFileSpace){
	
		//error
		LogError(strerror(GetLastError()));
		return;
	}

	strncpy(newFileSpace, htmlFileTemplate, len);
	newFileSpace[len] = NULL;
	strcat(newFileSpace, dynamicTitle);
	char* found_2 = strstr(htmlFileTemplate, SEPERATOR);
	int len_2 = found_2 - found;
	strncat(newFileSpace, found, len_2);
	newFileSpace[len_2 + len + strlen(dynamicTitle)] = NULL;

	LogEvent("created and sends the top part together with the title");
	//sends the top part together with the title.
	char* linkName = dynamicHtml(nameOfFile, addString, newFileSpace);
	

	//free(dynamicTitle);
	free(htmlFileTemplate);

	LogEventWithVariable("The function (dynamicTitleHtml) is done and created html pages, name", linkName);
	Loglinebreak();

	//sends the name of file to home page samples link.
	return linkName;
}


//Creates a html nav in home page.
//add the name of origin file and the nav data.
char* dynamicNavHtml(char* nameOfFile, char* addString) {

	 Loglinebreak();
	 LogEvent("enter the function (dynamicNavHtml)");
     nameFile[50] = "";
     strcpy(nameFile, nameOfFile);
     char* dynamicTitle = addString;

	 //The file is read
     char* htmlFileTemplate = readFromFile();
     
     char* found = strstr(htmlFileTemplate, SEPERATOR_NAV);
     
     
     int len = found - htmlFileTemplate;
     char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 2 + strlen(dynamicTitle));
     if (!newFileSpace){
     
     	//error
		 LogError(strerror(GetLastError()));
     	return;
     }
     
     strncpy(newFileSpace, htmlFileTemplate, len);
     newFileSpace[len] = NULL;
     strcat(newFileSpace, dynamicTitle);
     strcat(newFileSpace, found);
     char* nameForFile = saveInToFileHTML(newFileSpace);
     
     
     //free(dynamicTitle);
     free(htmlFileTemplate);
	 
	// LogEvent("The function (dynamicNavHtml) is done and created html nave in home page");
	 //Loglinebreak();

     return nameForFile;
}