#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_NUM_ARGS 3

/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the
 * arguments passed to the program
 * Description: This program takes two integer
 * arguments and computes their product.
 * Return: Always 0 (Success)
 */

int main(int argc, const char *argv[])
{
	const char *num1_input, *num2_input;
	int num1, num2, product, i;

	if (argc != EXPECTED_NUM_ARGS)
	{
		fprintf(stderr, "Usage: %s num1 num2\n", argv[0]);
		fprintf(stderr, "Error: Expected %d arguments, but got %d\n",
				EXPECTED_NUM_ARGS - 1, argc - 1);
		exit(1);
	}

	num1_input = argv[1];
	num2_input = argv[2];

	for (i = 0; num1_input[i] != '\0'; i++)
	{
		if (num1_input[i] < '0' || num1_input[i] > '9')
		{
			fprintf(stderr, "Error: Invalid character in num1: %c\n", num1_input[i]);
			exit(1);
		}
	}

	for (i = 0; num2_input[i] != '\0'; i++)
	{
		if (num2_input[i] < '0' || num2_input[i] > '9')
		{
			fprintf(stderr, "Error: Invalid character in num2: %c\n", num2_input[i]);
			exit(1);
		}
	}

	num1 = atoi(num1_input);
	num2 = atoi(num2_input);

	product = num1 * num2;

	printf("%d\n", product);

	return (0);
}
