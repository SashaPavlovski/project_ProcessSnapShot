#include <stdio.h>
#include <stdlib.h>
#include "typesStructs.h"
#include "homePageHTML.h"
#pragma warning(disable:4996)

extern int 	numberOfIndex = 0;

void deleteDictionaryDLLAndPro()
{
	saveInToFileHTML(readFromFile());
	dictionaryDLL* currDictionary = dictionaryDLL_Head;
	dictionaryDLL* OldCurrDictionary;
	S_dictionaryProcess* currDictionaryPro = currDictionary->dictionaryProcessUsed;
	S_dictionaryProcess* OldCurrDictionaryPro;

	while (currDictionary != NULL) {

		currDictionaryPro = currDictionary->dictionaryProcessUsed;
		while (currDictionaryPro != NULL) {

			OldCurrDictionaryPro = currDictionaryPro;
			currDictionaryPro = currDictionaryPro->next;
			free(OldCurrDictionaryPro);
		}
		OldCurrDictionary = currDictionary;
		currDictionary = currDictionary->next;
		free(OldCurrDictionary);
	}

}




void deleteHTMLPage()
{
	char* filePageName = (char*)malloc(100);
	for (int i = 1; i <= 3; i++)
	{	
	     numberOfIndex++;
	     sprintf(filePageName, "index%d.html", numberOfIndex);
	     FILE* fileDelete;
	     	
	     fileDelete = fopen(filePageName, "r");
	     if (!fileDelete)
	     {
	     	return NULL;
	     }
	     
	     char* charCount = (char*)malloc(10000);
	     if (!charCount)
	     {
	     	return 1;
	     }
	     char* read;
	     int fileSize = 0;
	     while ((read = fgets(charCount, 1000, fileDelete)))
	     {
	     	fileSize += strlen(charCount);
	     }
	     
	     free(charCount);
	     fclose(fileDelete);
	     fileSize += 2;
	     
	     fileDelete = fopen("index.html", "r");
	     if (!fileDelete)
	     {
	     	return NULL;
	     }
	     char* inThefile = (char*)malloc(fileSize);
	     if (!inThefile)
	     {
	     	return 1;
	     }
	     int readPosition = 0;
	     char charToRead;
	     while ((charToRead = fgetc(fileDelete)) != EOF)
	     {
	     	inThefile[readPosition] = charToRead;
	     	readPosition++;
	     }
	     inThefile[readPosition] = NULL;
	     
	     
	     fclose(fileDelete);
	     
	     if (strcmp(nameFile, "index.html") == 0)
	     {
		    fileDelete = fopen("homePage.html", "w");
		    if (!fileDelete)
		    {
		    	//error - The file (PhotoCopying.html) did not open
		    	return 1;
		    }
		    
		    //The file (newName) was opened successfully
		    fputs(inThefile, fileDelete);
		    fclose(fileDelete);
	     }
	}

	if (strcmp(filePageName, "index2.html") == 0 || strcmp(filePageName, "index3.html") == 0)
	{















	}

	
	
		


}