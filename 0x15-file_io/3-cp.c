#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * Copies the content of file_from to file_to.
 *
 * @param file_from the name of the file to read from.
 * @param file_to   the name of the file to write to.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t n_read;
	char buf[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1) {
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	while ((n_read = read(fd_from, buf, BUFFER_SIZE)) > 0) {
		if (write(fd_to, buf, n_read) != n_read) {
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (n_read == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	if (close(fd_from) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return 97;
	}

	copy_file(argv[1], argv[2]);

	return 0;
}
