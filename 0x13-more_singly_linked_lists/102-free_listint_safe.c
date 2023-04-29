#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the first node of the list.
 *
 * Return: The number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		/* Mark the current node as visited */
		current->next = NULL;
		/* Free the current node if it hasn't been visited before */
		if (current != next)
		{
			free(current);
			count++;
		}
		/* Move on to the next node */
		current = next;
	}

	/* Set the head to NULL */
	*h = NULL;

	return (count);
}
