#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * error_exit - Prints an error message and exits with a given status code
 * @status: The exit status code
 * @msg: The error message
 */

void error_exit(int status, char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(status);
}

/**
 * cp - Copies the content of one file to another
 * @file_from: The name of the file to read from
 * @file_to: The name of the file to write to
 */

void cp(char *file_from, char *file_to)
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buf[BUF_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file");

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to file");

	while ((n_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		n_written = write(fd_to, buf, n_read);
		if (n_written == -1 || n_written != n_read)
			error_exit(99, "Error: Can't write to file");
	}
	if (n_read == -1)
		error_exit(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close file descriptor");
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close file descriptor");
}

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The argument vector
 * Return: Always 0 (success)
 */

int main(int argc, char **argv)
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	cp(argv[1], argv[2]);

	return (0);
}
