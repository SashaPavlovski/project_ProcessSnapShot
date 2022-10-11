#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#pragma warning(disable:4996)


int firstTime = 0;

void dynamicHtml()
{
	char dynamicTable[] = "<tr>\n<td> 1 </td>\n<td> Samples1.html- </td>\n<td> 2 </td>\n<td> Samples2.html </td>\n<td> 2 </td>\n</tr>\n";
	char* htmlFileTemplate = readFromFile();
	firstTime = 1;

	// find the token
	char* found = strstr(htmlFileTemplate, SEPERATOR);

	int len = found - htmlFileTemplate;
	char* newFileSpace = (char*)malloc(strlen(htmlFileTemplate) + strlen(dynamicTable));

	strncpy(newFileSpace, htmlFileTemplate, len);
	newFileSpace[len] = NULL;

	strcat(newFileSpace, dynamicTable);
	//newFileSpace[len + strlen(dynamicTable)] = NULL;

	strcat(newFileSpace,found);


	saveInToFileHTML(newFileSpace);
	

	free(newFileSpace);
	free(htmlFileTemplate);


}



int main()
{

	dynamicHtml();

	return;
}












