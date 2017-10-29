#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main()
{
	char filename[] = "/bin/id\x00";
	char uid[] = "-u\x00";
	char **argv, **envp;

	argv[0] = filename;
	argv[1] = 0;
	envp[0] = 0;

	execve(filename, argv, envp);
}
