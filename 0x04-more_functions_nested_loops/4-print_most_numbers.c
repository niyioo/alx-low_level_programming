#include "main.h"

/**
 * print_most_numbers - Prints the numbers from 0 to 9 without 2 and 4
 * followed by a new line
 *
 * Return: 0
 */

void print_most_numbers(void)
{
	int i = 0;

	for (i = 0; i < 10; i++)
		if (i != 2 && i != 4)
	{
		_putchar(i + '0');
	}
	_putchar('\n');
}
