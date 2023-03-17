#include <stdio.h>

/**
 * main - Entry point
 * Print alphabet lowercase except q and e
 *
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i != 'e' && i != 'q')
		{
			putchar(i);
		}
	}

	putchar('\n');

	return (0);
}
