#include "main.h"

/**
 * _strcpy - function that copy strings
 *
 * @dest: input
 * @src: input source
 *
 * Return: save
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}
