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
	unsigned int bit_count = 0;

	while (mask <= n)
	{
		mask <<= 1;
		bit_count++;
	}

	if (bit_count > 0)
	{
		mask >>= 1;
		bit_count--;
	}

	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;
		bit_count--;
	}

	if (bit_count == 64)
		_putchar('0');
}
