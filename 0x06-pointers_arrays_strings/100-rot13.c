#include "main.h"

/**
 * *rot13 - function that encodes a string using rot13
 * @s: String to encode
 *
 * Return: pointer to encoded string
 */

char *rot13(char *s)
{
	int i, j;
	char s1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char s2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				s[i] = s2[j];
				break;
			}
		}
	}

	return (s);
}
