#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: A pointer to the head of the list_t list.
 *
 * Return: void.
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
