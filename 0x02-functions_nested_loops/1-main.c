#include "main.h"

/**
 * print_alphabet - prints the lowercase alphabet
 * followed by a new line
 *
 * Return: 0
 */

int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}

	_putchar('\n');
	return (0);
}
