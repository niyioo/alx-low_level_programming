#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, read_result, write_result;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	read_result = read(fd, buffer, letters);
	if (read_result == -1)
		return (0);

	write_result = write(STDOUT_FILENO, buffer, read_result);
	if (write_result != read_result)
		return (0);

	free(buffer);
	close(fd);

	return (read_result);
}
