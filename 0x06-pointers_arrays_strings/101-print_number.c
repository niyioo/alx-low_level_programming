#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Result: void
 */

void print_number(int n)
{
	int i, j, d = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	for (i = n; i >= 10; i /= 10)
		d *= 10;

	for (i = n; d >= 1; d /= 10)
	{
		j = i / d;
		_putchar(j + '0');
		i -= j * d;
	}
}
