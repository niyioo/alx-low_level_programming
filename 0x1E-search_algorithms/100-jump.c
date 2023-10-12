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
	size_t i, j, jump;

	if (array == NULL || size == 0)
		return (-1);

	j = sqrt(size);

	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array [%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += j;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump > size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array [%ld] = [%d]\n", i, array[i]);
	printf("Value checked array [%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
