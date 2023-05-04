#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bits_printed = 0;

	while ((mask << 1) <= n)
		mask <<= 1;

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			bits_printed++;
		}
		else if (bits_printed > 0 || mask == 1)
		{
			_putchar('0');
			bits_printed++;
		}
		mask >>= 1;
	}

	if (bits_printed == 0)
		_putchar('0');
}
