#include "main.h"

/**
 * _memset - function 
 *
 * @s: input
 * @b: input
 * @n: input
 *
 * Return: save
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *save = s;
	while (n--)
		*s++ = b;
	return (save);
}
