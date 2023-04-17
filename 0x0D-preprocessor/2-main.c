#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the name of the file it was
 * compiled from followed by a new line, using the __FILE__ macro
 * The program returns 0 to indicate successful completion
 *
 * Return: 0
 */

int main(void)
{
	printf(__FILE__ "\n");
	return 0;
}
