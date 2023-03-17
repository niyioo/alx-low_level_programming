#include <stdio.h>

/**
 * main - Entry point
 * Prints alphabet lowercase uppercase
 *
 * Return: 0
 */

int main(void)
{
	char letter1, letter2 = 'a', 'A';

	while (letter1 <= 'z', letter2 <= 'Z')
	{
		putchar(letter1, letter2);
		letter1++, letter2++;
	}

	putchar('\n');

	return (0);
}
