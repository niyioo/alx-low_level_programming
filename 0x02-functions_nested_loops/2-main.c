#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet in
 * lowercase followed by a new line
 *
 * Return: 0
 */

int main(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 'a'; j <= 'z'; j++)
		{
			_putchar(j);
		}
		_putchar('\n');
	}
	return (0);
}