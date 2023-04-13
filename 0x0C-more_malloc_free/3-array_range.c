#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers
 *
 * @min: The minimum integer to include in the array
 * @max: The maximum integer to include in the array
 *
 * Return: A pointer to the newly created array of integers
 */

int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(arr + i) = min + i;

	return (arr);
}
