#include "main.h"

/**
 * _memcpy - function
 *
 * @dest: input
 * @src: source
 * @n: input
 *
 * Return: save
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *save = dest;
	while (n--)
		*dest++ = *src++;
	return (save);
}
