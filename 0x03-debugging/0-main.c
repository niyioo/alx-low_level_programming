#include "main.h"

/**
* main - prints whether a given integer is positive, negative, or zero
* @i: the integer to be tested
* Return: void
*/

int main(void)
{
	int num;
	
	printf("Enter an integer: ");
	scanf("%d", &num);

	positive_or_negative(num);
	
	return (0);
}
