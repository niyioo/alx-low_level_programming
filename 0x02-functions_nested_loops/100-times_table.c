#include "main.h"

/**
 * print_times_table - prints the n times table starting with 0
 * @n: input
 *
 * Return: 0
 */

void print_times_table(int n)
{
	if (n < 0 || n > 15)
	{
		return;
	}

	int i, j, result;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			result = i * j;

			if (j > 0)
			{
				_putcar(' ');
			}

			if (result < 10)
			{
				_putchar(result + '0');
			}
			else if (result < 100)
			{
				_putchar((result / 100) + '0');
				_putchar(((result / 10) % 10) + '0');
				_putchar((result % 10) + '0');
			}

			if (j < n)
			{
				_putchar(',');
			}}

		_putchar('\n');
	}
}
