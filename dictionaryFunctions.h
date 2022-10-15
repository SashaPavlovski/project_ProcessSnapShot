#pragma once

void dictionaryProcess(snapshot* snapShotList);
void addDictionaryDLL(DLLName* nameSortDLL, PROCESS* processSortDLL);
void dictionaryDLLFunction(PROCESS* sortProcessList);

extern int countnewDictionaryDLL;

extern S_dictionaryProcess* usedDictionaryProcess;
void MakeProcessDictionary(PROCESS* useProcess);



void addDictionaryProcess(dictionaryDLL* locationDLL, PROCESS* namePro);
void checkDictionaryDLL(DLLName* dDLL, PROCESS* newProDictionary);

//extern int freeProcess;













