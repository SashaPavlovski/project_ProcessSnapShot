#pragma once
void fun_log(char message[100]);
void LogError(char message[100]);
void LogEvent(char message[100]);
void LogEventWithVariable(char message[100], char variable[10000]);
void LogEventWithNumber(char message[100], int numVariable);
void LogWarning(char message[100]);
void LogInit(char filename[1000]);
void Loglinebreak();
extern char logFileName[200];
extern char* variable;
