#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"

#pragma warning(disable:4996)


FILE* file;
FILE* fileR;
char* readFromFile() {
	

	if (firstTime == 0)
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
		fileR = fopen("samplePage.html", "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile,"index3.html") == 0)
	{
		fileR = fopen("useDll.html", "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}



    // Get the file size
    char* buff = (char*)malloc(1000000);
	if (!buff)
	{
		return 1;
	}
    char* read;
    int fileSize = 0;
    while ((read = fgets(buff, 1000, fileR)))
    {
	fileSize += strlen(buff);
    }
    
    free(buff);
    fclose(fileR);
    fileSize++;
    // alloc space as file size
    buff = (char*)malloc(fileSize);
    
	if (firstTime == 0)
	{
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
		fileR = fopen("samplePage.html", "r");
		if (!fileR)
		{
			//error
			return 0;
		}
	}
	else if (strcmp(nameFile, "index3.html") == 0)
	{
		fileR = fopen("useDll.html", "r");
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
    	buff[readPosition] = charToRead;
    	readPosition++;
    }
    buff[readPosition] = NULL;
    
    fclose(fileR);
    
    return buff;

}







/*

char* readFromFile()
{
	FILE* f;
	if (firstTime == 0)
	{
		f = fopen("index.html", "r");
		if (!f)
		{
			//error
			return 0;
		}
	}
	else
	{
		f = fopen("updatedHtmlFile.html", "r");
		if (!f)
		{
			//error
			return 0;
		}
	}

	char* temp = (char*)malloc(10000);
	int originFileSize = 0;
	while (fread(temp, sizeof(char), 1, f))
	{
		originFileSize++;
	}

	fclose(f);
	free(temp);
	originFileSize++;


		if (firstTime == 0)
		{
			f = fopen("index.html", "r");
			if (!f)
			{
				//error
				return 0;
			}
		}
		else
		{
			f = fopen("updatedHtmlFile.html", "r");
			if (!f)
			{
				//error
				return 0;
			}
		}

	 char* originFile =(char*) malloc(sizeof(originFileSize));
	 free(originFile);

	 fread(originFile, sizeof(char), originFileSize, f);
	 int a = strlen(originFile);
	 originFile[originFileSize] = NULL;
	 a = strlen(originFile);
	 fclose(f);
	 return originFile;
	
}
*/



char* saveInToFileHTML(char* newFile)
{
	//enter the function PhotoCopying
	if (strcmp(nameFile, "index.html") == 0)
	{
	   file = fopen("homePage.html", "w");
	   if (!file)
	   {
	    	//error - The file (PhotoCopying.html) did not open
	    	return "homePage.html";
	   }
	   //The file (newName) was opened successfully
	   
	   fputs(newFile, file);
	   fclose(file);
    }
    else if (strcmp(nameFile, "index2.html") == 0)
    {
        file = fopen("samplePage.html", "w");
        if (!file)
        {
        	 //error - The file (PhotoCopying.html) did not open
        	 return "samplePage.html";
        }
        //The file (newName) was opened successfully
    
        fputs(newFile, file);
        fclose(file);
    }
	else if (strcmp(nameFile, "index3.html") == 0)
	{
		file = fopen("useDll.html", "w");
		if (!file)
		{
			//error - The file (PhotoCopying.html) did not open
			return "useDll.html";
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
	//The file (PhotoCopying.html) is closed, the function PhotoCopying is finished
}







