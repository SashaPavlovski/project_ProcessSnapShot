

//lemala:
/*
if (firstTime == 0)
{
	fileR = fopen(nameFile, "r");
	if (!fileR)
	{
		//error
		return 0;
	}

}
else if (nameFile == "index.html")
{
	fileR = fopen("homePage.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}

else if (nameFile == "index2.html")
{
	fileR = fopen("samplePage.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}
else if (nameFile == "index3.html")
{
	fileR = fopen("useDll.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}

*/



//lemata:
/*

if (firstTime == 0)
{
	fileR = fopen("index.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}
else if (nameFile == "index2.html")
{
	fileR = fopen("homePage.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}
else if (nameFile == "index3.html")
{
	fileR = fopen("useDll.html", "r");
	if (!fileR)
	{
		//error
		return 0;
	}
}
*/





//function save
/*

if (nameFile == "homePage.html")
{
	file = fopen("homePage.html", "w");
	if (!file)
	{
		//error - The file (PhotoCopying.html) did not open
		return "homePage.html";
	}
	//The file (newName) was opened successfully

	fputs(newFile, file);
	fclose(file);
}
else if (nameFile == "samplePage.html")
{
	file = fopen("samplePage.html", "w");
	if (!file)
	{
		//error - The file (PhotoCopying.html) did not open
		return "samplePage.html";
	}
	//The file (newName) was opened successfully

	fputs(newFile, file);
	fclose(file);
}
else if (nameFile == "useDll.html")
{
		file = fopen("useDll.html", "w");
		if (!file)
		{
			//error - The file (PhotoCopying.html) did not open
			return "useDll.html";
		}
		//The file (newName) was opened successfully

		fputs(newFile, file);
		fclose(file);
}
else
{
		//no exist file
		printf("no exist file\n");
		return 1;
}



*/




/*
//opsion 1 dictionary

void addDictionaryDLL(DLLName* nameSortDLL, PROCESS* processSortDLL, dictionaryDLL* connectingProcesses) {
	if (connectingProcesses == NULL && processSortDLL == NULL)
	{
		countnewDictionaryDLL = 0;
		dictionaryDLL_Head = 0;
		return;
	}

	if (existsDLLInList == 1)
	{

		strcat(connectingProcesses->useProcessesName, processSortDLL->nameOfProcess);
		strcat(connectingProcesses->useProcessesName, ",");

		char strId[10000] = "";
		sprintf(strId, "%d", processSortDLL->processId);
		strcat(connectingProcesses->useProcessesID, strId);
		strcat(connectingProcesses->useProcessesID, ",");
		return;
	}

		dictionaryDLL* newDictionaryDLL = (dictionaryDLL*)malloc(sizeof(dictionaryDLL));
	if (!newDictionaryDLL)
	{
		//error
		return ;
	}
	countnewDictionaryDLL++;
	newDictionaryDLL->countDictionaryDLL = countnewDictionaryDLL;
	strcpy(newDictionaryDLL->nameOfDLL, nameSortDLL->nameOfDLL);
	newDictionaryDLL->useProcessesName[0] = "";
	strcat(newDictionaryDLL->useProcessesName,processSortDLL->nameOfProcess);
	strcat(newDictionaryDLL->useProcessesName,",");

	newDictionaryDLL->useProcessesID[0] = NULL;
	char strId[100000] = "";
	sprintf(strId, "%d", processSortDLL->processId);
	strcat(newDictionaryDLL->useProcessesID, strId);
	strcat(newDictionaryDLL->useProcessesID, ",");

	newDictionaryDLL->next = NULL;
	if (dictionaryDLL_Head == NULL) {
		dictionaryDLL_Head = newDictionaryDLL;
		dictionaryDLL_Tail = newDictionaryDLL;
		newDictionaryDLL->prev = NULL;
	}
	else {
		dictionaryDLL_Tail->next = newDictionaryDLL;
		newDictionaryDLL->prev = dictionaryDLL_Tail;
		dictionaryDLL_Tail = newDictionaryDLL;
	}

}











	*/

