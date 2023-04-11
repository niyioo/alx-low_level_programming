#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new string which
 * is a duplicate of the string str.
 * @str: the string to be duplicated.
 *
 * Return: pointer to the new string or
 * NULL if insufficient memory was available.
 */

char *_strdup(char *str)
{
	char *new_str;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	/* get length of the string */
	for (len = 0; str[len] != '\0'; len++)
		;

	/* allocate memory for the new string */
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	/* copy the string */
	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);
}
