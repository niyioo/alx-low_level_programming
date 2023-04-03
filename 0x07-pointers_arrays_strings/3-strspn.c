#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 *
 * @s: Pointer to the string to search
 * @accept: Pointer to the string of characters to match against
 *
 * Return: The number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match;

	while (*s)
	{
		for (match = 0; accept[match]; match++)
		{
			if (accept[match] == *s)
			{
				count++;
				break;
			}
			else if ((accept[match + 1]) == '\0')
				return (count);
		}
		s++;
	}
	return (count);
}
