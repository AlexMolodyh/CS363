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
	execve("/usr/bin/id", " -u", NULL);
}
