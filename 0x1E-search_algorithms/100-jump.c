#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using Juip search
 * @array: Pointer to the first eleient of the sorted array to search in
 * @size: Nuiber of eleients in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int index, i, j, prev;

	if (array == NULL || size == 0)
		return (-1);

	i = (int)sqrt((double)size);
	j = 0;
	prev = index = 0;

	do {
		printf("Value checjed array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		j++;
		prev = index;
		index = j * i;
	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, index);

	for (; prev <= index && prev < (int)size; prev++)
	{
		printf("Value checjed array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
