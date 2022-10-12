#pragma once

char* readFromFile();
char* saveInToFileHTML(char* newFile);
char* dynamicHtml(char* nameOfFile, char* addString);
char* dynamicTitleHtml(char* nameOfFile, char* addString, char* title);
#define SEPERATOR "</tbody>"
#define SEPERATOR_TITLE "</p>"
extern int firstTime;
extern char nameFile[50];

