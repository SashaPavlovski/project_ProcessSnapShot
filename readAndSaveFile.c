#include <stdlib.h> 
#include <stdio.h>
#include "homePageHTML.h"
#pragma warning(disable:4996)


FILE* file;

char* readFromFile()
{

	if (firstTime == 0)
	{
		file = fopen("index.html", "r");
		if (!file)
		{
			//error
			return 0;
		}
	}
	else
	{
		file = fopen("updatedHtmlFile.html", "r");
		if (!file)
		{
			//error
			return 0;
		}
	}

	char* temp = (char*)malloc(10000);
	int originFileSize = 0;
		while (fread(temp, sizeof(char), 1, file))
		{
			originFileSize++;
		}

		fclose(file);
	    free(temp);




		if (firstTime == 0)
		{
			file = fopen("index.html", "r");
			if (!file)
			{
				//error
				return 0;
			}
		}
		else
		{
			file = fopen("updatedHtmlFile.html", "r");
			if (!file)
			{
				//error
				return 0;
			}
		}

	 char* originFile = (char*)malloc(sizeof(char)* originFileSize);

	 fread(originFile, sizeof(char), originFileSize, file);
	 originFile[originFileSize] = NULL;

	 fclose(file);

	 return originFile;
	
}



void saveInToFileHTML(char* newFile)
{
	//enter the function PhotoCopying
	file = fopen("updatedHtmlFile.html", "w");
	if (!file)
	{
		//error - The file (PhotoCopying.html) did not open
		exit(1);
	}
	//The file (newName) was opened successfully

	fputs(newFile, file);
	fclose(file);

	//The file (PhotoCopying.html) is closed, the function PhotoCopying is finished
}







