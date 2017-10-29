#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	/*this section allocates memory on the heap*/
	char *pchar = malloc(sizeof(char) * 10);
	int *pint = malloc(sizeof(int) * 10);
	float *pfloat = malloc(sizeof(float) * 10);
	double *pdouble = malloc(sizeof(double) * 10);
	
	/*just array without initializing it*/
	char pachar[20];

	/*struct deffenition*/
	struct Person{
		char name[40];
		int age;
	}person;

	

	/*this section allocates memory on the stack*/
	char schar[16] = "Hello Kali!!";
	int sint[4] = {2, 4, 8, 16};
	float sfloat[4] = {22, 44, 88, 1616};
	double sdouble[4] = {2.2, 4.4, 8.8, 16.16};

	/*this section contains non pointer variables*/
	char c;
	int i;
	float f;
	double d;

	/*this section contains non pointer stack variables*/
	char sc = 's';
	int si = 9;
	float sf = 9;
	double sd = 2.0;

	/*print the heap adresses*/
	printf("char heap:     %p\n", pchar);
	printf("int  heap:     %p\n", pint);
	printf("float heap:    %p\n", pfloat);
	printf("double heap:   %p\n\n", pdouble);

	printf("just arr[20]:  %p\n\n", pachar);
	printf("struct adress: %p\n\n", person);

	/*print the stack adresses*/
	printf("char stack:    %p\n", schar);
	printf("int stack:     %p\n", sint);
	printf("float stack:   %p\n", sfloat);
	printf("double stack:  %p\n\n", sdouble);

	
	printf("first char:    %p\n", &c);
	printf("first int:     %p\n", &i);
	printf("first float:   %p\n", &f);
	printf("double heap:   %p\n\n", &d);
	
	printf("stack char:    %p\n", &sc);
	printf("stack int:     %p\n", &si);
	printf("stack float:   %p\n", &sf);
	printf("stack double:  %p\n\n", &sd);
}
