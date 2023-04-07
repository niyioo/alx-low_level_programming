#include "main.h"

/**
 * _strncat - function
 *
 * @dest: input
 * @src: input source
 * @n: input
 *
 * Return: save
 */

char *_strncat(char *dest, char *src, int n)
{
	char *save = dest;
	while (*dest)
		dest++;
	while (*src && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}
