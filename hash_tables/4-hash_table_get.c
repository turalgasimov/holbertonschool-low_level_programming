#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: is the hash table you want to look into
 * @key: is the key you are looking for
 *
 * Return: value associated with the element, 
 * or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	int index;

	index = key_index((unsigned char*)key, ht->size);
	node = ht->array[index];

	if (!node)
		return (NULL);
	
	while (node)
	{
		if (!strcmp(key, node->key))
			return node->value;
		node = node->next;
	}

	return NULL;
}
