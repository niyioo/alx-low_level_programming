#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string to get the length of
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * mul - multiplies two positive numbers
 * @num1: the first number
 * @num2: the second number
 *
 * Return: the result of num1 times num2
 */
char *mul(char *num1, char *num2)
{
	char *result;
	int len1, len2, i, j, k, carry, n1, n2, sum;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	result[i] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1, k = i + j + 1; j >= 0; j--, k--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + carry + (result[k] - '0');
			carry = sum / 10;
			result[k] = (sum % 10) + '0';
		}

		result[k] += carry;
	}

	while (*result == '0' && *(result + 1))
		result++;

	return (result);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i]; i++)
	{
		if (!_isdigit(num1[i]))
		{
			printf("Error\n");
			return (98);
		}
	}

	for (j = 0; num2[j]; j++)
	{
		if (!_isdigit(num2[j]))
		{
			printf("Error\n");
			return (98);
		}
	}

	result = mul(num1, num2);
	printf("%s\n", result);
	free(result);

	return (0);
}
