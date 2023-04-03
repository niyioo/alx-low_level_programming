#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: A pointer to the address of the string to modify
 * @to: A pointer to the string to copy into s
 * Return: Nothing.
 */

void set_string(char **s, char *to)
{
	*s = to;
}
