#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the head node of the list.
 * @str: String to be added as the value of the new node.
 *
 * Return: Address of the new node or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last_node;

	/* Create the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Otherwise, traverse the list to find the last node */
	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;

	/* Add the new node to the end of the list */
	last_node->next = new_node;

	return (new_node);
}
