#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * word_count - Counts the number of words in a string
 *
 * @str: The string to count words in
 *
 * Return: The number of words in str
 */
int word_count(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
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
	char **words;

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	words[word_count] = NULL;

	return (words);
}

/**
 * strtow - Splits a string into words
 *
 * @str: The string to split into words
 *
 * Return: An array of strings (words)
 */
char **strtow(char *str)
{
	int word_count = 0, i = 0, k = 0, len = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (*(str + i))
	{
		if (*(str + i) != ' ')
		{
			len++;
			if (*(str + i + 1) == ' ' || *(str + i + 1) == '\0')
				word_count++;
		}
		i++;
	}

	if (word_count == 0)
		return (NULL);

	words = alloc_words(word_count);
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != ' ')
		{
			len = 0;
			while (*(str + i + len) != ' ' && *(str + i + len) != '\0')
				len++;

			*(words + k) = malloc(sizeof(char) * (len + 1));
			if (*(words + k) == NULL)
			{
				for (i = 0; i < k; i++)
					free(*(words + i));
				free(words);
				return (NULL);
			}

			for (len = 0; *(str + i) != ' ' && *(str + i) != '\0'; len++)
			{
				*(*(words + k) + len) = *(str + i);
				i++;
			}

			*(*(words + k) + len) = '\0';
			k++;
		}
		else
			i++;
	}

	return (words);
}
