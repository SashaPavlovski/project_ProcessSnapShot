#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "homePageHTML.h"
#include "logFile.h"
#pragma warning(disable:4996)


FILE* file;
FILE* fileR;
int countOfCreateFileIndex2 = 1;
int countOfCreateFileIndex3 = 1;


//know which file to open
char* newNameOfFile = 0;

//reads from the file
char* readFromFile() {
	
	Loglinebreak();
	LogEvent("enter the function (readFromFile)");

	//open the file to count how many chars it has
	if (firstTimeInFile == 0 && strcmp(nameFile, "index.html") != 0){

		LogEvent("enter if it's not the home page and it's the first time condition");
		//If it's not the home page and it's the first time
		fileR = fopen(nameFile, "r");
		if (!fileR){
			//error
			return 1;
		}

	}
	else if (firstTimeHomePage == 0&& firstTimeInFile == 0){

		LogEvent("enter if it's the home page and it's the first time condition");
		//If it's the home page and it's the first time
		fileR = fopen(nameFile, "r");
		if (!fileR){
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile,"index.html")==0){

		LogEvent("enter if it's index.html and it's not the first time condition");
		//it's index.html and it's not the first time
		fileR = fopen("homePage.html", "r");
		if (!fileR){
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile, "index2.html") == 0){

		LogEvent("enter if it's index2.html and it's not the first time condition");
		//it's index2.html and it's not the first time
		fileR = fopen(newNameOfFile, "r");
		if (!fileR){
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile,"index3.html") == 0){

		LogEvent("enter if it's index3.html and it's not the first time condition");
		//it's index3.html and it's not the first time
		fileR = fopen(newNameOfFile, "r");
		if (!fileR){
			//error
			return 1;
		}
	}



    // Get the file size
    char* charCount = (char*)malloc(10000);
	if (!charCount){
		//error
		return 1;
	}
    char* read;
    int fileSize = 0;
    while ((read = fgets(charCount, 1000, fileR))){

	    fileSize += strlen(charCount);
    }
    
    free(charCount);
    fclose(fileR);
    fileSize += 2;
	LogEvent("The file is closed and the memory is freed");




    // alloc space as file size
	char* inThefile = (char*)malloc(fileSize);
	if (!inThefile){

		return 1;
	}



	//open the file to read the file into a variable
	if (firstTimeInFile == 0 && strcmp(nameFile, "index.html") != 0){
		LogEvent("second enter if it's not the home page and it's the first time condition");
		fileR = fopen(nameFile, "r");
		if (!fileR){
			//error
			return 1;
		}

	}
	else if (firstTimeHomePage == 0 && firstTimeInFile == 0){
	
		LogEvent("second enter if it's the home page and it's the first time condition");

		firstTimeHomePage = 1;
		fileR = fopen(nameFile, "r");
		if (!fileR){
		
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile, "index.html") == 0){
	
		LogEvent("second enter if it's index.html and it's not the first time condition");

		fileR = fopen("homePage.html", "r");
		if (!fileR) {
		
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile, "index2.html") == 0){ 
	
		LogEvent("second enter if it's index2.html and it's not the first time condition");

		fileR = fopen(newNameOfFile, "r");
		if (!fileR) {
		
			//error
			return 1;
		}
	}
	else if (strcmp(nameFile, "index3.html") == 0) {
	
		LogEvent("second enter if it's index3.html and it's not the first time condition");

		fileR = fopen(newNameOfFile, "r");
		if (!fileR) {
		
			//error
			return 1;
		}
	}

    int readPosition = 0;
    char charToRead;
    while ((charToRead = fgetc(fileR)) != EOF) {
    
		inThefile[readPosition] = charToRead;
    	readPosition++;
    }
	inThefile[readPosition] = NULL;
	
    
    fclose(fileR);

	LogEvent("The file is closed and the value send, the function (readFromFile) is done\n");
	//returns the variable
    return inThefile;

}



//saves what is created in a file
//Gets the variable
char* saveInToFileHTML(char* newFile) {

	Loglinebreak();
	LogEvent("enter the function (saveInToFileHTML)");

	if (strcmp(nameFile, "index.html") == 0) {

	   LogEvent("enter if it's index.html condition");

	   file = fopen("homePage.html", "w");
	   if (!file) {
	   
	    	//error - The file (homePage.html) did not open
	    	return 1;
	   }

	   //The file (newName) was opened successfully
	   fputs(newFile, file);
	   fclose(file);
	  
    }
    else if (strcmp(nameFile, "index2.html") == 0) {

		LogEvent("enter if it's index2.html condition");

        file = fopen(newNameOfFile, "w");
        if (!file) {
        
        	//error - The file (PhotoCopying.html) did not open
			return 1;
        }

        //The file (newName) was opened successfully
        fputs(newFile, file);
        fclose(file);
    }
	else if (strcmp(nameFile, "index3.html") == 0) {

		LogEvent("enter if it's index3.html condition");

		file = fopen(newNameOfFile, "w");
		if (!file) {
		
			//error - The file (PhotoCopying.html) did not open
			return 1;
		}

		//The file (newName) was opened successfully
		fputs(newFile, file);
		fclose(file);
	}
	else {
	
		//no exist file
		printf("no exist file\n");
		return 1;
	}
	free(newFile);

	LogEventWithVariable("The file is closed and the new name send, the function (saveInToFileHTML) is done, name of file", newNameOfFile);
	Loglinebreak();

	//Sends the name of the saved file
	return newNameOfFile;
	//The file (PhotoCopying.html) is closed, the function PhotoCopying is finished
}






//creates a new name for the files
char* createNewName(char* nameOfOriginFile) {

	Loglinebreak();
	LogEvent("enter the function (createNewName)");

	char* newNameFile = (char*)malloc(30);

	if (strcmp(nameOfOriginFile, "index2.html") == 0) {
	
	    sprintf(newNameFile, "samplePage_%d.html", countOfCreateFileIndex2);
	    countOfCreateFileIndex2++;


		LogEventWithVariable("The function (createNewName) is done, name of file", newNameOfFile);
		Loglinebreak();

	    return newNameFile;
	}
	else if (strcmp(nameOfOriginFile, "index3.html") == 0) {
	
		sprintf(newNameFile, "useDll_%d.html", countOfCreateFileIndex3);
		countOfCreateFileIndex3++;


		LogEventWithVariable("The function (createNewName) is done, name of file", newNameOfFile);
		Loglinebreak();

		return newNameFile;
	}
	else {
	

		LogEvent("The function (createNewName) is done, name of file sended NULL\n");

		return NULL;
	}
}