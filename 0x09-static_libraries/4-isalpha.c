#include "main.h"
#include <ctype.h>

/**
 * _isalpha - prints alphabet
 * @c: Input
 *
 * Return: void
 */

int _isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
