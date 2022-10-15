#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "typesStructs.h"
#include "oneSnapShot.h"

#pragma warning(disable:4996)



int FirstListProcess = 0;

void PrintMemoryInfo(DWORD processID)
{

	PROCESS* ret = (PROCESS*)malloc(sizeof(PROCESS));
	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	
	ret->prev = NULL;
	ret->next = NULL;
	ret->processId = processID;
	// Open process in order to receive information
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
	{
		// Write to log a warning
		return;
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	TCHAR FoundProcessName[MAX_PATH];
	TCHAR wDllName[MAX_PATH];
	char regularCharArr[MAX_PATH];

	// Get Process Name
	if (GetModuleFileNameEx(hProcess, 0, FoundProcessName, MAX_PATH))
	{

		size_t numConverted;
		wcstombs_s(&numConverted, ret->nameOfProcess, MAX_PATH, FoundProcessName, MAX_PATH);
		if (strlen(ret->nameOfProcess) < 1)
		{
			//not have name to the process
			return ;
		}


		// At this point, buffer contains the full path to the executable
	}
	else
	{
		// You better call GetLastError() here
		// Write To log
	}

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{

		ret->PageFaultCount = pmc.PageFaultCount;
		ret->WorkingSetSize = pmc.WorkingSetSize;
		ret->QuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		ret->QuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		ret->PagefileUsage = pmc.PagefileUsage;

	}


	// Get Dlls List

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], wDllName, MAX_PATH))
			{
				
				char dllName[MAX_PATH];
				size_t numConverted;
				wcstombs_s(&numConverted, dllName, MAX_PATH, wDllName, MAX_PATH);
				addDLL(dllName);

			}
		}

	}
	ret->dllTail = DLLName_Tail;
	ret->dll = DLLName_Head;
	ret->numbersOfDLL = DLLName_Tail->countDLL;

	CloseHandle(hProcess);

	addProcess(ret);

}






void GetProcessesInfo()
{
	// Get Processes
	DWORD aProcesses[1024] = { 0 };
	DWORD cbNeeded, cProcesses;

	// * Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		// Error. Write to log
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the memory usage for each process
	// *Loop of all processes

	if (userResponse == 1)
	{
		for (int y = 0; y < cProcesses; y++)
		{
			PrintMemoryInfo(aProcesses[y]);

		}
	}
	else if (userResponse == 2)
	{
		FirstListProcess = 0;
		for (int i = 0; i < 20; ++i)
		{

			for (int j = 0; j < cProcesses; j++)
			{
				PrintMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;
			Sleep(1000);

			if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
			{
				// Error. Write to log
				return 1;
			}

			// Calculate how many process identifiers were returned.
			cProcesses = cbNeeded / sizeof(DWORD);
		}

		int ee = 0;
	}
	else
	{
		FirstListProcess = 0;
		char stop = 0;
		while (stop != '4')
		{

			for (int j = 0; j < cProcesses; j++)
			{
				PrintMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;
			if (kbhit())
			{
				stop = getch();
			}
			Sleep(1000);

			if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
			{
				// Error. Write to log
				return 1;
			}

			// Calculate how many process identifiers were returned.
			cProcesses = cbNeeded / sizeof(DWORD);
		}

	}




	int aaa = 1;

	// For each Process to get its Memory Information

}



