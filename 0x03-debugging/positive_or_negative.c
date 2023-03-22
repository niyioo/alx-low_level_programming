#include "main.h"
#include <stdio.h>

/**
* positive_or_negative - prints if integer is positive, negative, or zero
* @num: Input
* Return: 0
*/

void positive_or_negative(int num)
{
	if (num > 0)
		printf("%d is positive\n", num);
        else if (num < 0)
                printf("%d is negative\n", num);
        else
                printf("The entered number is 0\n");
}
