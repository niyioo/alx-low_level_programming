#include "main.h"

/**
 * _strlen - print length
 * @s: Input
 *
 * Return: length
 */

int _strlen(char *s)
{
	int len = 0;
	while (*s++)
		len++;
	return (len);
}
