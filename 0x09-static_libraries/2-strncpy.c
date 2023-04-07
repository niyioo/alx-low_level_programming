#include "main.h"

/**
 * _strncpy - function that copy strings
 *
 * @dest: input
 * @src: input source
 * @n: input
 *
 * Return: save
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *save = dest;
	while (*src && n--)
		*dest++ = *src++;
	while (n--)
		*dest++ = '\0';
	return (save);
}
