#include "main.h"

/**
 * get_endianness - checks the endianness of the machine
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int num = 1;
	char *c = (char *) &num;
	return ((int) *c);
}
