
#include <windows.h>
#include <psapi.h>


typedef struct _DLLName {
	char nameOfDLL[300];
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
	char nameOfProcess[300];
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



typedef struct _dictionaryProcess {
	char nameOfProcess[300];
	int countDictionaryProcess;
	struct _dictionaryProcess* next;
	struct _dictionaryProcess* prev;
}S_dictionaryProcess;


extern S_dictionaryProcess* dictionaryProcess_Head;
extern S_dictionaryProcess* dictionaryProcess_Tail;


typedef struct _dictionaryDLL {
	char nameOfDLL[300];
	int countDictionaryDLL;
	S_dictionaryProcess* dictionaryProcessUsed;
	S_dictionaryProcess* dictionaryProcessTail;
	struct _dictionaryDLL* next;
	struct _dictionaryDLL* prev;
}dictionaryDLL;


extern dictionaryDLL* dictionaryDLL_Head;
extern dictionaryDLL* dictionaryDLL_Tail;

#pragma onces


