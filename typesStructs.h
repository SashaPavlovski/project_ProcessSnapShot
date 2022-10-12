#include <windows.h>
#include <psapi.h>


typedef struct _DLLName {
	char nameOfDLL[MAX_PATH];
	int countDLL;
	struct _DLLName* next;
	struct _DLLName* prev;
}DLLName;

extern DLLName* DLLName_Head;
extern DLLName* DLLName_Tail;

typedef struct _DLLNameHeader {
	int versionDLLName;
	char reserve[20];
}DLLNameHeaders;


extern int countOfDll;


typedef struct _PROCESS {
	char nameOfProcess[MAX_PATH];
	DWORD PageFaultCount;
	SIZE_T WorkingSetSize;
	SIZE_T QuotaPeakPagedPoolUsage;
	SIZE_T QuotaPagedPoolUsage;
	SIZE_T PagefileUsage;
	DWORD processId;
	DLLName* dll;
	DLLName* dllTail;
	int numbersOfDLL;
	int countProcess;
	struct _PROCESS* prev;
	struct _PROCESS* next;

} PROCESS;


extern PROCESS* PROCESS_Head;
extern PROCESS* PROCESS_Tail;

typedef struct _processHeader {
	int versionProcess;
	char reserve[20];
} processHeader;


extern int countP;


typedef struct _snapshot {
	PROCESS* myprocess;
	int countSnapsNumber;
	int countOfProcess;
	char timeOfSnapshot[100];
	struct _snapshot* next;
	struct _snapshot* prev;
}snapshot;


typedef struct _snapshotHeader {
	int versionSnapShot;
	int countSnapshot;
	char reserve[20]; 
}snapShotHeader;


extern snapshot* snapshot_Head;
extern snapshot* snapshot_Tail;



extern int FirstListProcess;
extern int processNotExist;
extern int userResponse;
extern char str[100];


extern snapshot* newSnapShot;
extern PROCESS* newProcess;

extern snapShotHeader* snapShotHeaderFile;
extern processHeader* processHeaderFile;
extern DLLNameHeaders* DLLHeaderFile;


#pragma once