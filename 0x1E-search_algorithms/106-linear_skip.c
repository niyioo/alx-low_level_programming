#include "search_algos.h"

/**
 * linear_skip - Search for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: A pointer to the first node where the value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *prev;

	if (!list)
		return (NULL);

	while (current->express)
	{
		prev = current;
		current = current->express;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n >= value)
			break;
	}

	if (current->n >= value)
	{
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
		current = prev;
	}
	else
	{
		while (current->next)
			current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
	}

	while (prev)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (prev->n > value)
			break;
		prev = prev->next;
	}

	return (NULL);
}

