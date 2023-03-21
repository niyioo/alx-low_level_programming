#include "main.h"
#include <unistd.h>

/**
 * main - Prints _purchar followed by a new line
 *
 * Return: 0
 */

int main(void)
{
	char message[] = "_putchar\n";

	int i = 0;

	while (message[i] != '\0')
	{
		_putchar(message[i]);
		i++;
	}

	return (0);
}
