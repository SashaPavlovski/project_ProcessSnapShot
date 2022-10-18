#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#include "homePageDLL.h"
#pragma warning(disable:4996)


int firstTimeInFile = 0;
int firstTimeHomePage = 0;
char seperator;
char nameFile[50] = "";

char* dynamicHtml(char* nameOfFile, char* addString, char* topHtml)
{
	strcpy(nameFile, nameOfFile);
	char* dynamicTable = addString;
	char* htmlFileTemplate = readFromFile();
	firstTimeInFile = 1;
	char* found = "";
	int len;
	char* newFileSpace;

	if (topHtml == NULL)
	{
		if (countDLLPageHTML > 0) {
			countDLLPageHTML = 0;
			found = strstr(htmlFileTemplate, SEPERATOR_TEMP);
			len = found - htmlFileTemplate;
		}
		else
		{
			found = strstr(htmlFileTemplate, SEPERATOR);
			len = found - htmlFileTemplate;
		}
		newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + 1 + strlen(dynamicTable));
		strncpy(newFileSpace, htmlFileTemplate, len);
		newFileSpace[len] = NULL;
	}
	else
	{

		found = strstr(htmlFileTemplate, SEPERATOR);
		newFileSpace = (char*)malloc(strlen(found) + strlen(topHtml) + 2 + strlen(dynamicTable));
		//newFileSpace = "";
		strcpy(newFileSpace, topHtml);
		//free(topHtml);
	}
	// find the token
	strcat(newFileSpace, dynamicTable);
	strcat(newFileSpace, found);
	char* nameForFile = saveInToFileHTML(newFileSpace);
	free(htmlFileTemplate);
	//free(dynamicTable);
	return nameForFile;

}





char* dynamicTitleHtml(char* nameOfFile, char* addString, char* title) {

	newNameOfFile = createNewName(nameOfFile);
	strcpy(nameFile, nameOfFile);
	char* dynamicTitle = title;
	char* htmlFileTemplate = readFromFile();

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
	newFileSpace[len_2 + len + strlen(dynamicTitle)] = NULL;
	char* linkName = dynamicHtml(nameOfFile, addString, newFileSpace);


	//free(dynamicTitle);
	free(htmlFileTemplate);

	return linkName;
}



char* dynamicNavHtml(char* nameOfFile, char* addString) {

strcpy(nameFile, nameOfFile);
char* dynamicTitle = addString;
char* htmlFileTemplate = readFromFile();

char* found = strstr(htmlFileTemplate, SEPERATOR_NAV);


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
strcat(newFileSpace, found);
char* nameForFile = saveInToFileHTML(newFileSpace);


//free(dynamicTitle);
free(htmlFileTemplate);

return nameForFile;
}