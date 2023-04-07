#include "main.h"

/**
 * _puts - print output
 * @s: Input
 *
 * Return: void
 */

void _puts(char *s)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (*s == '\0')
			break;
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}
