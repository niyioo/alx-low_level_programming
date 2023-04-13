#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_error - Prints "Error" followed by a newline to standard error.
 */
void print_error(void)
{
	char *msg = "Error\n";
	int i = 0;

	while (msg[i] != '\0')
	{
		putchar(msg[i]);
		i++;
	}
}

/**
 * is_valid_num - Determines if a string represents a valid number.
 * @num: The string to check.
 *
 * Return: If the string represents a valid number - 1.
 *         Otherwise - 0.
 */
int is_valid_num(char *num)
{
	int i = 0;

	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * multiply - Multiplies two numbers represented as strings.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: A string representing the product of the two numbers.
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i = 0, j = 0, carry = 0, prod = 0;
	char *result;

	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;

	result = malloc((len1 + len2) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1] - '0';
			carry = prod / 10;
			result[i + j + 1] = (prod % 10) + '0';
		}
		result[i] += carry;
	}

	for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
		;
	if (i > 0)
		for (j = 0; j <= len1 + len2 - i; j++)
			result[j] = result[j + i];

	return (result);
}

/**
 * print_result - Prints a string to standard output.
 * @str: The string to print.
 */
void print_result(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');
}

/**
 * main - Multiplies two numbers.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if successful, 1 otherwise.
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3 || !is_valid_num(argv[1]) || !is_valid_num(argv[2]))
	{
		print_error();
		return (1);
	}

	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);
	if (result == NULL)
	{
		print_error();
		return (1);
	}

	print_result(result);
	free(result);

	return (0);
}
