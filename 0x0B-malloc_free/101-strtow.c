#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words in
 *
 * Return: The number of words in the string
 */
static int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			++count;
		}
	}

	return (count);
}

/**
 * word_len - Computes the length of a word
 * @str: The string to compute the length of
 *
 * Return: The length of the word
 */
static int word_len(char *str)
{
	int len = 0;

	while (*str && *str != ' ')
	{
		++len;
		++str;
	}

	return (len);
}

/**
 * free_words - Frees the memory allocated for an array of words
 * @words: The array of words to free
 * @count: The number of words in the array
 */
static void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; ++i)
	{
		free(words[i]);
	}

	free(words);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: An array of words, or NULL if an error occurs
 */
char **strtow(char *str)
{
	char **words;
	int word_count, i, j, k = 0, len;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	word_count = count_words(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < word_count; ++i)
	{
		while (str[k] == ' ')
		{
			++k;
		}

		len = word_len(str + k);
		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}

		for (j = 0; j < len; ++j)
		{
			words[i][j] = str[k++];
		}

		words[i][j] = '\0';
	}

	words[word_count] = NULL;
	return (words);
}
