#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program.
 * @ac: the argument count.
 * @av: the argument vector.
 *
 * Return: pointer to the new string or
 * NULL if insufficient memory was available.
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0, index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[index] = av[i][j];
			index++;
		}
		str[index] = '\n';
		index++;
	}

	str[index] = '\0';

	return (str);
}
