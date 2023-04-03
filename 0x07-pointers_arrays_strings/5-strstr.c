#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring
 *
 * @haystack: Pointer to the string to search in
 * @needle: Pointer to the substring to search for
 *
 * Return: A pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n == *haystack && *n != '\0' && *haystack != '\0')
		{
			n++;
			haystack++;
		}
		if (*n == '\0')
			return (h);
		haystack = h + 1;
	}
	return (NULL);
}
