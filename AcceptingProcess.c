#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "typesStructs.h"
#include "oneSnapShot.h"
#include "logFile.h"
#pragma warning(disable:4996)

int FirstListProcess = 0;


// get the memory usage for process, ID, name of process, names of is dll
// Calls two functions, that create a linked list of DLLs and processes
// get ID process
void getMemoryInfo(DWORD processID){

	LogEvent("enter the function getMemoryInfo");

	//create a new variable
	PROCESS* ret = (PROCESS*)malloc(sizeof(PROCESS));

	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	
	ret->prev = NULL;
	ret->next = NULL;

	//add the process Id into the new variable
	LogEvent("add the process Id into the new variable");
	ret->processId = processID;


	// Open process in order to receive information
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess){
		LogWarning("Cannot get a pointer");
		// Write to log a warning
		return;
	}
	LogEvent("geted a pointer to a process");
	HMODULE hMods[1024];
	DWORD cbNeeded;
	TCHAR FoundProcessName[MAX_PATH];
	TCHAR wDllName[MAX_PATH];
	char regularCharArr[MAX_PATH];

	// Get Process Name
	if (GetModuleFileNameEx(hProcess, 0, FoundProcessName, MAX_PATH)){
		LogEvent("Get Process Name");
		// At this point, buffer contains the full path to the executable

		size_t numConverted;
		//Changing the string from TCHAR to char
	    //add the name Of Process into the new variable
		LogEvent("add the process name into the new variable");
		wcstombs_s(&numConverted, ret->nameOfProcess, MAX_PATH, FoundProcessName, MAX_PATH);

		//Checking that there are no nameless processes
		if (strlen(ret->nameOfProcess) < 1){
			LogWarning("there is no name for the process, its did not enter a linked list");
			//not have name to the process
			//not added to the process linked list
			return 1;
		}
	}
	else{
		LogWarning("couldn't get the name process, its did not enter a linked list");
		// couldn't get the name
		// You better call GetLastError() here
		// Write To log
		return 1;
	}


	// Gets the memory data and puts it in a new variable
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))){
	
		LogEvent("add the process memory data into the new variable");
		ret->PageFaultCount = pmc.PageFaultCount;
		ret->WorkingSetSize = pmc.WorkingSetSize;
		ret->QuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		ret->QuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		ret->PagefileUsage = pmc.PagefileUsage;

	}


	// Get Dlls List
    // Receive all dll and put in hMods Array
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)){

		LogEvent("Loads all dll from the process to the array");
		// Calculate how many dll identifiers were returned.
		// and loop of all dlls
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++){
		
			// Get the full path to the module's file.
			// "name of the dll"
			if (GetModuleFileNameEx(hProcess, hMods[i], wDllName, MAX_PATH)){

				LogEvent("add the dll name into the new variable");
				char dllName[MAX_PATH];
				size_t numConverted;
				wcstombs_s(&numConverted, dllName, MAX_PATH, wDllName, MAX_PATH);
				LogEvent("add the dll name into dllName array");
				// get a name and links it to a dll linked list
				addDLL(dllName);

			}
		}
	}
	LogEvent("return to function getMemoryInfo");
	LogEvent("add the dllTail into the new variable");
	//add the DLLName_Tail, DLLName_Head, countDLL into the new variable
	ret->dllTail = DLLName_Tail;
	LogEvent("add the dllHead into the new variable");
	ret->dll = DLLName_Head;
	LogEvent("add the numbersOfDLL into the new variable");
	ret->numbersOfDLL = DLLName_Tail->countDLL;

    //Close the process
	CloseHandle(hProcess);
	LogEvent("the process is closed");

	//get the new variable and links it to a process linked list
	LogEvent("Putting the variable into the function");
	addProcess(ret);
	LogEvent("The file (getMemoryInfo) is closed, the function getMemoryInfo is finished");
}




//function that include 3 Options
//receive all processes once, 20 times and until the user is pressed 4.
//the choice is made by the user
void getProcessesInfo(){

	LogEvent("enter the function getProcessesInfo");
	//Get Processes
	DWORD aProcesses[1024] = { 0 };
	DWORD cbNeeded, cProcesses;

	//Receive all process ID and put in aProcesses Array
	LogEvent("Loads all processes to the array");
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)){
		// Error. Write to log
		LogError("The function failed to exit the processes");
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// put in struct process the memory usage for each process, ID, name of process, linked list of is dll
	// and connecting the struct to process linked list

	if (userResponse == 1){
		LogError("Inserting the processes into the loop that enters the function getMemoryInfo");
		// Loop of all processes
		for (int y = 0; y < cProcesses; y++){
		
			//function that makes a frocess linked list
			getMemoryInfo(aProcesses[y]);

		}
	}
	else if (userResponse == 2){
		LogError("Inserting the processes into the loop that enters the function getMemoryInfo");
		// sign that the first process linked list has been created
		FirstListProcess = 0;

		// Loop of all processes
		for (int i = 0; i < 20; ++i){
		

			for (int j = 0; j < cProcesses; j++){
			
				getMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;

			//Stops all processes on the computer for a second
			LogEvent("Pauses the processes on the computer for a second");
			Sleep(1000);

			//reloads the processes again
			LogEvent("Loads all processes to the array");
			if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)){
			
				// Error. Write to log
				return 1;
			}

			// Calculate how many process identifiers were returned.
			cProcesses = cbNeeded / sizeof(DWORD);
		}

	}
	else{
		LogError("Inserting the processes into the loop that enters the function getMemoryInfo");
        //enter if the user presses 3

	    // sign that the first process linked list has been created
		FirstListProcess = 0;

		//the stopping conditions
		char stop = 0;

		//If the user presses 4 it will stop
		while (stop != '4'){
		
			// Loop of all processes
			for (int j = 0; j < cProcesses; j++){
			
				getMemoryInfo(aProcesses[j]);

			}

			FirstListProcess++;

			//enters the condition only if the user clicks a button
			if (kbhit()){
			
				//passes the result
				LogEvent("The user Press on a character");
				stop = getch();
			}

			LogEvent("Pauses the processes on the computer for a second");
			Sleep(1000);
			LogEvent("Loads all processes to the array");
			if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)){
			
				// Error. Write to log
				return 1;
			}

			// Calculate how many process identifiers were returned.
			cProcesses = cbNeeded / sizeof(DWORD);
		}

	}
	LogEvent("The file (getProcessesInfo) is closed, the function getProcessesInfo is finished");

}



