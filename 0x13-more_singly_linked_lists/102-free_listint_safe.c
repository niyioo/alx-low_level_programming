#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	current = *h;
	while (current != NULL)
	{
		count++;
		temp = current->next;
		free(current);
		if (temp >= current)
			break;
		current = temp;
	}
	*h = NULL;
	return (count);
}
