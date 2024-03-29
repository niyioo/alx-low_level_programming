#include "main.h"

/**
 * print_sign - prints the sign of a number
 * @n: input.
 *
 * Return: 1 and print + if n greater than zero
 * 0 and print 0 if n is zero
 * -1 and print - if n is less than zero
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
