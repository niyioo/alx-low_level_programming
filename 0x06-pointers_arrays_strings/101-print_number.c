#include "main.h"

/**
 * print_number - Prints an integer to stdout
 *
 * @n: The integer to print
 */
void print_number(int n)
{
	int divisor = 1;
	int abs_n = n < 0 ? -n : n;
	int num_digits = 0;
	int digit;

	while (abs_n / divisor > 9)
	{
		divisor *= 10;
	}

	if (n < 0)
	{
		_putchar('-');
	}

	while (divisor != 0)
	{
		num_digits++;
		digit = abs_n / divisor;
		_putchar('0' + digit);
		abs_n %= divisor;
		divisor /= 10;
	}

	if (num_digits == 0)
	{
		_putchar('0');
	}
}
