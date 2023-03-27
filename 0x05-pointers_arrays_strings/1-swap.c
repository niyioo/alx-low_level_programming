#include "main.h"

/**
 * swap_int - function that swaps the values of two integeres
 * @a: Input 1
 * @b: Input 2
 *
 * Return: 0
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
