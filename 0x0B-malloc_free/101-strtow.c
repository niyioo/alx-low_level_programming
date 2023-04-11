#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words in str.
 */

int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: If str is NULL, empty, or fails - NULL.
 * Otherwise - a pointer to an array of strings (words).
 */

char **strtow(char *str)
{
	char **words;
	int i, j, k, len, word_count = 0, index = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	word_count = count_words(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		while (str[index] == ' ')
			index++;

		len = 0;
		while (str[index + len] != ' ' && str[index + len] != '\0')
			len++;

		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (k = 0; k < len; k++)
			words[i][k] = str[index + k];
		words[i][k] = '\0';

		index += len;
	}

	words[word_count] = NULL;

	return (words);
}
