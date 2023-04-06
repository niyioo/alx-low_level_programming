#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * followed by a new line
 *
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);

	return (0);
}
