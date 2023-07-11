#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table array.
 *
 * Return: A pointer to the created hash table, or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *new_node;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			return (update_value(node, value));
		}
		node = node->next;
	}

	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	insert_node(ht, new_node, index);
	return (1);
}

/**
 * update_value - Updates the value of an existing
 * node in the sorted hash table.
 * @node: The node to update.
 * @value: The new value.
 *
 * Return: 1 on success, 0 on failure.
 */
int update_value(shash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	free(node->value);
	node->value = new_value;
	return (1);
}

/**
 * create_new_node - Creates a new node for the sorted hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * insert_node - Inserts a new node into the sorted hash table.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert.
 * @index: The index in the hash table array.
 */
void insert_node(shash_table_t *ht, shash_node_t *new_node, unsigned long int index)
{
	shash_node_t *current, *prev;

	current = ht->array[index];
	prev = NULL;

	while (current != NULL && strcmp(current->key, new_node->key) < 0)
	{
		prev = current;
		current = current->next;
	}

	new_node->next = current;

	if (prev == NULL)
		ht->array[index] = new_node;
	else
		prev->next = new_node;

	update_sorted_linked_list(ht, new_node);
}

/**
 * update_sorted_linked_list - Updates the sorted
 * linked list of the sorted hash table.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert into the sorted linked list.
 */
void update_sorted_linked_list(shash_table_t *ht, shash_node_t *new_node)
{
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		shash_node_t *current = ht->shead;

		while (current->snext != NULL &&
				strcmp(new_node->key, current->snext->key) > 0)
			current = current->snext;

		new_node->snext = current->snext;
		new_node->sprev = current;

		if (current->snext != NULL)
			current->snext->sprev = new_node;
		else
			ht->stail = new_node;

		current->snext = new_node;
	}
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * from the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}

	free(ht->array);
	free(ht);
}
