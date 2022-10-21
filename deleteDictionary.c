#include <stdio.h>
#include <stdlib.h>
#include "typesStructs.h"
#include "resetCollectionsFile.h"
#include "logFile.h"
#pragma warning(disable:4996)



//Resets the dctionary dll and dctionary processes
void deleteDictionaryDLLAndPro()
{
	dictionaryDLL* currDictionary = dictionaryDLL_Head;
	dictionaryDLL* OldCurrDictionary;
	S_dictionaryProcess* currDictionaryPro = currDictionary->dictionaryProcessUsed;
	S_dictionaryProcess* OldCurrDictionaryPro;

	while (currDictionary != NULL) {

		currDictionaryPro = currDictionary->dictionaryProcessUsed;
		while (currDictionaryPro != NULL) {

			OldCurrDictionaryPro = currDictionaryPro;
			currDictionaryPro = currDictionaryPro->next;
			free(OldCurrDictionaryPro);
		}
		OldCurrDictionary = currDictionary;
		currDictionary = currDictionary->next;
		free(OldCurrDictionary);
	}

}
	
		