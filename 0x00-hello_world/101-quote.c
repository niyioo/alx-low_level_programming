#include <unistd.h>

/**
 *include the library for write() function
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
