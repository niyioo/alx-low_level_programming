#include "main.h"

/**
 * _strncat - concatenate two strings, using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: number of bytes from src to be used
 *
 * Return: pointer to resulting string
 */

char *_strncat(char *dest, char *src, int n)
{
	int len_dest = 0, len_src = 0;

	while (*(dest + len_dest) != '\0')
		len_dest++;

	while (*(src + len_src) != '\0' && len_src < n)
	{
		*(dest + len_dest + len_src) = *(src + len_src);
		len_src++;
	}

	(*(dest + len_dest + len_src) = '\0');

	return (dest);
}
