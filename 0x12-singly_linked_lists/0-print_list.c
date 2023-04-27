#include "lists.h"

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		size_t str_len = h->str ? strlen(h->str) : 0;

		printf("[%lu] %s\n", str_len, h->str ? h->str : "(nil)");
		node_count++;
		h = h->next;
	}

	return (node_count);
}
