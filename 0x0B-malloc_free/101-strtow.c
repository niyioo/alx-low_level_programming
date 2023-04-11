#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string
 *
 * @str: The string to count words in
 *
 * Return: The number of words in str
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * alloc_words - Allocates memory for an array of words
 *
 * @word_count: The number of words to allocate memory for
 *
 * Return: A pointer to the allocated memory
 */
char **alloc_words(int word_count)
{
	char **words = NULL;

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	words[word_count] = NULL;

	return (words);
}

/**
 * strtow - Splits a string into words
 *
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words = NULL;
	int word_count = 0, i, j = 0, k = 0, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = alloc_words(word_count);
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			len = 0;
			for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
				len++;

			words[k] = malloc(sizeof(char) * (len + 1));
			if (words[k] == NULL)
			{
				for (i = 0; i < k; i++)
					free(words[i]);
				free(words);
				return (NULL);
			}

			for (j = 0; j < len; j++)
				words[k][j] = str[i + j];

			words[k][j] = '\0';
			i += len;
			k++;
		}
	}

	return (words);
}
