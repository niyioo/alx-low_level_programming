#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * validate_input - Validates that the input is composed of digits
 * @input: The input string to be validated
 *
 * Return: 0 if the input is composed of digits, 1 otherwise
 */
int validate_input(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
			return (1);
	}

	return (0);
}

/**
 * main - Multiplies two positive numbers
 * @argc: The number of arguments passed
 * @argv: An array containing the arguments passed
 *
 * Return: 0 if successful, 98 if the number of arguments is not 3,
 * 1 if either of the two numbers contains non-digit characters
 */
int main(int argc, char *argv[])
{
	char *num1_str, *num2_str;
	long int num1, num2, result;

	/* Check for the correct number of arguments */
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	/* Validate the first argument */
	num1_str = argv[1];
	if (validate_input(num1_str))
	{
		printf("Error\n");
		return (1);
	}

	/* Validate the second argument */
	num2_str = argv[2];
	if (validate_input(num2_str))
	{
		printf("Error\n");
		return (1);
	}

	/* Convert the arguments to integers */
	num1 = strtol(num1_str, NULL, 10);
	num2 = strtol(num2_str, NULL, 10);

	/* Multiply the two numbers */
	result = num1 * num2;

	/* Print the result */
	printf("%ld\n", result);

	return (0);
}
