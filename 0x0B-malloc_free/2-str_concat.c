#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: pointer to the new string or
 * NULL if insufficient memory was available.
 */

char *str_concat(char *s1, char *s2)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 != NULL)
	{
		for (; s1[len1] != '\0'; len1++)
			;
	}

	if (s2 != NULL)
	{
		for (; s2[len2] != '\0'; len2++)
			;
	}

	new_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	for (j = 0; j < len2; j++, i++)
		new_str[i] = s2[j];

	new_str[i] = '\0';

	return (new_str);
}
