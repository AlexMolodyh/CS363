/**
 * Author: Alex Molodyh
 * Class: CS363
 * Assignment: Lab1 Guesser.c
 * Date: 10/16/2017
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int equalsStr(char *pStrInput, char *pStrToMatch);

void main()
{
    char *pGuessName = malloc(sizeof(char) * 30);
    char *pGuessNumber = malloc((sizeof(int) * 30));

    char *pName = "Bob";
    int *pNumber = 223;

    execl("./questioner.exe", "Bob", (char *) NULL);

}
