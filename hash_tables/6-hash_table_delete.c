#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: is the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int index;

	if (!ht)
		return;

	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];

		if (!node)
			continue;

		while (node)
		{
			ht->array[index] = node->next;
			free(node->key);
			free(node->value);
			free(node->next);
			free(node);
			node = ht->array[index];
		}
	}

	free(ht);
}
