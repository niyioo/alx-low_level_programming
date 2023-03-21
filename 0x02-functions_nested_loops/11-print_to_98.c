#include "main.h"

/**
 * print_to_98 - prints natural numbers from n to 98
 * followed by a new line
 * @n: input
 *
 * Return: 0
 */

void print_to_98(int n)
{
	int n = 0;

	while (n <= 98)
	{
		_putchar(n);
		_putchar(',');
		_putchar(' ');
		n++;
	}

	_putchar('\n');
}
