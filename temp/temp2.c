#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char *str = malloc(sizeof(char) * 20);
	int i;
	char t;
	char arr[30];

	printf("address of str is: %p\n", &str);
	printf("address of i is:   %p\n", &i);
	printf("address of t is:   %p\n", &t);
	printf("address of arr is: %p\n\n\n", &arr);
	
	
	printf("pointer of str is: %p\n", str);
	printf("address of i is:   %p\n", &i);
	printf("address of t is:   %p\n", &t);
	printf("pointer of arr is: %p\n\n\n", arr);
	

	str = "Hello Kali!!";
	i = 20;
	t = 't';
	int k;
	for(k = 0; k < 20; k++)
	{
		arr[k] = (char) k + 65;		
	}
	
	
	printf("pointer of str is: %p\n", str);
	printf("address of i is:   %p\n", &i);
	printf("address of t is:   %p\n", &t);
	printf("pointer of arr is: %p\n\n\n", arr);

		
	printf("value of str is:   %s\n", str);
	printf("value of i is:     %d\n", i);
	printf("value of t is:     %c\n", t);
	printf("value of arr is:   %s\n", arr);

}
