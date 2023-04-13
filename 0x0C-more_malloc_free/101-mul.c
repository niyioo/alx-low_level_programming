#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers
 * @argc: The number of arguments passed
 * @argv: An array containing the arguments passed
 * Return: 0 if successful, 98 if the number of arguments is not 3
 * r if either of the two numbers contains non-digit characters
 */

int main(int argc, char *argv[])
{
	char *num1_str, *num2_str;
	int i, num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1_str = argv[1];
	num2_str = argv[2];

	for (i = 0; num1_str[i] != '\0'; i++)
	{
		if (num1_str[i] < '0' || num1_str[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}

	for (i = 0; num2_str[i] != '\0'; i++)
	{
		if (num2_str[i] < '0' || num2_str[i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}

	num1 = atoi(num1_str);
	num2 = atoi(num2_str);

	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
