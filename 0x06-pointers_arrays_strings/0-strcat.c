#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: string to be concatenated to.
 * @src: string to be appended to dest.
 *
 * Return: pointer to resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = j = 0;
	while (*(dest + i) != '\0')
		i++;
	while ((*(dest + i) = *(src + j)) != '\0')
	{
		i++;
		j++;
	}
	return (dest);
}
