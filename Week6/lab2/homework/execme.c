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
	char *exec = {"/bin//echo", "$UID", 0};
	execve(exec[0], &exec[1], NULL);
	int i = 0;
}
