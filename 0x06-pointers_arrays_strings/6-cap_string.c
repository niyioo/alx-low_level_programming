#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: Input string
 *
 * Return: Pointer to the resulting string
 */

char *cap_string(char *s)
{
	int i = 0, cap_next = 1, cap_first = 1;

	while (s[i])
	{
		if (cap_next && s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
			cap_next = 0;
		}
		if (cap_first && s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
			cap_first = 0;
		}
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
				s[i] == ',' || s[i] == ';' || s[i] == '.' ||
				s[i] == '!' || s[i] == '?' || s[i] == '"' ||
				s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
			cap_next = 1;
		i++;
	}

	return (s);
}
