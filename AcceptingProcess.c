#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#pragma warning(disable:4996)

int FirstListProcess = 0;


// get the memory usage for process, ID, name of process, names of is dll
// Calls two functions, that create a linked list of DLLs and processes
// get ID process
void getMemoryInfo(DWORD processID)
{
	//create a new variable
	PROCESS* ret = (PROCESS*)malloc(sizeof(PROCESS));

	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	
	ret->prev = NULL;
	ret->next = NULL;

	//add the process Id into the new variable
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
		// At this point, buffer contains the full path to the executable

		size_t numConverted;
		//Changing the string from TCHAR to char
	    //add the name Of Process into the new variable
		wcstombs_s(&numConverted, ret->nameOfProcess, MAX_PATH, FoundProcessName, MAX_PATH);

		//Checking that there are no nameless processes
		if (strlen(ret->nameOfProcess) < 1)
		{
			//not have name to the process
			//not added to the process linked list
			return ;
		}
	}
	else
	{
		// couldn't get the name
		// You better call GetLastError() here
		// Write To log
	}


	// Gets the memory data and puts it in a new variable
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{

		ret->PageFaultCount = pmc.PageFaultCount;
		ret->WorkingSetSize = pmc.WorkingSetSize;
		ret->QuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		ret->QuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		ret->PagefileUsage = pmc.PagefileUsage;

	}


	// Get Dlls List
    // Receive all dll and put in hMods Array
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		// Calculate how many dll identifiers were returned.
		// and loop of all dlls
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			// Get the full path to the module's file.
			// "name of the dll"
			if (GetModuleFileNameEx(hProcess, hMods[i], wDllName, MAX_PATH))
			{
				char dllName[MAX_PATH];
				size_t numConverted;
				wcstombs_s(&numConverted, dllName, MAX_PATH, wDllName, MAX_PATH);

				// get a name and links it to a dll linked list
				addDLL(dllName);

			}
		}

	}

	//add the DLLName_Tail, DLLName_Head, countDLL into the new variable
	ret->dllTail = DLLName_Tail;
	ret->dll = DLLName_Head;
	ret->numbersOfDLL = DLLName_Tail->countDLL;

    //Close the process
	CloseHandle(hProcess);

	//get the new variable and links it to a process linked list
	addProcess(ret);

}




//function that include 3 Options
//receive all processes once, 20 times and until the user is pressed 4.
//the choice is made by the user
void getProcessesInfo()
{
	//Get Processes
	DWORD aProcesses[1024] = { 0 };
	DWORD cbNeeded, cProcesses;

	//Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		// Error. Write to log
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// put in struct process the memory usage for each process, ID, name of process, linked list of is dll
	// and connecting the struct to process linked list

	if (userResponse == 1)
	{
		// Loop of all processes
		for (int y = 0; y < cProcesses; y++)
		{
			//function that makes a frocess linked list
			getMemoryInfo(aProcesses[y]);

		}
	}
	else if (userResponse == 2)
	{
		// sign that the first process linked list has been created
		FirstListProcess = 0;

		// Loop of all processes
		for (int i = 0; i < 20; ++i)
		{

			for (int j = 0; j < cProcesses; j++)
			{
				getMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;

			//Stops all processes on the computer for a second
			Sleep(1000);

			//reloads the processes again
			if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
			{
				// Error. Write to log
				return 1;
			}

			// Calculate how many process identifiers were returned.
			cProcesses = cbNeeded / sizeof(DWORD);
		}

	}
	else
	{
        //enter if the user presses 3

	    // sign that the first process linked list has been created
		FirstListProcess = 0;

		//the stopping conditions
		char stop = 0;

		//If the user presses 4 it will stop
		while (stop != '4')
		{
			// Loop of all processes
			for (int j = 0; j < cProcesses; j++)
			{
				getMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;

			//enters the condition only if the user clicks a button
			if (kbhit())
			{
				//passes the result
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

}



