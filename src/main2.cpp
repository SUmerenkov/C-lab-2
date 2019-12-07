#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task2.h"
#include <time.h>
#include <stdlib.h>
#define secret_max 101

int main()
{
    int value = 0;
    printf("Input value from 1 to 100\n");
    scanf("%d", &value);
    if ((value <= 0) || (value > 100))
        printf("You are wrong!");
    else
    {
        time_t now;
        time(&now);
        srand(now);
        int secret = rand() % secret_max;
        
        while (value != secret)
        {
            switch (turn(value, secret))
            {
            case 1:
                printf("Input lower value\n");
                break;
            case -1:
                printf("Input greater value\n");
                break;
            }
            scanf("%d", &value);
        }
        printf("Guessed!");
    }
    return 0;
}