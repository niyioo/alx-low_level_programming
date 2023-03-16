#include <stdio.h>

/**
 * main - Entry point
 *
 * printf to know the size of the
 * folloing data types, char, int, long int,
 * long long int, and float
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float e;

	printf("Size of a char: %zu", sizeof (a));
	printf("\nSize of an int: %zu", sizeof (b));
	printf("\nSize of a long int: %zu", sizeof(c));
	printf("\nSize of a long long int: %zu", sizeof(d));
	printf("\nSize of a float: %zu", sizeof(e));
	return (0);
}
