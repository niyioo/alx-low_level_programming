#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp = NULL;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);

		temp = temp->next;
	}

	return (NULL);
}
