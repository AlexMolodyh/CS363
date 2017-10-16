#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subStrIndex(char *pSub, char *pStr);

int main()
{
	FILE *pFile;
	char fileName[12] = "answers.txt";
	char fileC;
	/*opening the file*/
	pFile = fopen(fileName, "r");
	if(pFile == NULL)
	{
		printf("Couldn't opent the file %s.", fileName);
		exit(0);
	}	

	fileC = fgetc(pFile);
	int index = 0;
	char *pFileStr;
	pFileStr = malloc(100);
	while(fileC != EOF)
	{
		pFileStr[index] = fileC;
		index = index + 1;
		
		printf("%c", fileC);
		fileC = fgetc(pFile);
	}	
	fclose(pFile);
	
	int subIndex = subStrIndex("Rachel", pFileStr);
	printf("The index of Rachel is %d.", subIndex);

}


int subStrIndex(char *pSub, char *pStr)
{
	int i = 0;
	int subStart = 0;
	int subCur = 0;
	int strLength = strlen(pStr);

	for(i; i < strlen(pStr); i++)
	{
		if(pSub[subCur] == pStr[i])
		{
			subStart = i;
			int j = subCur;
			int subLength = strlen(pSub);
			for(j; j < subLength; j++)
			{
				if(pSub[j] != pStr[j])
				{
					j = subLength;
				}
				return subStart;
			}
		}
	}
	return -1;
}


















