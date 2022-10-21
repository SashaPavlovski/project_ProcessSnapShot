#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>
#include "logFile.h"

#pragma warning(disable:4996)

char nameFile[1000];
void fun_log(char message[100])
{
	FILE* f = fopen(nameFile, "a");
	if (!f)
	{
		printf("error - The log file is not opened\n");
		exit(1);
	}

	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str_message_with_time[100];
	sprintf(str_message_with_time, "%d.%d.%d:%d:%d:%d - %s", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);


	fputs(str_message_with_time, f);
	fclose(f);
}

void LogError(char message[100])
{
	char strError[1000];
	sprintf(strError, "%s %s", "ERROR -", message);
	fun_log(strError);
}


void LogEvent(char message[100])
{
	char strEvent[1000];
	sprintf(strEvent, "%s %s", "Event -", message);
	fun_log(strEvent);
}

void LogWarning(char message[100])
{
	char strWarning[1000];
	sprintf(strWarning, "%s %s", "Warning -", message);
	fun_log(strWarning);
}

void LogInit(char filename[1000])
{
	sprintf(nameFile, "%s.log", filename);
}
