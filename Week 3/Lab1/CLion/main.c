#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

int subStrIndex(char *pSub, char *pStr);
char* getUserInfo(char *pUser, char *pStr);
int lineLength(int index, char *pStr);
char* getInput(char *inputBuffer, int bufferLength);

int main()
{
    FILE *pFile;
    char fileName[200] = "C:\\Users\\Almania\\Documents\\WOU\\CS363\\Week 3\\Lab1\\CLion\\answers.txt";

    //a pointer to store the user name
    char *pUserName = malloc(10);

    int defaultNumber = 12345;

    //used to convert user magic number from file
    uintmax_t magicNumber = defaultNumber;

    /*we only allocate 30 bytes for the user guess since it doesn't need to be that large
      if the user enters a number any larger than that, we will terminate the program*/
    int *pUserGuessNumber = malloc(sizeof(int) * 30);

    /*opening the file*/
    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        printf("Couldn't open the file %s.", fileName);
        exit(0);
    }

    //get the size of the file
    fseek(pFile, 0, SEEK_END);
    int fileSize = ftell(pFile);
    rewind(pFile);

    char fileC = fgetc(pFile);//a single char from the file
    char *pFileStr = malloc(fileSize);//the file content will be stored in this string
    int index = 0;
    //append all of the file characters to the string
    while (fileC != EOF) {
        pFileStr[index] = fileC;
        index = index + 1;
        fileC = fgetc(pFile);
    }
    fclose(pFile);

    //make sure user is not inputting large user names
    printf("What is your name? ");
    while(getInput(pUserName, 10) == -1)
    {
        fputs("The input is too long try again!", stdout);
    }

    //make sure user isn't inputting numbers that are too large
    printf("What is the magic number %s? ", pUserName);
    scanf(" %d", pUserGuessNumber);
    /*while(getInput(pUserGuessNumber, 10) == -1)
    {
        fputs("The number is too large, 10 digits max", stdout);
    }*/

    //if the user is in the file, then set the magic number to be from the file
    int userNameIndex = subStrIndex(pUserName, pFileStr);
    if(userNameIndex > -1)
    {

        magicNumber = strtoumax(getUserInfo(pUserName, pFileStr), NULL, 10);
    }

    //if we couldn't get the magic number from the file then we set it back to the default
    if(magicNumber == UINTMAX_MAX && errno == ERANGE)
    {
        magicNumber = defaultNumber;
    }
    if(magicNumber > *pUserGuessNumber)
        printf("TOO LOW");
    else if(magicNumber < *pUserGuessNumber)
        printf("TOO HIGH");
    else
        printf("SUCCESS");
}


/**Checks to see if the user has input the right amount*/
char* getInput(char *inputBuffer, int bufferLength)
{
    fgets(inputBuffer, bufferLength, stdin);
    //if the input has overwritten the \n value, then we return a -1 to indicate invalid input
    if (inputBuffer[strlen(inputBuffer) -1] != '\n')
    {
        int overflow = 0;
        while (fgetc(stdin) != '\n')
            overflow++;

        // if they input exactly (bufferLength - 1)
        // characters, there's only the \n to chop off
        if (overflow > 0)
            return - 1;
    }
    else//otherwise everything went smoothly
    {
        inputBuffer[strlen(inputBuffer) -1] = '\0';
        return 1;
    }
}


int subStrIndex(char *pSub, char *pStr)
{
    int i = 0;
    int subStart = 0;
    int subCur = 0;

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


char* getUserInfo(char *pUser, char *pStr)
{
    char *pNumber = malloc(30);
    int i = subStrIndex(pUser, pStr);
    int strLength = lineLength(subStrIndex(pUser, pStr), pStr) + i;
    int tempIndex = 0;
    int tab = 9;
    int space = 32;

    while(pStr[i] != tab && pStr[i] != space)
    {
        i = i + 1;
        tempIndex = tempIndex + 1;
    }
    i = i + 1;
    tempIndex = 0;
    for(i; i < strLength; i++)
    {
        pNumber[tempIndex] = pStr[i];
        tempIndex = tempIndex + 1;
    }
    pNumber[tempIndex] = '\r';

    return pNumber;
}

int lineLength(int index, char *pStr)
{
    int strLength = strlen(pStr);
    int i = index;
    int returnLength = 0;
    int newLine = 10;
    for(i; i < strLength; i++)
    {
        if(pStr[i] == newLine)
            return returnLength;
        else
            returnLength = returnLength + 1;
    }
    return returnLength;
}


















