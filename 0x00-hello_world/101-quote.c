#include <unistd.h>
#define MESSAGE "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n"

/**
 * include the library for write() function
 * #define defined the message to be printed
 * main - Entry point
 *
 *
 * Use the write() function to print the message to standard error file descriptor
 * Return 1 to show the program has error Always
 */
int main(void)
{
	write(STDERR_FILENO, MESSAGE, sizeof(MESSAGE)-1);
	return(1);
}
