#include "main.h"
#include <stdlib.h>

int _putchar(char c);

/**
 * is_digit - Checks if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if @c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * str_len - Computes the length of a string
 * @str: The string to compute the length of
 *
 * Return: The length of @str
 */
int str_len(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * str_to_int - Converts a string to an integer
 * @str: The string to convert
 *
 * Return: The integer representation of @str
 *
 * If @str is not a valid integer prints an error
 * message and exits with a status of 98.
 */
int str_to_int(char *str)
{
	int num = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		if (!is_digit(str[i]))
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			exit(98);
		}

		num = num * 10 + (str[i] - '0');
	}

	return (num);
}

/**
 * print_num - Prints an integer to stdout
 * @num: The integer to print
 *
 * This function recursively prints each digit of @num.
 */
void print_num(int num)
{
	if (num / 10)
		print_num(num / 10);

	_putchar(num % 10 + '0');
}

/**
 * main - Entry point for the program
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the command-line arguments
 *
 * This program multiplies two positive integers passed as command-line
 * arguments and prints the result to stdout. If the number of arguments is
 * incorrect or either argument is not a positive integer, prints an error
 * message and exits with a status of 98.
 *
 * Return: 0 on success, 98 on failure
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
		exit(98);
	}

	num1 = str_to_int(argv[1]);
	num2 = str_to_int(argv[2]);

	result = num1 * num2;

	print_num(result);
	_putchar('\n');

	return (0);
}
