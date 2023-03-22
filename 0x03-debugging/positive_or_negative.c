#include "main.h"
#include <stdio.h>

/**
* positive_or_negative - tests function that prints if integer is positive or negative
* Return: 0
*/

void positive_or_negative(int num)
{
	if (num > 0)
		printf("%d is positive.\n", num);
        else if (num < 0)
                printf("%d is negative.\n", num);
        else
                printf("The entered number is 0.\n");
}

int test_positive_or_negative(void)
{
	int num;

	num = 98;
	positive_or_negative(num);

	num = 0;
	positive_or_negative(num);

	num = -98;
	positive_or_negative(num);

	return (0);
}
