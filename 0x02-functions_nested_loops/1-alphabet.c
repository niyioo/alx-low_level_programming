#include "main.h"

/**
 * main - Entry point
 * function void print_alphabet that prints
 * alphabet in lowercase
 * followed by a new line
 *
 * Return: 0
 */

void print_alphabet(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}

	_putchar('\n');
}
