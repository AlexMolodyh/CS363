#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Read characters from the pipe and echo them to stdout. */
void read_from_pipe(int file)
{
    FILE *stream;
    int c;
	printf("In read data\n");
    stream = fdopen(file, "r");
    while ((c = fgetc(stream)) != EOF)
        putchar(c);
	printf("In read data2\n");
    fclose(stream);
}

/* Write some random text to the pipe. */
void write_to_pipe(int file, char *question)
{
    FILE *stream;
    stream = fdopen(file, "w");
    fprintf(stream, "Question %s\n", question);
    fclose(stream);
}

int main(void)
{
    pid_t pid;
    int mypipe[2];
    int i = 0;

    /* Create the pipe. */
    if (pipe(mypipe))
    {
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    /* Create the child process. */
    pid = fork();

    if (pid == (pid_t)0)
    {
        /* This is the child process.
                 Close other end first. */
        close(mypipe[1]);
        printf("In child process\n");
        read_from_pipe(mypipe[0]);
        return EXIT_SUCCESS;
    }
    else if (pid < (pid_t)0)
    {
        /* The fork failed. */
        fprintf(stderr, "Fork failed.\n");
        return EXIT_FAILURE;
    }
    else
    {
        /* This is the parent process.
                 Close other end first. */
        close(mypipe[0]);
        char *pAnswer = malloc(40);
        fgets(pAnswer, 40, stdin);
        printf("In parent process\n");
        write_to_pipe(mypipe[1], pAnswer);
        return EXIT_SUCCESS;
    }
}