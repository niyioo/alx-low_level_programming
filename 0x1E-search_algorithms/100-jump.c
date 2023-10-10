#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using Jump search
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, step, j;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	for (i = j = 0; j < size && array[j] < value;)
	{
		printf("Value checked array [%ld] = [%d]\n", j, array[j]);
		i = j;
		j += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, j);

	j = j > size - 1 ? j : size - 1;
	for (; i < j && array[i] < value; i++)
		printf("Value checked array [%ld] = [%d]\n", i, array[i]);
	printf("Value checked array [%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
