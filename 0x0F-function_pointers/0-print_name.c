#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - Prints a name using a function pointer
 * @name: Pointer to the name string
 * @f: Pointer to a function that prints a string
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
