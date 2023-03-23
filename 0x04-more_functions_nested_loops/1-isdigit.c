#include "main.h"

/**
 * _isdigit - function that checks for a digit (0 through 9)
 * @c: Input
 *
 * Return: 1 if c is a digit
 * 0 if c is otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
