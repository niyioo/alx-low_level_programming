#include <stdio.h>

/**
 * main - prints its name followed by a new line
 *
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
