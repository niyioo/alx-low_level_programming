#include "main.h"

/**
 * _strcat - function that catenate strings
 *
 * @dest: input dest
 * @src: input source
 *
 * Return: save
 */

char *_strcat(char *dest, char *src)
{
	char *save = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}
