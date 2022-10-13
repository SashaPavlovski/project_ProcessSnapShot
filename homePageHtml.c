#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#pragma warning(disable:4996)


int firstTimeInFile = 0;
int firstTimeHomePage = 0;
char seperator;
char nameFile[50] = "";

char* dynamicHtml(char* nameOfFile,char* addString,char* topHtml )
{
	strcpy(nameFile,nameOfFile);
	char* dynamicTable = addString;
	char* htmlFileTemplate = readFromFile();
	firstTimeInFile = 1;

	char* found = strstr(htmlFileTemplate, SEPERATOR);

	int len = found - htmlFileTemplate;

	char* newFileSpace;

	if(topHtml == NULL)
	{
		newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTable));
		strncpy(newFileSpace, htmlFileTemplate, len);
		newFileSpace[len] = NULL;
	}
	else
	{
		newFileSpace = (char*)malloc(strlen(found) +strlen(topHtml) + 1 + strlen(dynamicTable));
		strcpy(newFileSpace, topHtml);
	}
	// find the token

	strcat(newFileSpace, dynamicTable);


	strcat(newFileSpace,found);

	
	char* nameForFile = saveInToFileHTML(newFileSpace);
	
	    //free(newFileSpace);
		//free(htmlFileTemplate);
		//free(topHtml);
		//free(dynamicTable);

		return nameForFile;

}



char* dynamicTitleHtml(char* nameOfFile, char* addString,char* title) {
	newNameOfFile = createNewName(nameOfFile);
	strcpy(nameFile, nameOfFile);
	char* dynamicTitle = title;
	char* htmlFileTemplate = readFromFile();

	// find the token
	char* found = strstr(htmlFileTemplate, SEPERATOR_TITLE);

	int len = found - htmlFileTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTitle));
	if (!newFileSpace)
	{
		//error
		return;
	}

	strncpy(newFileSpace, htmlFileTemplate, len);

	newFileSpace[len] = NULL;
	strcat(newFileSpace, dynamicTitle);
	char* found_2 = strstr(htmlFileTemplate, SEPERATOR);
	int len_2 = found_2 - found;

	strncat(newFileSpace, found, len_2);

	
	newFileSpace[len_2+len+strlen(dynamicTitle)] = NULL;

	
	char* linkName = dynamicHtml(nameOfFile, addString, newFileSpace);


	//free(newFileSpace);
	//free(htmlFileTemplate);
	
	

	

	return linkName;

}
