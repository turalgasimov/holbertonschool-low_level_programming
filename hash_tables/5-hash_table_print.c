#include "hash_tables.h"

/**
 * hash_table_print- prints a hash table.
 * @ht: is the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int index;

	if (!ht)
		return;

	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];
		while (node)
		{
			printf("\'%s\': \'%s\', ", node->key, node->value);
			node = node->next;
		}
	}
}
