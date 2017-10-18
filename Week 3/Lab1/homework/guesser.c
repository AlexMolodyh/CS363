/**
 * Author: Alex Molodyh
 * Class: CS363
 * Assignment: Lab1 Guesser.c
 * Date: 10/16/2017
 **/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int equalsStr(char *pStrInput, char *pStrToMatch);

int main()
{
  FILE *output;
  int mypipe[2];
  int guessNumbers[6] = {2, 223, 12345, 123, 23, 345};
  char *names[5] = {"Bob", "Mike", "Rachel", "Alex", "John"};
  srand(time(NULL));
  int randomInt = rand() % 6;
  int randNames = rand() % 5;
  
  output = popen("./questioner.exe", "w");
  fprintf(output, "%s %d", names[randNames], guessNumbers[randomInt]);

  if (!output)
  {
    fprintf(stderr, "incorrect parameters or too many files.\n");
    return EXIT_FAILURE;
  }

  if (pclose(output) != 0)
  {
    fprintf(stderr, "Could not run more or other error.\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
