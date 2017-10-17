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
#include <sys/shm.h>
#include <sys/stat.h>

int equalsStr(char *pStrInput, char *pStrToMatch);

void main()
{
    FILE *output;
    
      output = popen ("more", "w");
      if (!output)
        {
          fprintf (stderr,
                   "incorrect parameters or too many files.\n");
          return EXIT_FAILURE;
        }
      write_data (output);
      if (pclose (output) != 0)
        {
          fprintf (stderr,
                   "Could not run more or other error.\n");
        }
        
        
    // key_t shm_key = 6166529;
    // const int shm_size = 1024;

    // int shm_id;
    // char *shmaddr = malloc(300);
    // char *ptr = malloc(300);
    // char *shared_memory[3];
    // int *p = malloc(300);

    // /* Allocate a shared memory segment. */
    // shm_id = shmget(shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

    // /* Attach the shared memory segment. */
    // shmaddr = (char *)shmat(shm_id, 0, 0);

    // /* Start to read data. */
    // p = (int *)shmaddr;
    // ptr = shmaddr + sizeof(int) * 2;
    // // shared_memory[0] = ptr;
    // // ptr += *p++;
    // // shared_memory[1] = ptr;
    // // ptr += *p;
    // // shared_memory[2] = ptr;

    // /* Detach the shared memory segment. */
    // shmdt(shmaddr);

    ////////////////////////////////////////////////////////////////////

    // char *pGuessName = malloc(sizeof(char) * 30);
    // char *pGuessNumber = malloc((sizeof(int) * 30));
    // int done = 0;

    // char *pName = "Bob";
    // int *pNumber = 223;

    // execl("./questioner.exe", "Bob", (char *)NULL);

    // while (done == 0)
    // {
    // }
}
