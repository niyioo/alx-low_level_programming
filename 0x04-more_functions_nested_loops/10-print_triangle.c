#include "main.h"

/**
 * print_triangle - Function that prints a triangle followed by a new line
 * @size: The size of the triangle to print
 */

void print_triangle(int size)
{
	int row, col, space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (row = 1; row <= size; row++)
	{
		for (space = 1; space <= size - row; space++)
			_putchar(' ');
		for (col = 1; col <= row; col++)
			_putchar('#');

		_putchar('\n');
	}
}
