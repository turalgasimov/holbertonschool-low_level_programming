#include "hash_tables.h"

/**
 * hash_table_create - entry
 * @size: size
 * Return: hash_table_t
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = (hash_table_t *)malloc(sizeof(hash_table_t));

	if (ht == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	ht->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);

	return (ht);
}
