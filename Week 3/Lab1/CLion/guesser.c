#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guess()
{
    char *pGuessName = malloc(sizeof(char) * 30);
    char *pGuessNumber = malloc((sizeof(int) * 30));

    fgets(pGuessName, 10, stdin);
    if(equalsStr(pGuessName, "What is your name?") == 1)
        fputs("Bob", stdout);
}

int equalsStr(char *pStrInput, char *pStrToMatch)
{
    if(strlen(pStrInput) != strlen(pStrToMatch))
        return -1;
    int i = 0;
    int strToMatchLen = strlen(pStrToMatch);
    for(i; i < strToMatchLen; i++)
    {
        if(pStrInput[i] != pStrToMatch[i])
            return -1;
    }
    return 1;
}