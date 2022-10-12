#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#pragma warning(disable:4996)


int firstTime = 0;
char seperator;
char nameFile[] = " ";

char* dynamicHtml(char* nameOfFile,char* addString)
{

	strcpy(nameFile,nameOfFile);
	char* dynamicTable = addString;
	char* htmlFileTemplate = readFromFile();
	firstTime = 1;

	// find the token
	char* found = strstr(htmlFileTemplate, SEPERATOR);

	int len = found - htmlFileTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTable));

	strncpy(newFileSpace, htmlFileTemplate, len);

	newFileSpace[len] = NULL;
	strcat(newFileSpace, dynamicTable);


	strcat(newFileSpace,found);

	char* nameForFile = (char*)malloc(50);
	nameForFile = saveInToFileHTML(newFileSpace);
	
	    free(newFileSpace);
		free(htmlFileTemplate);
	
		return nameForFile;

}



char* dynamicTitleHtml(char* nameOfFile, char* addString,char* title) {

	strcpy(nameFile, nameOfFile);
	char* dynamicTitle = title;
	char* htmlFileTemplate = readFromFile();
	firstTime = 1;
	
	// find the token
	char* found = strstr(htmlFileTemplate, SEPERATOR_TITLE);

	int len = found - htmlFileTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTitle));

	strncpy(newFileSpace, htmlFileTemplate, len);

	newFileSpace[len] = NULL;
	strcat(newFileSpace, dynamicTitle);

	strcat(newFileSpace, found);

	char* nameForFile = (char*)malloc(50);
	nameForFile = saveInToFileHTML(newFileSpace);

	free(newFileSpace);
	free(htmlFileTemplate);
	//free(dynamicTitle);
	
	dynamicHtml(nameOfFile, addString);

	return nameForFile;

}
