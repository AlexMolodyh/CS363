//
//  vulnerable.c
//  
//
//  Created by Yanwei Wu on 10/12/17.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main()
{
	char filename[] = "/bin/id\x00";
	char uid[] = "-u\x00";
	char **envp = malloc(sizeof(char) * 4);

	char **argv = malloc(sizeof(char) * 25);
	argv[0] = malloc(sizeof(char) * 14);
	argv[1] = malloc(sizeof(char) * 9);

	argv[0] = filename;
	argv[1] = uid;
	envp[0] = 0;

	execve(filename, argv, envp);
}
