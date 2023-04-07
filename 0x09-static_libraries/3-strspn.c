#include "main.h"

/**
 * _strspn - function
 *
 * @s: input
 * @accept: input
 *
 * Return: count
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count, i;

	for (count = 0; *(s + count) != '\0'; count++)
	{
		for (i = 0; *(s + count) != *(accept + i); i++)
		{
			if (*(accept + i) == '\0')
				return (count);
		}
	}
	return (count);
}
