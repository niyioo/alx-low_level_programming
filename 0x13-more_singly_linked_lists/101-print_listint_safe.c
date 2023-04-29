#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *tmp, *loop_start = NULL;

	tmp = head;

	while (tmp != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		tmp = tmp->next;

		if (tmp == loop_start)
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
			break;
		}

		if (count % 2 == 0 && count > 2)
			loop_start = loop_start == NULL ? (void *)head : loop_start->next;
	}

	return (count);
}
