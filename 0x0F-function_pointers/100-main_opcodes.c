#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 if successful, 1 if wrong number of arguments
 * 2 if negative number of bytes
 */

int main(int argc, char *argv[])
{
	char *opcodes;
	int nbytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	nbytes = atoi(argv[1]);

	if (nbytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	opcodes = (char *)main;

	for (i = 0; i < nbytes; i++)
	{
		printf("%02hhx", opcodes[i]);

		if (i < nbytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
