#include <stdio.h>
#include <string.h>
#include <mem.h>

int main()
{
    int valid = 0;
    char str1[8];
    char str2[8];

    gets(str2);
    if(strncmp(str1, str2, 8) == 0)
        valid = 1;

    printf("valid pointer %p\n", &valid);
    printf("str1 pointer %p\n", str1);
    printf("str2 pointer %p\n", str2);
    printf("buffer1: str1(%s), str2(%s), valid(%d)\n", str1, str2, valid);
    return 0;
}