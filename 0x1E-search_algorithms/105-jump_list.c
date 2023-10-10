#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Search for a value in a sorted singly
 * linked list using Jump search
 * @list: Pointer to the head of the linked list
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: A pointer to the first node where the value
 * is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, i, j;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	j = (size_t)sqrt((double)size);
	index = 0;
	i = 0;

	do {
		prev = list;
		i++;
		index = i * j;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
