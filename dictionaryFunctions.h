#pragma once

void dictionaryProcess(snapshot* snapShotList);
void addDictionaryDLL(DLLName* nameSortDLL, PROCESS* processSortDLL);
void dictionaryDLLFunction(PROCESS* sortProcessList);

extern int countnewDictionaryDLL;

extern S_dictionaryProcess* usedDictionaryProcess;
void MakeProcessDictionary(PROCESS* useProcess);


//NESAYON
void addDictionaryProcess(dictionaryDLL* proTail1, PROCESS* toList);
void checkDictionaryDLL(DLLName* dDLL, PROCESS* ppp);

extern int freeProcess;













