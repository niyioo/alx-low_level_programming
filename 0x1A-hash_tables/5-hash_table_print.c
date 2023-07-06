#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int count = 0;
	bool first = true;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);
			count++;
			first = false;

			node = node->next;
		}
	}

	printf("}\n");
}
