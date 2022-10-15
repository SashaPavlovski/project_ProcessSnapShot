#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"

#pragma warning(disable:4996)


FILE* file;
FILE* fileR;
int countOfCreateFileIndex2 = 1;
int countOfCreateFileIndex3 = 1;


//know which file to open
char* newNameOfFile = 0;


char* readFromFile() {
	

	if (firstTimeInFile == 0 && strcmp(nameFile, "index.html") != 0)
	{
		fileR = fopen(nameFile, "r");
		if (!fileR)
		{
			return NULL;
		}

	}
	else if (firstTimeHomePage == 0&& firstTimeInFile == 0)
	{
		fileR = fopen(nameFile, "r");
		if (!fileR)
		{
			return NULL;
		}
	}
	else if (strcmp(nameFile,"index.html")==0)
	{
		fileR = fopen("homePage.html", "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile, "index2.html") == 0)
	{
		fileR = fopen(newNameOfFile, "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile,"index3.html") == 0)
	{
		fileR = fopen(newNameOfFile, "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}



    // Get the file size
    char* charCount = (char*)malloc(10000);
	if (!charCount)
	{
		return 1;
	}
    char* read;
    int fileSize = 0;
    while ((read = fgets(charCount, 1000, fileR)))
    {
	    fileSize += strlen(charCount);
    }
    
    free(charCount);
    fclose(fileR);
    fileSize += 2;




    // alloc space as file size
	char* inThefile = (char*)malloc(fileSize);
	if (!inThefile)
	{
		return 1;
	}




	if (firstTimeInFile == 0 && strcmp(nameFile, "index.html") != 0)
	{
		fileR = fopen(nameFile, "r");
		if (!fileR)
		{
			return NULL;
		}

	}
	else if (firstTimeHomePage == 0 && firstTimeInFile == 0)
	{
		firstTimeHomePage = 1;
		fileR = fopen(nameFile, "r");
		if (!fileR)
		{
			return NULL;
		}
	}
	else if (strcmp(nameFile, "index.html") == 0)
	{
		fileR = fopen("homePage.html", "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile, "index2.html") == 0)
	{
		fileR = fopen(newNameOfFile, "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile, "index3.html") == 0)
	{
		fileR = fopen(newNameOfFile, "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}

    int readPosition = 0;
    char charToRead;
    while ((charToRead = fgetc(fileR)) != EOF)
    {
		inThefile[readPosition] = charToRead;
    	readPosition++;
    }
	inThefile[readPosition] = NULL;
	
    
    fclose(fileR);
    return inThefile;

}




char* saveInToFileHTML(char* newFile)
{
	//enter the function PhotoCopying
	if (strcmp(nameFile, "index.html") == 0)
	{
	   file = fopen("homePage.html", "w");
	   if (!file)
	   {
	    	//error - The file (PhotoCopying.html) did not open
	    	return 1;
	   }

	   //The file (newName) was opened successfully
	   fputs(newFile, file);
	   fclose(file);
	  
    }
    else if (strcmp(nameFile, "index2.html") == 0)
    {
        file = fopen(newNameOfFile, "w");
        if (!file)
        {
        	//error - The file (PhotoCopying.html) did not open
			return 1;
        }

        //The file (newName) was opened successfully
        fputs(newFile, file);
        fclose(file);
    }
	else if (strcmp(nameFile, "index3.html") == 0)
	{
		file = fopen(newNameOfFile, "w");
		if (!file)
		{
			//error - The file (PhotoCopying.html) did not open
			return 1;
		}

		//The file (newName) was opened successfully
		fputs(newFile, file);
		fclose(file);
	}
	else
	{
		//no exist file
		printf("no exist file\n");
		return 1;
	}
	free(newFile);
	return newNameOfFile;
	//The file (PhotoCopying.html) is closed, the function PhotoCopying is finished
}







char* createNewName(char* nameOfOriginFile) {

	char* newNameFile = (char*)malloc(30);

	if (strcmp(nameOfOriginFile, "index2.html") == 0)
	{
	    sprintf(newNameFile, "samplePage_%d.html", countOfCreateFileIndex2);
	    countOfCreateFileIndex2++;

	    return newNameFile;
	}
	else if (strcmp(nameOfOriginFile, "index3.html") == 0)
	{
		sprintf(newNameFile, "useDll_%d.html", countOfCreateFileIndex3);
		countOfCreateFileIndex3++;

		return newNameFile;
	}
	else
	{
		return NULL;
	}
}