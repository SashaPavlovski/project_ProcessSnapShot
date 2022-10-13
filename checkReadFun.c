/*

char* readFromFile()
{
	FILE* f;
	if (firstTime == 0)
	{
		f = fopen("index.html", "r");
		if (!f)
		{
			//error
			return 0;
		}
	}
	else
	{
		f = fopen("updatedHtmlFile.html", "r");
		if (!f)
		{
			//error
			return 0;
		}
	}

	char* temp = (char*)malloc(10000);
	int originFileSize = 0;
	while (fread(temp, sizeof(char), 1, f))
	{
		originFileSize++;
	}

	fclose(f);
	free(temp);
	originFileSize++;


		if (firstTime == 0)
		{
			f = fopen("index.html", "r");
			if (!f)
			{
				//error
				return 0;
			}
		}
		else
		{
			f = fopen("updatedHtmlFile.html", "r");
			if (!f)
			{
				//error
				return 0;
			}
		}

	 char* originFile =(char*) malloc(sizeof(originFileSize));
	 free(originFile);

	 fread(originFile, sizeof(char), originFileSize, f);
	 int a = strlen(originFile);
	 originFile[originFileSize] = NULL;
	 a = strlen(originFile);
	 fclose(f);
	 return originFile;

}
*/
