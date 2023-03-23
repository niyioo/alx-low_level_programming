#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0
 */

int main(void)
{
	long n = 612852475143;
		long factor;

		for (factor = 2; factor <= n; factor++)
		{
			while (n % factor == 0)
			{
				n /= factor;
			}
		}

		printf("%ld\n", factor - 1);
		return (0);
}
