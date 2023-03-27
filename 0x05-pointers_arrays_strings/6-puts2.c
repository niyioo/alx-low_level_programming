#include "main.h"

/**
 * puts2 - Function that prints every other character of a string starting
 * with the frist character followed by a new line
 * @str: Input
 *
 * Return: Void
 */

void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
		_putchar(str[i]);
			}
		i++;
	}
		_putchar('\n');
}
