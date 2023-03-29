#include "main.h"

/**
 * leet - Encodes a string into 1337 (leet) speak
 * @s: Input string
 *
 * Return: Pointer to the resulting string
 */
char *leet(char *s)
{
	int i, j;
	char leet[] = {'4', '3', '0', '7', '1'};
	char chars[] = {'a', 'e', 'o', 't', 'l'};

	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == chars[j] || s[i] == chars[j] - 32)
				s[i] = leet[j];
		}
	}

	return (s);
}
