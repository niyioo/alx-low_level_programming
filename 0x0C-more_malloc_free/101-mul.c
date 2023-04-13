#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Compute the length of a string
 * @s: The string to compute the length of
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * is_digit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * str_to_int - Convert a string to an integer
 * @s: The string to convert
 *
 * Return: The integer value of the string
 */

int str_to_int(char *s)
{
	int result = 0;

	while (*s)
	{
		if (!is_digit(*s))
		{
			exit(98);
		}
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}

/**
 * mul - Multiply two positive integers
 * @num1: The first number to multiply
 * @num2: The second number to multiply
 *
 * Return: The result of the multiplication
 */

int mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * print_number - Print an integer
 * @n: The integer to print
 */

void print_number(int n)
{
	char buffer[16];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
	}
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the command-line arguments
 *
 * Return: 0 if the program completes successfully, 98 if an error occurs
 */
int main(int argc, char **argv)
{
	int num1, num2, result;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	num1 = str_to_int(argv[1]);
	num2 = str_to_int(argv[2]);

	result = mul(num1, num2);

	print_number(result);
	_putchar('\n');

	return (0);
}
