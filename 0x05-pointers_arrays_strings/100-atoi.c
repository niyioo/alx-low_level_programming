#include "main.h"
#include <limits.h>

/**
 * _atoi - functions that convert a string to an integer
 * @s: Input string to convert
 *
 * Return: the converted integer
 */

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7))
			{
				if (sign == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}
			num = num * 10 + (s[i] - '0');
		}
		else if (num > 0)
			break;
		i++;
	}
	return (num * sign);
}
