#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>
#include "logFile.h"

#pragma warning(disable:4996)

char logFileName[200] = "";

void fun_log(char* message)
{
	FILE* f = fopen(logFileName, "a");
	if (!f)
	{
		printf("error - The log file is not opened\n");
		exit(1);
	}

	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str_message_with_time[10300];
	sprintf(str_message_with_time, "%d.%d.%d:%d:%d:%d - %s\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);


	fputs(str_message_with_time, f);
	fclose(f);
}


void LogError(char message[100]){

	char strError[120];
	sprintf(strError, "%s %s", "ERROR -", message);
	fun_log(strError);
}


void LogEvent(char message[200]){

	char strEvent[220];
	sprintf(strEvent, "%s %s", "Event -", message);
	fun_log(strEvent);
}

void LogEventWithVariable(char message[100],char variable[10000]) {
	
	char strEventWithVariable[10200];
	sprintf(strEventWithVariable, "%s %s - %s", "Event -", message, variable);
	fun_log(strEventWithVariable);
}


void LogEventWithNumber(char message[100], int numVariable){

	char strEventWithNumber[500];
	sprintf(strEventWithNumber, "%s %s - %d", "Event -", message, numVariable);
	fun_log(strEventWithNumber);
	
}

void LogWarning(char message[100])
{
	char strWarning[120];
	sprintf(strWarning, "%s %s", "Warning -", message);
	fun_log(strWarning);
}

void LogInit(char filename[50])
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	sprintf(logFileName, "%s_%d-%d-%d_%d-%d-%d.log", filename, timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

}

void Loglinebreak()
{
	FILE* f = fopen(logFileName, "a");
	if (!f)
	{
		printf("error - The log file is not opened\n");
		exit(1);
	}

	fputs("\n", f);
	fclose(f);
}