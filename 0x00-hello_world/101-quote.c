#include <unistd.h>
#define MESSAGE "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n"

/**
 * main - Entry point
 * include the library for write() function
 * #define defined the message to be printed
 * Use the write function to print the message to standard error file descriptor
 * Return 1 to show the program has error
 * Return: Always 0(Success)
 */
int main(void)
{
	write (STDERR_FILENO, MESSAGE, sizeof (MESSAGE) -1);
	return (1);
}
