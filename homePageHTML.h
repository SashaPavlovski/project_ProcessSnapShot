#pragma once

char* readFromFile();
char* saveInToFileHTML(char* newFile);
char* dynamicHtml(char* nameOfFile, char* addString, char* topHtml);
char* dynamicTitleHtml(char* nameOfFile, char* addString, char* title);
char* createNewName(char* nameOfOriginFile);



#define SEPERATOR "</tbody>"
#define SEPERATOR_TITLE "</p>"
#define SEPERATOR_NAV "</span>"
#define SEPERATOR_TEMP "</tfoot>"



//if this is the first time that file opened.
extern int firstTimeInFile;

//if this is the first time that HomePage file opened.
extern int firstTimeHomePage;

//To know which file to open
extern char nameFile[50];

//for createNewName to index2
extern int countOfCreateFileIndex2;

//for createNewName to index3
extern int countOfCreateFileIndex3;

extern char* newNameOfFile;

//know if is for table processes
extern int titleProcesses;

