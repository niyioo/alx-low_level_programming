#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 *
 * @str: The string to count the words in.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * free_words - Frees an array of words.
 *
 * @words: The array of words to free.
 * @n: The number of words in the array.
 */
void free_words(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(words[i]);

	free(words);
}

/**
 * get_word - Gets the next word from a string.
 *
 * @str: The string to get the word from.
 *
 * Return: A pointer to the next word in the string.
 */
char *get_word(char *str)
{
	char *word;
	int i, len = 0;

	while (str[len] != ' ' && str[len] != '\0')
		len++;

	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[i];

	word[len] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words.
 *
 * @str: The string to split.
 *
 * Return: An array of words or NULL if the string is empty or if memory
 * allocation fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, n;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	n = count_words(str);

	words = malloc((n + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			words[j] = get_word(str + i);
			if (words[j] == NULL)
			{
				free_words(words, j);
				return (NULL);
			}
			j++;
			i += strlen(words[j - 1]);
		}
	}

	words[j] = NULL;

	return (words);
}
