#include "main.h"

/**
 * _isupper - function that checks for uppercase character
 * @c: Input
 *
 * Return: 1 if c is uppercase
 * 0 if c is otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
