#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 *
 * @str: The string to count words in
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			++count;
	}

	return (count);
}

/**
 * free_words - Frees memory allocated for an array of words
 *
 * @words: The array of words to free
 */
void free_words(char **words)
{
	int i;

	for (i = 0; words[i]; ++i)
	{
		free(words[i]);
	}

	free(words);
}

/**
 * alloc_words - Allocates memory for an array of words
 *
 * @word_count: The number of words to allocate memory for
 *
 * Return: The allocated memory for the array of words
 */
char **alloc_words(int word_count)
{
	char **words;

	words = malloc(sizeof(char *) * word_count);

	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * strtow - Splits a string into words
 *
 * @str: The string to split
 *
 * Return: The array of words
 */
char **strtow(char *str)
{
	char **words;
	int word_count, i, j, k = 0, len;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	word_count = count_words(str);

	if (word_count == 0)
		return (NULL);

	words = alloc_words(word_count + 1);

	if (words == NULL)
		return (NULL);

	for (i = 0; str[i]; ++i)
	{
		if (str[i] != ' ')
		{
			for (len = 0, j = i; str[j] && str[j] != ' '; ++j)
				++len;

			words[k] = malloc(sizeof(char) * (len + 1));

			if (words[k] == NULL)
			{
				free_words(words);
				return (NULL);
			}

			for (j = 0; j < len; ++j, ++i)
				words[k][j] = str[i];

			words[k++][j] = '\0';
		}
	}

	words[k] = NULL;

	return (words);
}
