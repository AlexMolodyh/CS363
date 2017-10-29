<<<<<<< HEAD
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
=======
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
>>>>>>> 7d179384374928ed8ecd8863049b0f866f9d010d
