#include <stdio.h>

/**
 * main - Entry point
 * Prints alphabet in lower case
 *
 * Return: 0
 */

int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		purchar(letter);
		letter++;
	}

	purchar('\n');

	return (0);
}
