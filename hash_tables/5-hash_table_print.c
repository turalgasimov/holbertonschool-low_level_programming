#include "hash_tables.h"

/**
 * hash_table_print- prints a hash table.
 * @ht: is the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int index;
	int printed;

	if (!ht)
		return;

	printed = 0;
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];
		if (!node)
			continue;

		while (node)
		{
			if (printed++)
				printf(", ");
			printf("\'%s\': \'%s\'", node->key, node->value);
			node = node->next;
		}
	}
	printf("}\n");
}
