#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the sorted array to search in
 * @left: The left boundary of the search range
 * @right: The right boundary of the search range
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int binary_search_(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i == right)
				printf("%d", array[i]);
			else
				printf("%d, ", array[i]);
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Search for a value in a
 * sorted array using Exponential search
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	i = 1;
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}

	left = i / 2;
	right = (i < size - 1) ? i : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	return (binary_search_(array, left, right, value));
}

