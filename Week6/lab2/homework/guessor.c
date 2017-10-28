//
//  questioner.c
//  
//
//  Created by Yanwei Wu on 10/17/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    
    int flag = 0;
    char randomLetter[1];
    char guessed[1];
    int counter = 0;
    
    srand(time(NULL));
    *randomLetter = rand() % 256;
    
    while(counter < 3)
    {
        counter++;
        
        printf("Input your guess! ");
        scanf("%s", &guessed);
        
        if (guessed[0] == randomLetter[0])
        {
            flag = 1;
            break;
        }
    }
    
    if (flag > 0)
    {
        
        printf("Succeed!");
    }
    
    return 0;
}
